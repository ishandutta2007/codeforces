#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define ldl long double*/
/**/
using namespace std;

ll n,i,y,j,k,l,m=1000000;
ll a[100001],b[100001],t[100001],tt[100001];
vector <ll> dp;

int main()
{
  //freopen("disease.in","r",stdin);
  //freopen("disease.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n;
  for (i=1;i<=n;i++) cin >> a[i];
  dp.pb(0);
  for (i=1;i<=n;i++)
  {
   cin >> b[i];
   dp.pb(dp[i-1]+b[i]);
  }
  for (i=1;i<=n;i++)
  {int l=upper_bound(dp.begin()+i-1,dp.end(),a[i]+dp[i-1])-dp.begin();
   t[l]++;
   tt[l]+=a[i]+dp[i-1]-dp[l-1];}
  for (i=1;i<=n;i++)
  {
   k++;
   k-=t[i];
   cout << k*b[i]+tt[i] << " ";
  }
  return 0;
}