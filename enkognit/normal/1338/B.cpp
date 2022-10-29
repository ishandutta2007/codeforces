#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, T, P, mn=1, mx=0, a[1000001], pr[1000001], in[1000001], out[1000001], hh[1000001];
vector<ll> v;
vector<ll> c[1000001];
ll bn[1000001][20];
ll tt[1000001];

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

void dfs(int h,int k=1,int p=0)
{
    T++;
    in[h]=T;
    hh[h]=k;
    bn[h][0]=p;
    for (int i = 1; i < 20; i++) bn[h][i]=bn[bn[h][i-1]][i-1];
    if (c[h].size()==1)
    {
        tt[h]=1;
        T++;
        out[h]=T;
        return;
    }
    ll g=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],k+1,h);
            g+=tt[c[h][i]];
        }
    if (g>1) mx-=(g-1);
    T++;
    out[h]=T;
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[y]<=out[x];
}

ll get_lca(int x,int y)
{
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    for (int i = 19; i > -1; i--)
        if (!is_ancestor(bn[x][i],y)) x=bn[x][i];
    return bn[x][0];
}

void solve()
{
    cin >> n;
    out[0]=1e9;
    mn=1, mx=n-1;
    if (n==2)
    {
        cout << "1 1\n";
        return;
    }
    vector<pll> v;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
        //v.pb(mp(x,y));
    }
    for (int i = 1; i <= n; i++)
        if (c[i].size()>1) P=i;
    dfs(P);
    for (int i = 1; i <= n; i++)
        if (c[i].size()==1) v.pb(mp(in[h],i));
    sort(all(v));
    for (int i = 0; i < v.size()-1; i++)
    {
        ll x=v[i].se, y=v[i+1].se;
        ll p=get_lca(x,y);
        if ((hh[x]+hh[y]-2*hh[p])%2!=0) mn=3;
    }
    cout << mn << " " << mx << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //for (ll i = 1; i <= 60; i++) pr[i]=pr[i-1]+(1ll<<(i-1));
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

ghlaz
azjgh

*/