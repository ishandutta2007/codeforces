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

ll n,m,k,l=0,r,i,j,w,x,y,p;pll a[200001];

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  if (m<n-1) {cout << "Impossible";exit(0);}k=m;
  for (i=1;i<n;i++)
  {
   if (m==0) break;
   for (j=i+1;j<=n;j++)
   {
    if (m==0) break;
    if (__gcd(i,j)==1) {a[m]=mp(i,j);m--;}
   }
  }
  if (m>0) {cout << "Impossible";exit(0);}
  cout << "Possible\n";
  for(i=k;i>=1;i--) cout << a[i].fi << " " << a[i].se << "\n";
  return 0;
}