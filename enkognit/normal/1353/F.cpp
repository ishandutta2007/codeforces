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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, ans, RR=0, a[101][101], b[101][101], dp[101][101];

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

void solve()
{
    cin >> n >> m;
    vector<ll> v;
    v.pb(0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (!(i==1&& j==1))
            {
                b[i][j]=a[i][j]-(a[1][1]+i+j-2);
                if (b[i][j]<0) v.pb(b[i][j]);
            }
        }
    /*cout << "---\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << b[i][j] << " ";
        cout << "\n";
    }*/
    sort(all(v));
    reverse(all(v));
    ll ans=1e18;
    for (int i = 1; i <= n; i++) dp[i][0]=-1;
    for (int i = 1; i <= m; i++) dp[0][i]=-1;
    for (int it = 0; it < v.size(); it++)
        if (it==0 || v[it]!=v[it-1])
        {
            //cout << v[it] << "\n";
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j]=-1;
                    if (i==1 && j==1) dp[i][j]=-v[it];
                    //if (v[it]==-8) cout << i << " " << j << " " << dp[i-1][j] << " " << dp[i][j-1] << "\n";
                    if (b[i][j]>=v[it] && (dp[i-1][j]!=-1 || dp[i][j-1]!=-1))
                    {
                        if (dp[i-1][j]!=-1)
                        {
                            if (dp[i][j]==-1) dp[i][j]=dp[i-1][j]+b[i][j]-v[it]; else
                                dp[i][j]=min(dp[i][j], dp[i-1][j]+b[i][j]-v[it]);
                        }
                        if (dp[i][j-1]!=-1)
                        {
                            if (dp[i][j]==-1)
                            {
                                dp[i][j]=dp[i][j-1]+b[i][j]-v[it];
                                //cout << dp[i][j-1]+b[i][j]-v[it] << "\n";
                            } else
                            {
                                dp[i][j]=min(dp[i][j], dp[i][j-1]+b[i][j]-v[it]);
                                //cout << " - " << dp[i][j] << " " << dp[i][j-1]+b[i][j]-v[it] << "\n";
                            }
                        }
                    }
                }
            if (dp[n][m]!=-1)ans=min(ans, dp[n][m]);
        }
    //for (int i = 1; i <= n; i++)
    /*{
        for (int j = 1; j <= m; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << "---\n";*/
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
    ll t;
    cin >> t;
    //cout << "-\n";
    while (t--)
    {
        solve();
    }
    return 0;
}