#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, a[1000001], dp[501][501];

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
    //cout << l << "\n";
    return l;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n*2; j++) dp[i][j]=1e9;
    dp[0][0]=0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < n*2; j++)
        {
            dp[i][j+1]=min(dp[i][j+1], dp[i][j]);
            //cout << i << " " << j << " " << a[i+1] << " " << j+1 << "\n";
            if (i<n)dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+abs(a[i+1]-(j+1)));
        }
    cout << dp[n][n*2] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
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

3
1 4
4 3
8 1
3
1
3
2
*/