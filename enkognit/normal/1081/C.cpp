#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll ans,n,m,i,j,k,l,a[100001],c[100001];
string s;map <ll,ll> t;
ll v[100001];
ll dp[2002][2002];

int main()
{
  //freopen("backforth.in","r",stdin);
  //freopen("backforth.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  dp[1][1]=1;
  k++;
  for (i=1;i<=n;i++)
   for (j=1;j<=k;j++)
  {
   if (k-j<n-i) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
   if (j<k) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
  }
  for (i=1;i<=k;i++) ans+=dp[n][i],ans%=MOD;
  ans*=m;ans%=MOD;
  for (j=1;j<k;j++) {ans*=(m-1);ans%=MOD;}
  cout << ans;
}