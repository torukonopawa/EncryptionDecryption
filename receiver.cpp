#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    std::string KEY;
    double KEYvalue = 0;
    std::string inputMessage;
    std::string decryptedMessage;
    std::string toClipboard;

    //IO with user
    std::cout << "Hello Boss, enter message" << std::endl;
    std::getline(std::cin, inputMessage);
    std::cout << "ENTER YOUR KEY" << std::endl;
    std::getline(std::cin, KEY);

    //Real Key Value
    for(int i=0; i < KEY.length() ;i++)
    {
        KEYvalue += KEY[i];
    }

    //DECRYPTION Message
    for(int i=0; i < inputMessage.length() ;i++)
    {
        if(inputMessage[i] == 32)
        {
            decryptedMessage.push_back(' ');
            continue;
        }

        char nextLetter = inputMessage[i] - KEYvalue;

        decryptedMessage.push_back(nextLetter);
    }

    //CONFIGURE user Clipboard
    toClipboard.append("Message = <");
    toClipboard.append(decryptedMessage);
    toClipboard.push_back('>');

    //SET CLIPBOARD
    const char* output = toClipboard.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    //END
    std::cout << "Decrypted MSG : " << decryptedMessage << std::endl;

    system("PAUSE");
    return 0;
}