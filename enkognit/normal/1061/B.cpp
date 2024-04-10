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
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit

using namespace std;

ll n,k,m,i,j,o,l,ans,x,y,a[100001];
map <ll,ll> t;

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++) {cin >> a[i];}
  sort(a,a+n);
  for (i=0;i<n-1;i++)
  {
   ans+=a[i]-1;
   if (o<a[i]) o++;
  }
  ans+=o-(a[n-1]==o);
  cout << ans;
  return 0;
}