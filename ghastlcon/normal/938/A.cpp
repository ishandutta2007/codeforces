#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize("O3")
using namespace std;

bool vowel(char c)
{
    return c =='a'||c=='e'||c =='i'||c=='o'||c=='u'||c=='y';
}

signed main()
{
    int n;
    string s;
    int i;
    char t;

    cin >> n >> s;
    for(i = 0;i < n;i ++)
        if(!i || !vowel(s[i]) || (vowel(s[i]) && !vowel(t)))
        {
            putchar(s[i]);
            t = s[i];
        }

    return 0;
}