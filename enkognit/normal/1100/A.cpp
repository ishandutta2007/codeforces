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

ll n,m,i,j,k,l,a[200001];
string s;

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> k;
  ll r1=0,r2=0;
  for (int i = 1; i <= n; i++) {cin >> a[i];if (a[i]==1)r1++; else r2++;}
  for (int i = 1; i <= n;  i++)
  {
      ll p=i%k;
      ll s1=0,s2=0;
      if (p==0) p=k;
      for (int j = p; j <= n; j+=k)
        if (a[j]==1)s1+=a[j]; else s2-=a[j];
      l=max(l,abs(r1-s1-r2+s2));
  }
  cout << l;
  return 0;
}