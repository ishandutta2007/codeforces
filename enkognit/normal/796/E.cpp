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

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z;
vector<vector<vector<int> > > dp, dd;
bool t1[10001], t2[10001];

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
    ll p, k;
    cin >> n >> p >> k;
    p=min(p, (n+k-1)/k*2);
    ll x, y;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> y;
        t1[y]=1;
    }
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> y;
        t2[y]=1;
    }
    dp.resize(p+1);
    for (int i = 0; i <= p; i++)
    {
        dp[i].resize(k+1);
        for (int j = 0; j <= k; j++) dp[i][j].resize(k+1, -1e9);
        if (i==0) dp[i][k][k]=0;
    }
    dd=dp;
    int i, j, u, z;
    for (i = 1; i <= n; i++)
    {
        int t=0;
        for (j = 0; j <= p; j++)
            for (u = 0; u <= k; u++)
                for (z = 0; z <= k; z++)
                    if (dp[j][u][z]>-1e9)
                {
                    //cout << i-1 << " " << j << " " << u << " " << z << " " << dp[j][u][z] << "\n";
                    dd[j][min((ll)u+1,k)][min((ll)z+1,k)]=
                        max(dp[j][u][z]+((t1[i] && min((ll)u+1,k)<k) || (t2[i] && min((ll)z+1,k)<k)), dd[j][min((ll)u+1,k)][min((ll)z+1,k)]);
                    if (j<p)
                    {
                        dd[j+1][0][min((ll)z+1,k)]=
                            max(dp[j][u][z]+(t1[i] || (t1[i] && min((ll)z+1,k)<k)), dd[j+1][0][min((ll)z+1,k)]);

                        dd[j+1][min((ll)u+1,k)][0]=
                            max(dp[j][u][z]+((t1[i] && min((ll)u+1,k)<k) || t2[i]), dd[j+1][min((ll)u+1,k)][0]);
                        if (j+1<p)
                        dd[j+2][0][0]=
                            max(dd[j+2][0][0], dp[j][u][z]+(t1[i] || t2[i]));
                    }
                    dp[j][u][z]=0;
                }
        swap(dd, dp);
    }
    int ans=0;
    for (int i = 0; i <= p; i++)
        for (int j = 0; j <= k; j++)
            for(int u = 0; u <= k; u++) ans=max(ans, dp[i][j][u]);
    cout << ans << "\n";
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/