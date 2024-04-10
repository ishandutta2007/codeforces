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

ll n, m, k, T, nw[100001], a[100001];
pll ans[100001];

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

bool tt[1001];
vector<ll> c[1001];
vector<ll> v[1001];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0;

    for (int i = 1; i <= n*k; i++)
    {
        cin >> a[i];
        c[a[i]].pb(i);
    }

    vector<ll> z;
    for (int i = 1; i <= n; i++)
    {
        z.pb(i);
    }
    while (1)
    {
        ll y=0;
        for (int i = 1; i <= n; i++)
            if (!tt[i])
                nw[i]=0, y=1;
        if (!y) break;
        ll p=0;
        //cout << "---\n";
        while (1)
        {
            ll mn=1e18, pp=0, u=0;
            for (int i = 1; i <= n; i++)
                if (!tt[i])
                {
                    while (nw[i]<c[i].size()-1 && c[i][nw[i]]<=p) nw[i]++;
                    if (nw[i]<c[i].size()-1 && c[i][nw[i]+1]<mn) mn=c[i][nw[i]+1], u=c[i][nw[i]], pp=i;
                }
            if (pp==0) break;
            tt[pp]=1;
            ans[pp]=mp(u, mn);
            p=mn;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}