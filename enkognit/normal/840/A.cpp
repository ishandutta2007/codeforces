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

ll n,m,k,l=0,r,i,j,w,x,y,p,a[200001],c[200001];
pll b[200001];

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) cin >> a[i];
  sort(a+1,a+n+1);
  reverse(a+1,a+n+1);
  for (i=1;i<=n;i++) {cin >> b[i].fi;b[i].se=i;}
  sort(b+1,b+n+1);
  for (i=1;i<=n;i++) {c[b[i].se]=a[i];}
  for (i=1;i<=n;i++) cout << c[i] << " ";
  return 0;
}