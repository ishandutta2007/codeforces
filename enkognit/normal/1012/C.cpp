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

const ll MOD=1e9+7;
ll n, m, k, l, r, a[300005], p[300005], i, j;
ll dp[5005][3005][2];

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 1; i <= n+1; i++)
      for (int j = 0; j <= n/2+1; j++)
          for (int u = 0; u < 2; u++)dp[i][j][u]=1e18;


  //for (int i = 1; i <= (n+1)/2; i++) cout << dp[n+1][i] << " ";

  dp[1][0][0]=0;

  for (int i = 1; i <= n; i++)
      for (int j = 0; j <= (n+1)/2; j++)
          for (int u = 0; u < 2; u++)
            if (dp[i][j][u]!=1e18)
            {
                //cout << i << " " << j << " " << dp[i][j] << "\n";
                if (u==0)
                {
                    dp[min(n+1,(ll)i+2)][j+1][1]=min(dp[i][j][u]+max(0ll,a[i-1]-a[i]+1)+max(0ll,a[i+1]-a[i]+1), dp[min(n+1,(ll)i+2)][j+1][1]);
                }else
                if (u==1)
                {
                    dp[min(n+1,(ll)i+2)][j+1][1]=min(dp[i][j][u]+max(0ll,min(a[i-2],a[i-1]+1)-a[i])+max(0ll,a[i+1]-a[i]+1), dp[min(n+1,(ll)i+2)][j+1][1]);
                }
                dp[i+1][j][0]=min(dp[i][j][u],dp[i+1][j][0]);
            }
  for (int i = 1; i <= (n+1)/2; i++) cout << min(dp[n+1][i][0],dp[n+1][i][1]) << " ";
  return 0;
}