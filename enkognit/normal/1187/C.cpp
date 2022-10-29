#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define leng length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
ll n, m, k, ans, q, l, r, i, j, a[1000005];
bool tt[1000001];
vector <pll> v1, v0;
string s, d;

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n >> m;
  //v1.pb(mp(0,0));
  for (int i = 1; i <= n; i++) a[i]=i;
  for (int i = 0; i < m; i++)
  {
      ll t, l, r;
      cin >> t >> l >> r;
      if (t) {for (int j = l; j < r; j++) tt[j]=1;}else v0.pb(mp(l,r));
  }
  //ll z=0;
  sort(v0.begin(),v0.end());

  v1.pb(mp(n+1,n+1));

  for (int i = 0; i < v0.size(); i++)
  {
      ll p=0;
      for (int j = v0[i].fi; j < v0[i].se; j++) if (!tt[j]) {p=j;}
      if (p==0) {cout << "NO\n";exit(0);}a[p]=1e8-i;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
/*for (int i = 0; i < v1.size(); i++)
  {
      while (z<v0.size() && v0[z].se<v1[i].fi) z++;
      if (z==v0.size()) break;
      if (v1[i].se>=v0[z].se && v0[z].fi>=v1[z].fi) {cout << "NO\n";exit(0);}
  }*/