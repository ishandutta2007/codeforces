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

ll n,m,k,l,r=0,i,j,w,x,y,z;
ll a[1001];

//struct thll{ll fi,se,th;};

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=1;i<=n;i++) cin >> a[i];
  for (i=1;i<=m;i++)
  {
   cin >> x >> y;
   k+=min(a[x],a[y]);
  }
  cout << k;
  return 0;
}