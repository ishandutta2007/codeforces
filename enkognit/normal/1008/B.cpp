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

ll n,m,k,l,r,i,j,w,x,y,p,b[200001];
pll a[200001];
string s,d;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
  reverse(a+1,a+n+1);
  k=min(a[1].fi,a[1].se);
  for (i=2;i<=n;i++)
   if (max(a[i].fi,a[i].se)<k) {cout << "NO";exit(0);} else
   if (min(a[i].fi,a[i].se)<k) k=max(a[i].fi,a[i].se); else k=min(a[i].fi,a[i].se);
 cout << "YES";
  return 0;
}