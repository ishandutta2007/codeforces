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

ll n,m,k,l,r,i,j,w,x,y,p,a[200001];

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  y=1e9;
  for (i=1;i<=n;i++)
  {
   cin >> x;
   if (x<=y) {k++;a[k]=0;}
   a[k]++;y=x;
  }
  cout << k << "\n";
  for (i=1;i<=k;i++) cout << a[i] << " ";
  return 0;
}