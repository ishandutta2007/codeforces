#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,i,u,j,k,l;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  vector <ll> a(n+1);
  for (ll i=1;i<=n;i++) cin >> a[i];
  cin >> m;
  vector <ll> b(m+1);
  for (ll i=1;i<=m;i++) cin >> b[i];
  i=0;j=0;l=0;k=0;
  while (true)
  {
   if (i>=n && j>=m) break;
   if (l<k || l==0)
   {
    if (i==n) {cout << -1;exit(0);}i++;l+=a[i];
   }else
   if (l>k)
   {
    if (j==m) {cout << -1;exit(0);}j++;k+=b[j];
   }else
   if (l==k)
   {
    u++;l=0;k=0;
   }
   //cout << i << " " << j << " " << l << " " << k << "\n";
  }
  if (l==k) u++; else {cout << -1;exit(0);}
  cout << u;
  return 0;
}