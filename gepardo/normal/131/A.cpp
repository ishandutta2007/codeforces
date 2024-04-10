// 

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    bool y = true;
    for (int i = 1; i < n; i++)
        if ('a' <= s[i] && s[i] <= 'z') y = false;
    if (y) for (int i = 0; i < n; i++) s[i] = s[i] ^ ' ';
    cout << s;
}