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

ll n,i,x,y,h,j,k,u,m,l;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> m >> k >> l >> n;
  u=n-(m+k-l);
  if (l>k || l>m || u<1 || m+k-l>=n || u>n) cout << -1;else cout << u;
  return 0;
}