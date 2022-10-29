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

ll n,k,m,i,x,l;ll a[300001];pll b[300001];
string s;
map <ll,ll> t,u;
pll v[200001];
set<pll>::iterator o;

bool comp(ll x,ll y)
{
 return t[x]>t[y];
}

int main()
{
  //freopen("advert.in","r",stdin);
  //freopen("advert.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++)
  {
   cin >> a[i];
   //if (t[a[i]]==0) b.pb(a[i]);
   t[a[i]]++;
  }
  for (i=1;i<=200000;i++) b[i-1]=mp(t[i],i);
  sort(b,b+200000);
  for (i=200000-1;i>=200000-m;i--)
  {
   v[199999-i]=mp(b[i].fi,b[i].se);
  }
  /*o=v.end();
  o--;
  while ((*o).fi*(t[(*o).se]+1)/(t[(*o).se]+2)>(*v.begin()).fi-1)
  {
   t[(*o).se]++;
   cout << (*o).se << " ";
   v.erase(v.begin());
   o--;
  }
  while (l<r)
  while (v.size()) {cout << (*v.begin()).se << " ";v.erase(v.begin());}*/
  ll l=1,r=n;
  while (l<r)
  {
   ll p=0,w=(l+r)/2+(l+r)%2;
   for (i=0;i<m;i++) p+=v[i].fi/w;
   if (p<m) r=w-1; else l=w;
  }
  ll u=0;
  for (ll i=0;i<m && u<m;i++) for (ll j=0;j<v[i].fi/l && u<m;j++){cout << v[i].se << " ";u++;}
  return 0;
}