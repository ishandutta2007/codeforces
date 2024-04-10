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

const ll MOD=1e9+7;
ll n, m, k, q, l, r, a[300005], p[300005], i, j;
bool t[1000001];

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  ll t;
  cin >> t;
  while (t--)
  {
      cin >> n;
      vector <ll> v={};
      for (int i = 0; i <= n; i++) v.pb(0);
      for (int i = 0; i < n; i++)
      {
          ll x;
          cin >> x;
          v[x]++;
      }
      sort(v.begin(),v.end());
      reverse(v.begin(),v.end());
      ll ans=0, o=1e18;
      for (int i = 0; i < v.size(); i++)
          if (v[i]<o) ans+=v[i], o=v[i]; else
          {
              if (o==0) break;
              ans+=o-1;
              o--;
          }
      cout << ans << "\n";
  }
  return 0;
}