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

ll n,m,i,j,forw,k,l=0,r,o,p=0;ll a[100001],b[100001];
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
  cin >> n >> m;
  for (i=0;i<n;i++) {cin >> a[i];if (t[a[i]]==0) v.pb(a[i]);t[a[i]]++;}
  for (i=0;i<v.size();i++) r=max(r,(ll)t[v[i]]/m+(ll)(t[v[i]]%m>0));
  for (i=0;i<v.size();i++)
  {
   l+=r*m-t[v[i]];
  }
  cout << l;
  return 0;
}