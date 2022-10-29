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


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, T, Q, a[1000001], K, R, dp[60][60], kl[60];
vector<pll> v;

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
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
    cin >> d >> m;
    ll p = 1, u = 1;
    for (int i = 1; i <= 32; i++)
        for (int j = 1; j <= 32; j++) dp[i][j] = 0;
    while (p * 2 <= d) p *= 2, u++;
    //cout << p << " " << u << "\n";
    for (int i = 1; i < u; i++) dp[1][i] = binpow(2, i-1, m), kl[i]= binpow(2, i-1, m);
    dp[1][u] = (d - p + 1) % m;
    kl[u] = (d - p + 1) % m;
    for (int i = 1; i <= 32; i++)
        for (int j = 1; j <= u; j++)
            for (int o = j + 1; o <= u; o++)
                dp[i + 1][o] = (dp[i + 1][o] + dp[i][j] * (kl[o]) % m)%m;
    ll ans = 0;
    for (int i = 1; i <= 32; i++)
    {
        for (int j = 1; j <= u; j++) ans = (ans + dp[i][j]) % m;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/