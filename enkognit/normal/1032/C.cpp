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
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

ll n,m,i,j,forw,k,l=0,r,o,p=0;ll a[100001];ll b[100001];
string s;
vector <ll> v;
map<ll,ll> t;

int main()
{
  //freopen("digits.in","r",stdin);
  //freopen("digits.out","w",stdout);
  fast_io;
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++)cin >> a[i];
  if (b[0]>0)l=n-b[0]; else r=-b[0];
  if (a[1]<a[2]) a[0]=0;
  for (i=1;i<n;i++)
  {
   if (a[i]<a[i+1])
   {
    if (a[i-1]<a[i] || (a[i-1]==a[i] && b[i-1]==1))l++; else l=1;
   } else
   if (a[i]>a[i+1])
   {
    if (a[i-1]>a[i] || (a[i-1]==a[i] && b[i-1]==5))l--; else l=5;
   }else
   if (a[i]==a[i+1])
   {
    if (a[i]>a[i-1] && i!=1)l++;else
    if (a[i]<a[i-1] && i!=1)l--;else
    if (l!=2) l=2; else l=3;
   }
   if (l<1 || l>5) {cout << -1;exit(0);}
   b[i]=l;
  }
  if (a[n-1]<a[n]) l=b[n-1]+1;else
  if (a[n-1]>a[n]) l=b[n-1]-1;else
  if (a[n-1]==a[n]) if (b[n-1]<5)l=b[n-1]+1; else if (b[n-1]>1)l=b[n-1]-1;
  if (l<1 || l>5){cout << -1;exit(0);}
  for (i=1;i<=n-1;i++) cout << b[i] << " ";
  cout << l;
  return 0;
}