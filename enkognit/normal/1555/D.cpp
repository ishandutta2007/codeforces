#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=998244353;
const ld E=1e-10;

ll n, m, k, T, pr[10][4][200001];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

void solve()
{
    cin >> n >> m;
    string s;
    cin >> s;
    vector<string> v={"abc", "acb", "bac", "bca", "cab", "cba"};
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
        {
            //cout << i << " " << j << "\n";
            for (int u = 0; u < n; u++)
            {
                //cout << " " << u << " " << s[u] << "\n";
                pr[i][j][u]=(u>0?pr[i][j][u-1]:0)+(s[u]!=v[i][(u%3+j)%3]);
            }
        }
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll ans=1e18;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                ans=min(ans, pr[i][j][r]-(l>0?pr[i][j][l-1]:0));
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}