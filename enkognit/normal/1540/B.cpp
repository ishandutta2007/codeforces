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

ll MOD=1e9+7;
const ld E=1e-10;

ll n, m, k, T, a[1001], hh[1001], bn[1001][10], in[1001], out[1001], ff[1001][1001];
vector<ll> c[1001];

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


void dfs(int h,int p=-1)
{
    hh[h]=hh[p]+1;

    bn[h][0]=p;
    for (int i = 1; i < 10; i++)
        bn[h][i]=bn[bn[h][i-1]][i-1];

    in[h]=++T;

    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
        }

    out[h]=++T;
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[y]<=out[x];
}

ll lca(int x,int y)
{
    if (is_ancestor(x, y)) return x;
    if (is_ancestor(y, x)) return y;
    for (int i = 9; i > -1; i--)
        if (!is_ancestor(bn[x][i], y))
            x=bn[x][i];
    return bn[x][0];
}

void solve()
{
    cin >> n;
    out[0]=1e9;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }

    for (int i = 1; i <= n; i++)
        ff[0][i]=1;

    ll zzz=binpow(2,MOD-2,MOD);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ff[i][j]=((ff[i][j-1]+ff[i-1][j])*zzz)%MOD;

    ll ans=0;

    for (int it = 1; it <= n; it++)
    {
        T=0;
        dfs(it, 0);
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                if (i!=j)
                {
                    ll o=lca(i, j);
                    ans=(ans+ff[(hh[j]-hh[o])][(hh[i]-hh[o])])%MOD;
                }
    }

    cout << ans*binpow(n,MOD-2,MOD)%MOD << "\n";
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