#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll m;
ll ans;

bool f(ll x)
{
        if((- m - m + n + n + x - 1) / x > x + 1)
        {
                return 1;
        }
        return 0;
}

void solve()
{
        cin >> n >> m;
        m = min(m, n - 1);
        ans = m;
        ll l = 1;
        ll r = 2e18;
        while(l < r)
        {
                ll tm = (l + r) / 2;
                if(f(tm))
                {
                        l = tm + 1;
                }
                else
                {
                        r = tm;
                }
        }
        cout << ans + l << endl;
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