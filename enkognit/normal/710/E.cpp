#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

ll n,p=0,k,b,m,i,j,o,l,ans,x,y,q,a[1005][1005];ll dp[30000001];
string s;

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input1.txt","r",stdin);
  //freopen("output1.txt","w",stdout);
  cin >> n >> x >> y;
  dp[0]=0;
  for (i=1;i<n*2;i++)
  {
   dp[i]=dp[i-1]+x;
   if ((i+1)%2) dp[i]=min(dp[i],dp[i/2]+y);
   if ((i+1)%2 && i/2<i-1)dp[i-1]=min(dp[i-1],dp[i]+x);
  }
  for (i=n*2-1;i>n;i--) dp[n]=min(dp[i]+x*(i-n),dp[n]);
  cout << dp[n];
  return 0;
}