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

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T, kl[400001], a[400001], in[400001], out[400001];
vector<pll> c[400001];


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
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

pll bn[400001][20];

void dfs(int h,int p=0,int k=0)
{
    in[h]=++T;
    bn[h][0]=mp(p, k);
    for (int i = 1; i < 20; i++)
        bn[h][i]=mp(bn[bn[h][i-1].fi][i-1].fi, max(bn[h][i-1].se, bn[bn[h][i-1].fi][i-1].se));
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].fi!=p)
        {
            dfs(c[h][i].fi,h,c[h][i].se);
        }
    out[h]=++T;
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll get_lca(int x,int y)
{
    ll mx=0;
    for (int i = 19; i > -1; i--)
        if (!is_ancestor(bn[x][i].fi,y)) mx=max(mx,bn[x][i].se), x=bn[x][i].fi;
    mx=max(mx, bn[x][0].se);
    for (int i = 19; i > -1; i--)
        if (!is_ancestor(bn[y][i].fi,x)) mx=max(mx, bn[y][i].se), y=bn[y][i].fi;
    mx=max(mx, bn[y][0].se);
    return mx;
}

void solve()
{
    cin >> n >> m;
    in[0]=-1;out[0]=1e9;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        c[x+n].pb(mp(i, 0));
        kl[i]++;
    }
    for (int i = 1; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        kl[y+n]++;
        c[x+n].pb(mp(y+n, i));
    }
    ll p=0;
    for (int i = n+1; i <= n+m; i++)
        if (kl[i]==0) {p=i;break;}
    dfs(p);
    for (int i = 1; i < n; i++)
    {
        //cout << i << " " << i+1 << " " << get_lca(i,i+1) << "\n";
        a[get_lca(i,i+1)]--;
    }
    ll ans=n-1;
    for (int i = 0; i < m; i++)
    {
        ans+=a[i];
        cout << ans << "\n";
    }
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

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/