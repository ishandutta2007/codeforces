#include <iostream>

using namespace std;

int main()
{
    int sm=0,b=0;
    string s;
    cin>>s;
    for (int i = 0; i< s.length();++i)
        if (s[i]>='a'&&s[i]<='z')++sm;
        else ++b;
    if (b>sm) {
        for (int i = 0; i < s.length();++i)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] += 'A'-'a';
        }
    } else {
        for (int i = 0; i < s.length();++i)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a'-'A';
        }
    }
    cout << s;
    return 0;
}