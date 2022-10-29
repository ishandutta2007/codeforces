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

ll n,m,k,i,j,a[100001],x;
pll t[1000001];ll tt[1000001];

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
   if (tt[a[i]]) {cout << 0;exit(0);} else tt[a[i]]=1;
  }
  for (i=0;i<n;i++)
  {
   ll u=0;
   while ((a[i] & m) != a[i])
   {
    u++;
    a[i]=(a[i]&m);
    if (tt[a[i]]==1) t[a[i]].se=u,tt[a[i]]=2;
    if (tt[a[i]]==2)
    {
     if (t[a[i]].fi>u) t[a[i]].fi=u; else
        if (t[a[i]].se>u) t[a[i]].se=u;
    }  else t[a[i]].fi=u,tt[a[i]]=1;
   }
  }
  ll k=10000001;
  for (i=0;i<=100000;i++)if (tt[a[i]]==2) k=min(k,t[a[i]].fi+t[a[i]].se);
  if (k==10000001)cout << -1; else cout <<k;
  return 0;
}