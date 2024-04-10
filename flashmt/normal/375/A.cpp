#include <bits/stdc++.h>
using namespace std;

int p10[1000100], n, d[256];
string s, digits = "1689";

int main()
{
    ios::sync_with_stdio(0);
    
    p10[0] = 1;
    for (int i = 1; i <= 1000000; i++) p10[i] = p10[i - 1] * 10 % 7;
    
    d['1'] = d['6'] = d['8'] = d['9'] = 1;
    
    cin >> s;
    n = s.size();
    
    for (int i = 0; i < 4; i++)
        for (int j = i; j < n; j++)
            if (s[j] == digits[i])
            {
                swap(s[j], s[i]);
                break;
            }
            
    int rem = 0;
    for (int i = 4; i < n; i++) rem = (rem + (s[i] - '0') * p10[n - 1 - i]) % 7;
    
    do
    {
        int curRem = 0;
        for (int i = 0; i < 4; i++) curRem = (curRem * 10 + digits[i] - '0') % 7;
        if ((curRem * p10[n - 4] + rem) % 7 == 0) 
        {
            for (int i = 0; i < 4; i++) s[i] = digits[i];
            cout << s << endl;
            return 0;
        }
    } while (next_permutation(digits.begin(), digits.end()));
    
    cout << "0\n";
}