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
ll dp[5005][3005][2];
bool t[1000001];
vector <ll> c[400005];

void dfs(ll h)
{
    t[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i]]) dfs(c[h][i]);
}

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++)
  {
      ll x, y;
      cin >> x >> y;
      y+=n;
      c[x].pb(y);
      c[y].pb(x);
  }

  ll ans=-1;

  for (int i = 1; i <= n+m; i++) if (!t[i]) ans++,dfs(i);

  cout << ans;
  return 0;
}