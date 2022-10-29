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

ll n,m,k,l,r,i,j,w,x,y,p,a[200001],b[200001];
string s;
map <ll,ll> c;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> a[i];c[a[i]]++;}
  for (i=1;i<=n;i++)
  {
   k=1;
   for (j=1;j<=30;j++)
   {
    k*=2;
    if (k>a[i])
    if (c[k-a[i]]>0 && (k/2!=a[i] || c[a[i]]>1)) {w++;break;}
   }
  }
  cout << n-w;
  return 0;
}