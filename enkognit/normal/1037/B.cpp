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

using namespace std;

ll n,i,j,p,u,x,m,l=0,k,a[200001];

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++) cin >> a[i];
  sort(a+1,a+n+1);
  if (a[n/2+1]<m)
  {
   for (i=n/2+1;i<=n;i++){l+=m-a[i];a[i]+=m-a[i];if (a[i]<=a[i+1])break;}
   cout << l;
  }else
  if (a[n/2+1]>m)
  {
   for (i=n/2+1;i>0;i--){l+=a[i]-m;a[i]-=a[i]-m;if (a[i]>=a[i-1])break;}
   cout << l;
  }else cout << 0;
  return 0;
}