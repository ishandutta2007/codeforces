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

ll n,m,i,j,k,x,y,z,l[10001],r[10001],b[10001];
ll a[10001];

int main()
{
  //freopen("forest.in","r",stdin);
  //freopen("forest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) {cin >> l[i];if (l[i]>i-1) {cout << "NO\n";exit(0);}}
  for (i=1;i<=n;i++) {cin >> r[i];if (r[i]>n-i) {cout << "NO\n";exit(0);}}
  for (i=1;i<=n;i++) {if (l[i]+r[i]>=n) {cout << "NO";exit(0);}a[i]=n-l[i]-r[i];}
  for (i=1;i<=n;i++)
  {
   ll o=0,u=0;
   for (j=i-1;j>0;j--) o+=(a[i]<a[j]);
   for (j=i+1;j<=n;j++) u+=(a[i]<a[j]);
   if (o!=l[i] || u!=r[i]) {cout << "NO";exit(0);}
  }
  cout << "YES\n";
  for (i=1;i<=n;i++) cout << a[i] << " ";
  return 0;
}