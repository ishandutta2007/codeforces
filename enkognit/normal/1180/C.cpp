#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r;
pll ans[500008];
vector <ll> v, z;
vector <pll> p;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
      ll x;
      cin >> x;
      v.pb(x);
  }
  reverse(v.begin(),v.end());
  for (int i = 0; i < m; i++) {ll x;cin >> x;p.pb(mp(x,i));}
  sort(p.begin(),p.end());
  bool tt=0;
  ll k=1;
  for (int i = 0; i < p.size(); i++)
  {
      while (k<p[i].fi && !tt)
      {
          k++;
          ll j=v.size()-1;
          if (v[j-1]<v[j]) swap(v[j],v[j-1]);
          z.pb(v[j]), v.erase(v.end()-1);
          if (v.size()==1) tt=1;
      }
      if (tt)
      {
          ans[p[i].se]=mp(v[0], z[(p[i].fi-k)%(n-1)]);
      } else
      ans[p[i].se]=mp(v[v.size()-1],v[v.size()-2]);
  }
  for (int i = 0; i < m; i++) cout << ans[i].fi << " " << ans[i].se << "\n";
  return 0;
}