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
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ll n,m,i,j,k,l,r,x,y,z,t1,t2,t3,a[100001];vector <ll> b;

int main()
{
  //freopen("forest.in","r",stdin);
  //freopen("forest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> a[0];
  if (a[0]!=0) {cout << 1;exit(0);}
  k=0;
  for (i=1;i<n;i++)
  {
   cin >> a[i];
  }
  for (i=1;i<n;i++) if (k+1<a[i]) {cout << i+1;exit(0);} else k=max(k,a[i]);
  cout << -1;
  return 0;
}