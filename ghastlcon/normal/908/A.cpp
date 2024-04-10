#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string s;
    int i, o;

    cin >> s;
    for(i = o = 0;i < (signed)s.size();i ++)
        o += s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9';
    cout << o << endl;

    return 0;
}