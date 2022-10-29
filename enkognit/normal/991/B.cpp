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

long double x,y,h,j,k,u,m,l,a[101];
ll i,n;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> a[i];k+=a[i];}
  m=4.5*n;
  if (k>=m) {cout << l;exit(0);}
  sort(a+1,a+n+1);
  for (i=1;i<=n;i++)
  {
   k+=5-a[i],l++;
   if (k>=m) {cout << l;exit(0);}
  }
  return 0;
}