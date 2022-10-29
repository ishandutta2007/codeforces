#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, TT, dp[101][20001];

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
    return l;
}

void solve()
{
    cin >> n;
    vector<pll> v;
    ll smb=0, sma=0;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        x*=2;y*=2;
        sma+=x;
        v.pb(mp(x,y));
        smb+=y;
    }
    for (int j = 0; j <= n; j++)
        for (int i = 0; i <= sma; i++) dp[j][i]=-1e9;
    dp[0][0]=smb/2;
    for (int i = 0; i < v.size(); i++)
    {
        for (int u = n-1; u > -1; u--)
            for (int j = sma; j > -1; j--)
                if (dp[u][j]!=-1e9)
                {
                    //cout << u << " " << j << " " << dp[u][j] << "\n";
                    dp[u+1][j+v[i].fi]=max(dp[u+1][j+v[i].fi], dp[u][j]+v[i].se/2);
                }
    }
    for (int i = 1; i <= n; i++)
    {
        ll ans=-1e9;
        for (ll j = 0; j <= sma; j++)
            //if (dp[i][j]!=)
        {
            //cout << i << " " << j << ""
            ans=max(min(dp[i][j], j), ans);
        }
        cout.precision(5);
        cout <<fixed<< (ld)ans/2. << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
3 2
100 100
101 101
102 102
101 101 2
105 105 2
*/