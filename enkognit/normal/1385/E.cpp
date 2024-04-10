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

ll n, m, T, nm[300001], kl[300001];
vector<ll> c[300001], g[200001];

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

bool tt[200001], tl[200001];
bool TT=0;

void dfs(int h)
{
    nm[h]=++T;
    tt[h]=1;
    tl[h]=1;
    //cout << h << " " << T << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (tt[c[h][i]])
        {
            //cout << h << " " << c[h][i] << "\n";
            TT=1;
            return;
        }else
        if (!tl[c[h][i]])
        {
            kl[c[h][i]]--;
            if (kl[c[h][i]]==0)dfs(c[h][i]);
        }
    tt[h]=0;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) tt[i]=0, c[i].clear(), g[i].clear(), tl[i]=0, kl[i]=0;
    TT=0;
    vector<pair<pll,ll> > v;
    T=0;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> h >> x >> y;
        if (h==1)
        {
            c[x].pb(y);
            kl[y]++;
        }
        v.pb(mp(mp(x, y), h));
    }
    for (int i = 1; i <= n; i++)
        if (kl[i]==0 && !tl[i]) dfs(i);
    for (int i = 1; i <= n; i++)
    {
        //cout << i << " " << tl[i] << "\n";
        if (kl[i]) {cout << "NO\n";return;}
    }
    if (TT) {cout << "NO\n";return;}
    cout << "YES\n";
    //for (int i = 1; i <= n; i++) cout << nm[i] << " ";
    //cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].se==1) cout << v[i].fi.fi << " " << v[i].fi.se << "\n"; else
        {
            if (nm[v[i].fi.fi]>nm[v[i].fi.se]) swap(v[i].fi.fi, v[i].fi.se);
            cout << v[i].fi.fi << " " << v[i].fi.se << "\n";
        }
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
    cin >> t;
    while(t--)
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