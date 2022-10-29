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

ll n,m,k,l,i,j;
ll a[11],b[11];
ll t[11];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++) cin >> a[i];
  for (j=1;j<=m;j++)
  {
   cin >> l;
   t[l]++;
  }
  for (i=1;i<=n;i++)
  if (t[a[i]]>0) {cout << a[i] << " ";t[a[i]]--;}
  return 0;
}