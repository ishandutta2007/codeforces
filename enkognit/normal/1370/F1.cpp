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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, hh[200001], mx, in[200001], out[200001], T;
pll pp[2001];
vector<ll> c[200001], v[1001];

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

void dfs(int h,ll k,int p=-1)
{
    in[h]=++T;
    hh[h]=k;
    mx=max(mx,k);
    v[k].pb(h);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p) dfs(c[h][i],k+1,h);
    out[h]=++T;
}

#define dies_from_cringe exit(0)

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

void solve()
{
    cin >> n;
    mx=0;
    for (int i = 1; i <= n; i++) c[i].clear(), v[i].clear();
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
    ll p, d;
    cin >> p >> d;
    dfs(p,0);
    ll l=0, r=mx+1;
    while (l<r)
    {
        ll w=(l+r)/2;
        cout << "? " << v[w].size() << " ";
        for (int i = 0; i < v[w].size(); i++) cout << v[w][i] << " ";
        cout << "\n";
        ll q, y;
        cin >> y >> q;
        pp[w]=mp(y,q);
        if (q==d) l=w+1; else r=w;
    }
    l--;
    ll a, b, e;
    if (pp[l].fi==0)
    {
        cout << "? " << v[l].size() << " ";
        for (int i = 0; i < v[l].size(); i++) cout << v[l][i] << " ";
        cout << "\n";
        cin >> a >> e;
    }else a=pp[l].fi;
    e=d-l;
    if (e==0) b=p; else
    {
        vector<ll> ww;
        for (int i = 0; i < v[e].size(); i++) if (!is_ancestor(v[e][i],a))ww.pb(v[e][i]);
        cout << "? " << ww.size() << " ";
        for (int i = 0; i < ww.size(); i++) cout << ww[i] << "\n";
        cout << "\n";
        cin >> b >> e;
    }
    cout << "! " << a << " " << b << "\n";
    string s;
    cin >> s;
    if (s!="Correct") dies_from_cringe;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
1
8
1 2
1 6
6 7
6 8
2 3
2 4
2 5
*/