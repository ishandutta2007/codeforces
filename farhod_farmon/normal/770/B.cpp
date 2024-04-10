#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

string s;

ll sum(ll x)
{
        ll cnt = 0;
        while(x)
        {
                cnt += x % 10;
                x /= 10;
        }
        return cnt;
}

ll f(ll h)
{
        ll x = 0;
        for(int i = 0; i < h; i++)
        {
                x = x * 10 + s[i] - '0';
        }
        if(h < s.size())
        {
                x = x * 10 + s[h] - '1';
        }
        for(int i = h + 1; i < s.size(); i++)
        {
                x = x * 10 + 9;
        }
        return x;
}

void solve()
{
        cin >> s;
        ll ans = f(s.size());
        for(int i = 0; i < s.size(); i++)
        {
                if(s[i] == '0')
                {
                        continue;
                }
                ll x = f(i);
                if(sum(x) > sum(ans) || sum(x) == sum(ans) && x > ans)
                {
                        ans = x;
                }
        }
        cout << ans << endl;
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}