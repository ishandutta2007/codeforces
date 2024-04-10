#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#define int long long

using namespace std;

string intToStr(int i)
{
    char s[50];
    sprintf(s, "%d", i);
    return string(s);
}

inline int calc(string s)
{
    int lastNum = 0, curMul = 1, curSum = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
        if ('0' <= s[i] && s[i] <= '9') lastNum = lastNum * 10 + s[i] - '0';
            else if (s[i] == '*') curMul *= lastNum, lastNum = 0;
                else if (s[i] == '+') curMul *= lastNum, curSum += curMul, curMul = 1, lastNum = 0;
    curMul *= lastNum, curSum += curMul;
    return curSum;
}

signed main()
{
    string s; cin >> s;
    int n = s.length();

    int ans = calc(s);

    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            ans = max(ans, calc( intToStr(calc(s.substr(0, i))) + s.substr(i, n - i) )),
            ans = max(ans, calc( s.substr(0, i + 1) + intToStr(calc(s.substr(i + 1, n - i - 1))) ));

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i] == '*' && s[j] == '*')
                ans = max(ans, calc( s.substr(0, i + 1) + intToStr(calc(s.substr(i + 1, j - i - 1))) + s.substr(j, n - j) ));

    cout << ans;
}