#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, dp1[200001], dp2[200001];
vector<ll> c[200001], g[200001];
bool tt[200001], tl[200001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

void dfs(int h)
{
    tt[h]=1;
    tl[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) dfs(c[h][i]); else
        if (tl[c[h][i]]) {cout << "-1\n";exit(0);}
    tl[h]=0;
}

void dfs1(int h)
{
    tt[h]=1;
    dp1[h]=h;
    for (int i = 0; i < c[h].size(); i++)
    {
        if (!tt[c[h][i]]) dfs1(c[h][i]);
        dp1[h]=min(dp1[h],dp1[c[h][i]]);
    }
}

void dfs2(int h)
{
    tt[h]=1;
    dp2[h]=h;
    for (int i = 0; i < g[h].size(); i++)
    {
        if (!tt[g[h][i]]) dfs2(g[h][i]);
        dp2[h]=min(dp2[h],dp2[g[h][i]]);
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        g[y].pb(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!tt[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) tt[i]=0, dp1[i]=1e18, dp2[i]=1e18;

    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs1(i);
        }

    for (int i = 1; i <= n; i++) tt[i]=0;

    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs2(i);
        }
    string d="";
    ll ans=0;
    for (int i = 1; i <= n; i++)
        if (dp1[i]==i && dp2[i]==i) ans++, d+='A'; else d+='E';
    cout << ans << "\n";
    cout << d << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
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