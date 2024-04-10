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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, dp[205][205][205];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s, d;
    cin >> s;
    cin >> d;
    s=' '+s;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int u = 0; u <= n; u++) dp[i][j][u]=-1e9, dp[i][j][u]=-1e9;
    dp[0][0][0]=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
            for (int u = 0; u <= n; u++)
                if (dp[i][j][u]>-1e9)
            {
                dp[i+1][j][u]=max(dp[i+1][j][u], dp[i][j][u]);
                dp[i+1][j+(s[i+1]!=d[0])][u+1]=max(dp[i+1][j+(s[i+1]!=d[0])][u+1], dp[i][j][u]);
                dp[i+1][j+(s[i+1]!=d[1])][u+(d[0]==d[1])]=max(dp[i+1][j+(s[i+1]!=d[1])][u+(d[0]==d[1])], dp[i][j][u]+u);
            }
    ll ans=0;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) ans=max(ans, dp[n][i][j]);
    cout << ans << "\n";
    return 0;
}