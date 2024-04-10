#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double
#define y1 Enkognit

using namespace std;

ll n,m,i,j,k,l,a[200001];
string s,d;

int main()
{
  //freopen("backforth.in","r",stdin);
  //freopen("backforth.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n/2;i++) cin >> a[i];
  ll l=0;
  cout << 0 << " ";
  for (i=1;i<n/2;i++)
  {
   if (a[i]>a[i-1])
   {cout << max(l,a[i]-a[i-1]) << " ";l=max(l,a[i]-a[i-1]);a[i]-=l;}else
   {cout << l << " ";a[i]-=l;}
  }
  for (i=n/2-1;i>=0;i--) cout << a[i] << " ";
}