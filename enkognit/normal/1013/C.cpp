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

ll n,m,k,i,j,a[300001];

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=1;i<=n*2;i++) cin >> a[i];
  sort(a+1,a+n*2+1);
  k=(a[n]-a[1])*(a[n*2]-a[n+1]);
  for (i=2;i<=n;i++)
  {
   if ((a[i+n-1]-a[i])*(a[n*2]-a[1])<k) k=(a[i+n-1]-a[i])*(a[n*2]-a[1]);
  }
  k=min(k,(a[n*2]-a[n])*(a[n+1]-a[1]));
  cout << k;
  return 0;
}