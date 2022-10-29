#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j;
vector <ll> c[100008], v, z;
ll a[1000001], dp[300005][11];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++) dp[j][i]=-1e18;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (j==1)
            {
                dp[i][j]=max(a[i]-k,dp[i][j]);
                dp[i][j]=max(dp[i][j],dp[i-1][m]+a[i]-k);
            }else
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]);
        }
    ll ans=0;
    //for (int i = 1; i <= n; i++)
   // {
      //for (int j = 1; j <= m; j++) cout << dp[i][j] << " ";
      //cout << "\n";
    //}
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){ans=max(ans,dp[i][j]);}
    cout << ans;
    return 0;
}