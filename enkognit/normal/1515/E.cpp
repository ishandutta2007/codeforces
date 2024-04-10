#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll M;
ll n, m, k, sz, k1, k2, a[300005], dp[500][500];
ll c[500][500];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n >> M;
    c[1][0]=1;
    c[1][1]=1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= i; j++)
        {
            c[i][j]=((j>0?c[i-1][j-1]:0)+c[i-1][j])%M;
        }
    a[1]=1;
    for (int i = 2; i <= n; i++)
        a[i]=(a[i-1]*2)%M;
    dp[0][0]=1;
    for (int j = 1; j <= n; j++)
        for (int i = 2; i <= n+1; i++)
        {
            for (int u = j-1; u < i-1; u++)
            {
                dp[i][j]=((dp[i][j]+(dp[u][j-1]*c[(u-(j-1))+(i-u-1)][(i-u-1)]%M)*a[i-u-1])%M)%M;
            }
            //cout << i << "  " << j << " : " << dp[i][j] << "\n";
        }
    ll ans=0;
    for (int i = 1; i <= n; i++)
        ans=(ans+dp[n+1][i])%M;
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
999999999
*/