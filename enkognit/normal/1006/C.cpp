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

ll n,m,k,l,r=0,i,j,w,x,y;ll a[200001];
map<ll,ll> t;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> a[i];r=a[i]+r;t[r]=i;}
  for (i=n;i>0;i--)
  {
   k+=a[i];
   if (t[k]<i && t[k]>0) {l=k;}
  }
  cout << l;
  return 0;
}