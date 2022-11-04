#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;
ll t, res;
int main()
{
    string s;
    cin >> s;
    for(int i = s.size() - 1; i > -1; i--)
    {
        if(s[i] != 'a')
        {
            t++;
            continue;
        }
        res += t;
        t *= 2;
        t %= mod;
        res %= mod;
    }
    cout << res;
    //fuck
}
// abbbbbbbbbba