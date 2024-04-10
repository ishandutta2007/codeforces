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
ll a[1001];
int dp[153][5701];
bool tt[5001];

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
    ll k, s;
    cin >> n >> k >> s;
    ll sm=0;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
        if (i<=k) sm+=a[i];
    }
    sort(all(v));
    ll l=1, w=0;
    for (int i = 0; i < k; i++)
    {
        while (tt[l]) l++;
        if (v[i].se<=k) tt[v[i].se]=1; else
            tt[l]=1, w+=(v[i].se-l);
    }
    s=min(s,w);
    for (int i = 1; i <= k+1; i++)
        for (int u = 0; u <= s; u++) dp[i][u]=1e9+1;
    dp[1][0]=0;
    for (ll u = 1; u <= n; u++)
    {
        //cout << u << " :\n";
        for (int i = min(k,u); i > -1; i--)
            for (int j = 0; j <= s; j++)
                if (dp[i][j]!=1e9+1)
                {
                    //cout << " " << i << " " << j << " " << dp[i][j] << "\n";
                    if (j+(u-i)<=s)dp[i+1][j+(u-i)]=min((ll)dp[i+1][j+(u-i)], dp[i][j]+a[u]);
                }
    }
    ll ans=1e18;
    /*for (int i = 1; i <= k+1; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i = 0; i <= s; i++)
    {
        ans=min(ans, (ll)dp[k+1][i]);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input3.txt","r",stdin);
    //freopen("output3.txt","w",stdout);
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