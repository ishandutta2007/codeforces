#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pu push
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m=-1e12,i,j,k,l;
bool t[1001];
ll a[200001],b[200001];
vector <ll> dp;

int main()
{
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  dp.pb(0);
  for (i=1;i<=n;i++)
  {cin >> a[i];dp.pb(dp[i-1]+a[i]);}
  for (j=1;j<=m;j++) cin >> b[j];
  ll z=0;
  for (i=1;i<=m;i++)
  {
   //cout << z << " ";
   if (b[i]+z>=dp[n]) {cout << n << "\n";z=0;} else
   {
    int r=upper_bound(dp.begin(),dp.end(),b[i]+z)-dp.begin();
    z+=b[i];
    cout << n-r+1 << "\n";
   }
  }
  return 0;
}