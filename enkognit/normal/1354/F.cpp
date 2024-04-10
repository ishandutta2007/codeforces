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
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF=1e18;
const ld E=1e-8;
const ld pi=acos(-1);
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T;
ll dp[80][80];
bool tt[80][80];
pair<pll,ll> a[1001];
//int d[5001][5001];

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

bool comp(pair<pll,ll> x,pair<pll,ll> y)
{
    return x.fi.se<y.fi.se;
}

void solve()
{
    cin >> n >> m;
    m=min(n,m);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se=i;
    }
    sort(a+1,a+n+1,comp);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) dp[i][j]=-1e18;
    dp[0][0]=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (dp[i+1][j]<dp[i][j]+a[i+1].fi.se*(m-1))
            {
                dp[i+1][j]=max(dp[i+1][j], dp[i][j]+a[i+1].fi.se*(m-1));
                tt[i+1][j]=0;
            }
            if (j<m && dp[i+1][j+1]<dp[i][j]+a[i+1].fi.fi+a[i+1].fi.se*j)
            {
                dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+a[i+1].fi.fi+a[i+1].fi.se*j);
                tt[i+1][j+1]=1;
            }
        }
    ll p=m;
    //cout << dp[n][m] << "\n";
    vector<ll> v, v2;
    for (int i = n; i > 0; i--)
    {
        if (tt[i][p]==0)
        {
            v2.pb(a[i].se);
        }else
        {
            v.pb(a[i].se);
            p--;
        }
    }
    reverse(all(v));
    cout << v.size()+v2.size()*2 << "\n";
    for (int i = 0 ;i < v.size()-1; i++) cout << v[i] << " ";
    for (int i = 0 ;i < v2.size(); i++) cout << v2[i] << " -" << v2[i] << " ";
    cout << v.back();
    cout << "\n";
}

int main()
{
    //freopen("input3.txt","r",stdin);
    //freopen("output3.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}