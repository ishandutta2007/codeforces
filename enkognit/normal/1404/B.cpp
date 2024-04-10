#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, kl[100001], dp[100001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

vector<ll> c[100001];
ll a, b, da, db, T=0, TT;

void dfs1(int h,int k,int p=-1)
{
    if (h==b)
    {
        T=1;
        return;
    }
    if (k==da) return;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs1(c[h][i],k+1,h);
        }
}

void dfs(int h,int p=-1)
{
    kl[h]=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            kl[h]=max(kl[h], kl[c[h][i]]+1);
        }
}

void dfs2(int h,ll mx,int p=-1)
{
    pll o=mp(0, 0);
    TT=max(kl[h]+mx, TT);
    dp[h]=kl[h]+mx;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            if (o.fi<kl[c[h][i]]+1) swap(o.fi, o.se), o.fi=kl[c[h][i]]+1; else
            if (o.se<kl[c[h][i]]+1) o.se=kl[c[h][i]]+1;
        }
    //cout << h << " " << mx << " " << o.fi << " " << o.se << "\n";
    TT=max(TT, o.fi+o.se);
    dp[h]=max(dp[h], o.fi+o.se);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            ll pp=o.fi;
            if (kl[c[h][i]]==pp-1) pp=o.se;
            dfs2(c[h][i], max(pp,mx)+1, h);
        }
}

ll K=0, Z=0;

void solve()
{
    T=0;TT=0;
    cin >> n >> a >> b >> da >> db;
    for (int i = 1; i <= n; i++) c[i].clear();
    vector<pll> v;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
        v.pb(mp(x, y));
    }
    dfs1(a, 0);
    if (T || da*2+1>db)
    {
        cout << "Alice\n";
        return;
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    //cout << TT << "\n";
    if (TT<=da*2) cout << "Alice\n"; else cout << "Bob\n";
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
    cin >> t;
   // if (t>100) Z++;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/