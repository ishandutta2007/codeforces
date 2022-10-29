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

ll n,m,l,i,j,x,y;long double k,dp[50001],a[50001];
string s;bool tt;

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++) cin >> a[i];
  for (i=1;i<m;i++) dp[i]=dp[i-1]+a[i];
  for (i=m;i<=n;i++)
  {
   dp[i]=dp[i-1]+a[i];
   for (j=0;j<=i-m;j++) k=max(k,(dp[i]-dp[j])/(long double)(i-j));
  }
  cout.precision(18);
  cout <<fixed<< k;
  return 0;
}