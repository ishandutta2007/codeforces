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

ll n,k,m,i,x,l;ll a[100001];
string s;

int main()
{
  //freopen("advert.in","r",stdin);
  //freopen("advert.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
  }
  for (i=1;i<n-1;i++)
  {
   if (a[i-1]==a[i+1] && a[i]==0 && a[i-1]==1) k++,a[i+1]=0;
  }
  cout << k;
  return 0;
}