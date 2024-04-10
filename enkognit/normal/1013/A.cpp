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

ll n,m,k,i,j,a[100001],x;

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=0;i<n;i++) {cin >> x;k+=x;}
  for (i=0;i<n;i++) {cin >> x;m+=x;}
  if (k>=m) cout << "Yes"; else cout << "No";
  return 0;
}