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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, kl=0, sz=0, bn[100001][20], hh[100001], in[100001], out[100001];
pair<ll,pll> ans;
vector<ll> c[100001], g[100001], vvv, vv1;
bool tt[100001];
vector<pll> vv;

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

void dfs(int h,int p=-1)
{
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            //cout << h << " " << c[h][i] << "\n";
            g[h].pb(c[h][i]);
            g[c[h][i]].pb(h);
            dfs(c[h][i],h);
        }else
        if (c[h][i]!=p)
        {
            vv.pb(mp(h,c[h][i]));
        }
}

void dfs2(int h,int k=0,int p=0)
{
    bn[h][0]=p;
    in[h]=++T;
    hh[h]=k;
    for (int i = 1; i < 20; i++) bn[h][i]=bn[bn[h][i-1]][i-1];
    for (int i = 0; i < g[h].size(); i++)
        if (g[h][i]!=p) dfs2(g[h][i],k+1,h);
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
    for (int i = 19; i > -1; i--)
        if (!is_ancestor(bn[x][i],y)) x=bn[x][i];
    return bn[x][0];
}

void dfs3(int h,int k,int p=0)
{
    if (k%2==0) vvv.pb(h); else vv1.pb(h);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p) dfs3(c[h][i],k+1,h);
}

void solve()
{
    cin >> n >> m >> k;
    in[0]=-1;
    out[0]=1e9;
    ans.fi=1e18;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    dfs2(1);
    //cout << in[1] << " "<< out[1] << "\n";
    //cout << in[2] << " "<< out[2] << "\n";
    for (int i = 0; i < vv.size(); i++)
    {
        ll x=vv[i].fi, y=vv[i].se;
        //cout << i << " " << x << " " << y << " " << lca(x,y) << "\n";
        ll o=hh[x]+hh[y]-hh[lca(x,y)]*2+1;
        if (ans.fi>o) ans=mp(o,mp(x,y));
    }
    if (ans.fi==1e18)
    {
        cout << "1\n";
        dfs3(1,0);
        if (vvv.size()<vv1.size()) swap(vvv,vv1);
        for (int i = 0; i < min((ll)vvv.size(),(k+1)/2); i++) cout << vvv[i] << " ";
        cout << "\n";
        return;
    }
    ll x=ans.se.fi, y=ans.se.se;
    ll p=lca(x,y);
    //cout << p << "\n";
    vector<ll> v, u;
    while (x!=p) v.pb(x), x=bn[x][0];
    v.pb(p);
    while (y!=p) u.pb(y), y=bn[y][0];
    reverse(all(u));
    for (int i = 0; i < u.size(); i++) v.pb(u[i]);
    if (v.size()<=k)
    {
        cout << "2\n";
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << "\n";
    }else
    {
        cout<< "1\n";
        ll o=0;
        for (int i = 0; i < v.size()-1; i+=2)
        {
            o++;
            if (o>(k+1)/2) break;
            cout << v[i] << " ";
        }
        cout << "\n";
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
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
3 10 12
1 Fufel 1 WA 1
2 OSUTeam 1 WA 2
3 vitebsk02 3 OK
5 fufel 3 WA 2
6 fufel 3 CE
6 fufel 3 TL 78
19 fufel 3 OK
23 fufel 1 OK
45 balukTeam 2 OK
54 VitebskieKovry 1 OK
74 MORGENSHTEND 2 WA 3
9595 ShlutLandShlutLand 1 OK
*/