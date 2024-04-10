#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s;
ll m , r , res = 1e9 , t = 1;
int main()
{
    cin >> s >> m;
    s += s;
    if(m == 2)
    {
        for(int i = s.size() / 2 - 1; i < s.size(); i++)
        {
            if((s[i] - '0') % 2 == 0 && s[i - s.size() / 2 + 1] != '0')
            {
                cout << "0";
                return 0;
            }
        }
        cout << "1";
        return 0;
    }
    if(m == 5)
    {
        for(int i = s.size() / 2 - 1; i < s.size(); i++)
        {
            if(s[i - s.size() / 2 + 1] != '0')
                res = min((int)res , s[i] - '0');
        }
        cout << res;
        return 0;
    }
    for(int i = 0; i < s.size() / 2; i++)
    {
        r = (r * 10) + (s[i] - '0');
        r %= m;
        if(i + 1 != s.size() / 2)
        {
            t *= 10;
            t %= m;
        }
    }
    res = r;
    for(int i = s.size() / 2; i < s.size(); i++)
    {
        r -= (s[i - s.size() / 2] - '0') * t;
        r *= 10;
        r += s[i] - '0';
        r %= m;
        if(r < 0)
            r += m;
        if(s[i - s.size() / 2 + 1] != '0')
            res = min(res , r);
    }
    cout << res;
}