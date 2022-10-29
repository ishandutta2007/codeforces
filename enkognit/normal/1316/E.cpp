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

ll n, m, k, d, h, ans, p, T, kl[80], dp[100001][128], a[100001], c[100001][9];
vector<ll> v[128];
bool tt[1000001];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> k;
    for (int i = 0; i < (1ll<<p); i++)
    {
        for (int j = 0; j < p; j++)
            if ((i&(1ll<<j))==0) v[i].pb(j);
    }

    vector<pll> pp;
    for (int i = 1; i <= n; i++) {cin >> a[i];pp.pb(mp(a[i],i));}
    sort(all(pp));
    pp.pb(mp(0,0));
    reverse(all(pp));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < p; j++) cin >> c[i][j];
    ll m=(1ll<<p);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) dp[i][j]=-1e18;
    dp[0][0]=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dp[i][j]!=-1e18)
            {
                if (i+1>k+p-v[j].size())
                {
                    dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
                    for (int u = 0; u < v[j].size(); u++)
                        dp[i+1][j^(1ll<<v[j][u])]=max(dp[i+1][j^(1ll<<v[j][u])], dp[i][j]+c[pp[i+1].se][v[j][u]]);
                }
                else
                {
                    dp[i+1][j]=max(dp[i+1][j], dp[i][j]+pp[i+1].fi);
                    for (int u = 0; u < v[j].size(); u++)
                        dp[i+1][j^(1ll<<v[j][u])]=max(dp[i+1][j^(1ll<<v[j][u])], dp[i][j]+c[pp[i+1].se][v[j][u]]);
                }
            }
    cout << dp[n][m-1];
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/