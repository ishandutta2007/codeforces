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

ll n,m,k,l,r,i,j,w,x,y;pll a[2001];ll b[2001];
bool t[2001],tt;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++) {cin >> a[i].fi;a[i].se=i;b[i]=a[i].fi;}
  sort(a+1,a+n+1);
  reverse(a+1,a+n+1);
  for (i=1;i<=m;i++) t[a[i].se]=1,l+=a[i].fi;
  cout << l << "\n";
  k=0;
  for (i=1;i<=n;i++)
  {
   //cout << b[i] << " ";
   k++;
   if (t[i])
   {
    if (!tt) tt=1; else {cout << k-1 << " ";k=1;}
   }
  }
  cout << k;
  return 0;
}