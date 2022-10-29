#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, o, T, Z, ZZ, f[10001], a[200001], kl[200001], pr[200005];
bool tt[1000001];
vector<ll> c[200001];

ll binpow(ll h,ll r,ll md=MOD)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void dfs0(int h,int p=-1)
{
    pr[h]=p;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=pr[h])
        {
            dfs0(c[h][i], h);
        }
}

void dfs(int h)
{
    kl[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=pr[h] && !tt[c[h][i]])
        {
            dfs(c[h][i]);
            kl[h]+=kl[c[h][i]];
        }
    if (kl[h]==f[T-1])
    {
        Z=h;
    }
    if (kl[h]==f[T-2])
    {
        ZZ=h;
    }
}

bool rec(int h,int k)
{
    tt[h]=1;
    if (k<3) return 1;
    T=k;
    Z=0;
    ZZ=0;
    dfs(h);
    ll z=Z, zz=ZZ;
    bool t=0;
    if (z)
    {
        tt[z]=1;
        tt[h]=1;
        t=(rec(z, k-1) & rec(h, k-2));
    }else
    if (zz)
    {
        tt[zz]=1;
        tt[h]=1;
        t=(rec(zz, k-2) & rec(h, k-1));
    }
    return t;
}

void solve()
{
    cin >> n;
    f[0]=1;
    f[1]=1;
    ll l=1;
    while (f[l]<n) l++, f[l]=f[l-1]+f[l-2];
    if (f[l]!=n)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs0(1);
    tt[1]=1;
    cout << (rec(1, l)?"YES\n":"NO\n");
}

int main()
{
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
/*
10 10
1 3
3 5
5 7
7 9
2 9
1 4
4 6
6 8
8 10
2 10
*/