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

ll n,m,i,j,l=1e9,r,o,k=0;ll x,y;


int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  l=n%3;
  n-=n%3;
  if (n/3%3==1) cout << n/3 << " " << n/3+(l==2) << " " << n/3+l-(l==2);else
  if (n/3%3==2) cout << n/3 << " " << n/3-(l==1) << " " << n/3+l+(l==1);else
  cout << n/3-1 << " " << n/3-1-(l==1) << " " << n/3+2+l+(l==1);
  return 0;
}
/**/