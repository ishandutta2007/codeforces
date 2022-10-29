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

ll n,m,k,l,i,j,x,y;
pll a[200001];
ll w[200001],r[200001],q[200001],b[200001];

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> a[i].fi;a[i].se=i;b[i]=a[i].fi;}
  sort(a+1,a+n+1);
  a[0].fi=-1e9;
  l=0;
  for (i=1;i<=n;i++)
  {
   if (a[i].fi==l && q[l]==0) q[l]=i,l++;
  }
  l=0;
  k=-1;
  while (l<n)
  {
   l++;
   ll e=k;
   if (a[q[k+1]].fi==k+1)
   {
    r[l]=a[q[k+1]].se;
    q[k+1]++;
    k++;
   }else
   {
    bool e=0;
    while (k>1 && !(a[q[k-3-e+1]].fi==k-3-e+1)){k-=3+e-1;e=1;}
    if (k<0) {cout << "Impossible";exit(0);}
    r[l]=a[q[k-3-e+1]].se;
    q[k-3-e+1]++;
    k-=3+e-1;
   }
   if (e==k) {cout << "Impossible";exit(0);}
  }
  for (i=1;i<=n;i++) if (r[i]==0) {cout << "Impossible";exit(0);}
  cout << "Possible\n";
  for (i=1;i<=n;i++) cout << r[i] << " ";cout << "\n";
  return 0;
}