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

ll n, m, k, T, a[1001][501], kol[501][501];
bool tt[1001];
vector<ll> c[501][501];

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

void remove(int h)
{
    for (int i = 1; i <= n; i++)
        kol[i][a[h][i]]--;
}

vector<ll> an;

void add(int h)
{
    if (tt[h]) return;
    tt[h]=1;
    an.pb(h);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < c[i][a[h][i]].size(); j++)
            if (!tt[c[i][a[h][i]][j]])
            {
                tt[c[i][a[h][i]][j]]=1;
                remove(c[i][a[h][i]][j]);
            }
    }
}

void solve()
{
    cin >> n;
    an.clear();
    for (int i = 1; i <= n*2; i++)
    {
        tt[i]=0;
        if (i<=n)
        for (int j = 1; j <= n; j++)
            c[i][j].clear(), kol[i][j]=0;
    }
    for (int i = 1; i <= n*2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            kol[j][a[i][j]]++;
            c[j][a[i][j]].pb(i);
        }
    }

    ll ans=1;

    for (int it = 1; it <= n; it++)
    {
        ll mn=1e18, u=0;
        for (int i = 1; i <= n*2; i++)
            if (!tt[i])
            {
                for (int j = 1; j <= n; j++)
                    if (kol[j][a[i][j]]<mn)
                    {
                        mn=kol[j][a[i][j]];
                        u=i;
                    }
            }
        assert(mn<3);
        if (mn==2) ans=ans*2%MOD;
        add(u);
    }
    cout << ans << "\n";
    for (int i = 0; i < an.size(); i++)
    {
        cout << an[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}