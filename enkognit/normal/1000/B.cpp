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

ll n,m,k,l,r,i,j,y;
ll a[100001];pll dp[100001];
bool t;

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> n >> m;
  y=1;
  for (i=1;i<=n;i++)
  {
   cin >> a[i];
  }
  l=m;
  for (i=n;i>=1;i--)
  {
   if (i%2==1)
   {
    dp[i].se=dp[i+1].se+l-a[i];dp[i].fi=dp[i+1].fi;
    l=a[i];
   }
    else
   {
    dp[i].fi=dp[i+1].fi+l-a[i];dp[i].se=dp[i+1].se;
    l=a[i];
   }
  }
  dp[0].fi=dp[1].fi+a[1];
  k=dp[0].fi;
  a[n+1]=m;
  for (i=1;i<=n;i++)
  {
   if (a[i]+1<a[i+1])
   if (k<dp[0].fi-dp[i].fi+dp[i].se-1) k=dp[0].fi-dp[i].fi+dp[i].se-1;
  }
  cout << k;
  return 0;
}