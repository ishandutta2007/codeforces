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

ll n, m, k, pp[100001], hh[100001], kl[100001];
vector<int> c[100001];
pii a[100001];
bool TT=0;

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

void dfs(int h,int p=-1)
{
    kl[h]=pp[h];
    pll o=mp(0,0);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            if (TT) return;
            kl[h]+=kl[c[h][i]];
            o.fi+=a[c[h][i]].fi;
            o.se+=a[c[h][i]].se;
        }
    if ((kl[h]+hh[h])%2!=0)
    {
        TT=1;
        return;
    }
    a[h].fi=(kl[h]+hh[h])/2;
    a[h].se=(kl[h]-hh[h])/2;
    if (o.fi+o.se+pp[h]!=a[h].fi+a[h].se || a[h].fi<o.fi || a[h].se<0 || a[h].fi<0)
    {
        TT=1;
        //cout << h << " " << o.fi << " " << o.se << " " << a[h].fi << " " << a[h].se << " " << kl[h] << " " << hh[h] << "\n";
        return;
    }
}

void solve()
{
    cin >> n >> m;
    TT=0;
    for (int i = 1; i <= n; i++) c[i].clear();
    for (int i = 1; i <= n; i++) cin >> pp[i];
    for (int i = 1; i <= n; i++) cin >> hh[i];
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    if (TT) cout << "NO\n"; else cout << "YES\n";
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
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
a-b=k
a+b=m
a=(m+k)/2;
b=(m-k)/2;
*/