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

ll n,m,i,j,x,k,l,o,p;
string s,d;

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  vector <ll> a(n);
  for (i=0;i<n;i++) cin >> a[i];
  o=k;
  p=0;
  for (i=n-1;i>=0;i--)
  {
   if (a[i]>o) {o=k-a[i];p++;if (p==m) break;l++;} else
   o-=a[i],l++;
  }
  cout << l;
  return 0;
}