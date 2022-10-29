#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pu push
#define len length()
#define ld long double
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m,k,i,j,l,r;pll a[1000001];

int main()
{
  //freopen("cubroot.in","r",stdin);
  //freopen("cubroot.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  for (i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
  if (n==0)
  {
   ll o=m;
   l+=o/k;
  }else
  {
   a[n+1].fi=m;
   for (i=0;i<=n;i++)
   {
    ll o=a[i+1].fi-a[i].fi-a[i].se;
    l+=o/k;
   }
  }
  cout << l;
}