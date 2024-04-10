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

ll n,i,j,k,p,x,y,u,m,l,r,a[100001];

int main()
{
  //freopen("yogurt.in","r",stdin);
  //freopen("yogurt.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  if (m==0) {cout << n << " " << n;exit(0);}
  cout << max((ll)0,n-m*2);
  cout << " ";
  for (i=0;i<=m;i++) {k+=i;if (k>=m) break;}
  cout << n-i-1;
  return 0;
}