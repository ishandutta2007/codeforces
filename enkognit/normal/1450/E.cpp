#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z, cl[1001], a[1001], d[1001][1001], an[1001];
vector<pll> c[1001];
bool tt[1001], tl[1001];
vector<pair<pll,ll> > v, vv;

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

void dfs1(int h)
{
    for (int i = 0; i < c[h].size(); i++)
        if (cl[c[h][i].fi]==0)
        {
            cl[c[h][i].fi]=(cl[h])%2+1;
            dfs1(c[h][i].fi);
        }else
        if (cl[c[h][i].fi]==cl[h]) T=1;
}

void dfs(int h)
{
    tt[h]=1;
    tl[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].se==-1)
        {
            if (tt[c[h][i].fi]==1)
            {
                if (tl[c[h][i].fi])
                {
                    T=1;
                }
            }else dfs(c[h][i].fi);
        }
    tl[h]=0;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        vv.pb(mp(mp(x, y), h));
        if (h==1)
        {
            c[x].pb(mp(y, 1));
            c[y].pb(mp(x, -1));
            v.pb(mp(mp(x, y), 1));
            v.pb(mp(mp(y, x), -1));
        }else
        {
            c[x].pb(mp(y, 1));
            c[y].pb(mp(x, 1));
            v.pb(mp(mp(x, y), 1));
            v.pb(mp(mp(y, x), 1));
        }
    }
    cl[1]=1;
    dfs1(1);
    if (T)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            Z++;
            dfs(i);
        }
    if (T)
    {
        cout << "nO\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i][j]=(i==j?0:1e18);
    for (int i = 0; i < v.size(); i++)
        d[v[i].fi.fi][v[i].fi.se]=v[i].se;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int u = 1; u <= n; u++)
                if (d[j][i]<1e18 && d[i][u]<1e18)
                d[j][u]=min(d[j][i]+d[i][u], d[j][u]);
    ll ans=-1;
    for (int i = 1; i <= n; i++)
    {
        bool t=0;
        for (int j = 0; j < vv.size(); j++)
        {
            if (vv[j].se==1)
            {
                if (d[i][vv[j].fi.fi]+1!=d[i][vv[j].fi.se]) t=1;
            }else
            {
                if (abs(d[i][vv[j].fi.fi]-d[i][vv[j].fi.se])!=1) t=1;
            }
        }
        if (!t)
        {
            ll mn=1e18, mx=0;
            for (int j = 1; j <= n; j++) mx=max(mx, d[i][j]), mn=min(mn, d[i][j]);
            if (ans<mx-mn)
            {
                ans=mx-mn;
                for (int j = 1; j <= n; j++) an[j]=d[i][j]+n;
            }
        }
    }
    if (ans==-1)cout << "No\n"; else
    {
        cout << "YES\n";
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) cout << an[i] << " ";
        cout << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    ios::sync_with_stdio(0);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/