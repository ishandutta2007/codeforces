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

const ll MOD = 1e9+7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, g, T, Q;
ll a[1000001], b[1000001], pr[1000001], sf[1000001];
vector<ll> v;
bool tt[101][101];

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
    for (int i = 1; i <= n; i++)
        if (i!=h && !tt[h][i])
        {
            tt[h][i]=1;
            dfs(i);
        }
    v.pb(h);
}

void solve()
{
    ll l, r;
    cin >> n >> l >> r;
    bool t=0;
    if (r==n*(n-1)+1) t=1, r--;
    ll lr=0, rr=n;
    while (lr<rr)
    {
        ll w=(lr+rr+1)/2;
        if ((n*(n-1)/2-(n-w)*(n-w-1)/2)*2>=l) rr=w-1; else lr=w;
    }
    //cout << lr << "\n";
    l-=(n*(n-1)/2-(n-lr)*(n-lr-1)/2)*2;
    r-=(n*(n-1)/2-(n-lr)*(n-lr-1)/2)*2;
    //cout << l << " " << r << "\n";
    ll p=lr+1;
    ll o=p+1;
    vector<ll> v;
    v.pb(0);
    for (int i = 1; i <= r; i+=2)
    {
        v.pb(p);
        v.pb(o);
        o++;
        if (o>n) p++, o=p+1;
    }
    for (int i = l; i <= r; i++) cout << v[i] << " ";
    if (t) cout << "1\n"; else cout << "\n";
    return;
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

ghlaz
azjgh

*/