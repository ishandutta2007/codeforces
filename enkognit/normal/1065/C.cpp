#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>

using namespace std;

ll n,i,j,k,p,x=0,y=1e9,u,m,l,r,a[300001];

int main()
{
  //freopen("yogurt.in","r",stdin);
  //freopen("yogurt.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++) {cin >> x;r=max(r,x);y=min(y,x);a[x]++;}
  x=0;
  for (i=r;i>y;i--)
  {
   k+=a[i]+x;
   if (k>m) {l++,k=a[i]+x;}
   x+=a[i];
  }
  if (k>0) l++;
  cout << l;
  return 0;
}