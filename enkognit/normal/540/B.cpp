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

ll n,m,k,l=0,r,i,j,w,x,y,p;
ll a[10001];


int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> m >> n >> p >> x >> y;
  for (i=1;i<=n;i++)
  {
   cin >> a[i];
   k+=a[i];
   l+=a[i]<y;
  }
  for (i=n+1;i<=m;i++)
  {
   if (l+1<(m+1)/2)
   {
    if (k<x) a[i]=1,k++,l++; else {cout << -1;exit(0);}
   }else
   if (k+y<=x)a[i]=y,k+=y; else {cout << -1;exit(0);}
  }

  if (l>=m-l){cout << -1;exit(0);} else
  for (i=n+1;i<=m;i++) cout << a[i] << " ";
  /*for(i=1;i<=n;i++)
  {
   cout << a[i].se << " " << a[i].fi << "\n";
  }*/
  return 0;
}