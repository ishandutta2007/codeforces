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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll a[100001], n, T, m, bn[100001][20], kl[100001], in[100001], out[100001], hh[100001], mn[100001];
bool tt[100001];
vector<ll> c[100001], v[100001];

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
    //cout << l << "\n";
    return l;
}

ll inverse(ll h)
{
    return binpow(h, md-2, md);
}

void dfs1(int h,int p=-1)
{
    kl[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p && !tt[c[h][i]])
        {
            dfs1(c[h][i], h);
            kl[h]+=kl[c[h][i]];
        }
}

ll get_centroid(int h,int k,int p)
{
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p && !tt[c[h][i]])
        {
            if (kl[c[h][i]]*2>=k)
            {
                return get_centroid(c[h][i], k, h);
            }
        }
    return h;
}

void dfs2(int h,int k,int p=-1)
{
    v[h].pb(k);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p && !tt[c[h][i]])
        {
            dfs2(c[h][i], k, h);
        }
}

void rec(int h)
{
    dfs1(h);
    //cout << h << "\n";
    //cout << "-\n";
    h=get_centroid(h,kl[h],0);
    //cout << "-\n";
    dfs2(h, h);
    //cout << "-\n";
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) rec(c[h][i]);
}


void dfs(int h,int p=0)
{
    hh[h]=hh[p]+1;
    in[h]=++T;
    bn[h][0]=p;
    for (int i = 1; i < 19; i++) bn[h][i]=bn[bn[h][i-1]][i-1];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
        }
    out[h]=++T;
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll lca(int x,int y)
{
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    for (int i = 18; i > -1; i--)
        if (!is_ancestor(bn[x][i], y)) x=bn[x][i];
    return bn[x][0];
}

ll get_dist(int x,int y)
{
    return hh[x]+hh[y]-2*hh[lca(x,y)];
}

void upd(int h)
{
    for (int i = 0; i < v[h].size(); i++)
        mn[v[h][i]]=min(mn[v[h][i]], get_dist(h, v[h][i]));
}

ll get(int h)
{
    ll ans=1e9;
    for (int i = 0; i < v[h].size(); i++)
        ans=min(ans, mn[v[h][i]]+get_dist(v[h][i], h));
    return ans;
}

void solve()
{
    cin >> n >> m;
    out[0]=1e9;
    for (int i = 1; i <= n; i++) mn[i]=1e9;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    //cout << "----\n";
    rec(1);
    //cout << "----\n";
    upd(1);
    //cout << "----\n";
    for (int i = 0; i < m; i++)
    {
        ll t, x;
        cin >> t >> x;
        if (t==1) upd(x); else cout << get(x) << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
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
1

3

0 1 1

1 3

3 2


*/