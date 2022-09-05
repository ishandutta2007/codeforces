#include <bits/stdc++.h>
using namespace std;
int n; 
string s, t; 
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        int cnt = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if('A' <= s[j] && s[j] <= 'Z')
            {
                cnt++;
            }
        }
        if(cnt == 2 && s.size() > 3 && 'A' <= s[0] && s[0] <= 'Z' && '0' <= s[1] && s[1] <= '9')
        {
            int rn = 0, cn = 0, j = 1;
            for(; j < s.size(); j++)
            {
                if('A' < s[j] && s[j] < 'Z')
                {
                     j++;
                     break;
                }
                rn = rn * 10 + (s[j] - '0');
            }
            for(; j < s.size(); j++)
            {
                if('A' < s[j] && s[j] < 'Z')
                {
                     break;
                }
                cn = cn * 10 + (s[j] - '0');
            }
            cn--;
            int pow = 26, sz = 1;
            while(cn - pow > 0)
            {
                cn -= pow;
                pow *= 26;
                sz++;
            }
            t = "";
            for(int i = 1; i <= sz; i++)
            {
                t = char('A' + (cn % 26)) + t;
                cn /= 26;
            }
            cout << t << rn << endl;
        }
        else
        {
            int cn = 0, rn = 0, len = 0, j;
            for(j = 0; j < s.size(); j++)
            {
                if('0' <= s[j] && s[j] <= '9')break;
                len++;
            }
            for(; j < s.size(); j++)
            {
                rn = rn * 10 + (s[j] - '0');
            }
            int pow = 1;
            for(j = 0; j < len; j++)
            {
                cn = cn * 26 + (s[j] - 'A');
            }
            pow = 1;
            for(j = 1; j < len; j++)
            {
                pow *= 26;
                cn += pow;
            }
            cn++;
            cout << "R" << rn << "C" << cn << endl;
        }
    }
}