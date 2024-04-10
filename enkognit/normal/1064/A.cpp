#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>

using namespace std;

ll n,i,j,k,p,x,y,u,m,l,r,a[300001];

int main()
{
  //freopen("yogurt.in","r",stdin);
  //freopen("yogurt.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  if (n>=m+k)
  {
   {cout << n-m-k+1;}
  }else
  if (m>=n+k) cout << m-n-k+1; else
  if (k>=n+m) cout << k-n-m+1; else cout << 0;

  return 0;
}