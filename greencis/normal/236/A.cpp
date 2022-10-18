#include <iostream>
using namespace std;

int freq[256];

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length();++i)
        ++freq[s[i]];

    int r = 0;
    for (int i = 0; i < 256; ++i) {
        if (freq[i])
            ++r;
    }
    if (r%2==0)
        cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
    return 0;
}