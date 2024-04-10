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

using namespace std;

ll n,m,i,j,k,l=0,x,y,h=1,r,o,p=0,a[100001];
string s;
map <ll,ll> f;
ll t[200002];

int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++) cin >> a[i];
  for (i=1;i<n;i++)
  {
   if (a[i]==a[i-1]+1) k++; else k=0;
   l=max(l,k);
  }
  ll l1=0,l2=0;
  if (a[0]==1) for (i=1;i<n;i++) if (a[i]==a[i-1]+1) l1++; else break;
  if (a[n-1]==1000) for (i=n-2;i>=0;i--) if (a[i]==a[i+1]-1) l2++; else break;
  cout << max(max(l1,l2),l-1);
  return 0;
}