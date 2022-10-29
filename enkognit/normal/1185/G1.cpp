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
ll n, m, t[50], g[50], k, l, r, sum[140000];
int dp[16][16][140000];

void rec(int h,int mask,int sm)
{
    if (h>n)
    {
        sum[mask]=sm;
        return;
    }
    rec(h+1,mask*2,sm);
    rec(h+1,mask*2+1,sm+t[h]);
}

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
      cin >> t[i] >> g[i];
  }
  rec(1,1,0);
  dp[0][0][(1<<(n))]=1;
  //cout << sum[5] << "\n";
  for (int i = 0; i < n; i++)
      for (int j = 0; j <= n; j++)
          for (int u = 1; u < (1<<(n+2)); u++)
              if (dp[i][j][u])
              {
                  for (int it = 1; it <= n; it++)
                      if ((u|(1<<(n-it)))!=u && g[it]!=g[j])
                      {
                          //cout << (u^(1<<(n-it))) << " " << i+1 <<  "\n";
                          dp[i+1][it][u|(1<<(n-it))]+=dp[i][j][u];
                          //dp[i+1][it][u|(1<<(n-it))]%=MOD;
                      }
              }

  int ans=0;
  for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
          for (int u = 0; u < (1<<(n+2)); u++)
            if (sum[u]==m)
            {
                ans+=dp[i][j][u];
                //cout << i << " " << j << " " << u << " " << dp[i][j][u] << " " << sum[u] << "\n";
                ans%=MOD;
            }
  cout << ans%MOD;
  return 0;
}