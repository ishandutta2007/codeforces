#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

void dfs(ll v, ll &cnt, vector <bool> &used, vector <vector <ll>> &g) {
  cnt++;
  used[v] = true;
  for (ll u : g[v])
    if (!used[u])
      dfs(u, cnt, used, g);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector <vector <ll>> g(n);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    if (u == 0 || v == 0) continue;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <bool> used(n);
  vector <ll> a;
  for (ll i = 1; i < n; i++)
    if (!used[i]) {
      ll cnt = 0;
      dfs(i, cnt, used, g);
      a.push_back(cnt + 1);
    }
  ll k = a.size();
  ll ans = 0;
  vector <ll> answer(k);
  vector <ll> ansforsz(n + 1, -1);
  for (ll it = 1; it <= k; it++) {
    if (ansforsz[a[it - 1]] != -1) {
      answer[it - 1] = ansforsz[a[it - 1]];
      continue;
    }
    vector <vector <ll>> dp(k + 1, vector <ll>(2 * n + 1));
    dp[0][n] = 1;
    for (ll i = 1; i <= k; i++) {
      ll x = a[i - 1];
      dp[i] = dp[i - 1];
      for (ll j = 0; j <= 2 * n; j++) {
        dp[i][j] = dp[i - 1][j];
        if (i == it) continue;
        if (j - x >= 0)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
        if (j + x <= 2 * n)
          dp[i][j] = (dp[i][j] + dp[i - 1][j + x]) % MOD;
      }
    }
    ll sum = 0;
    for (ll i = n - a[it - 1] + 2; i <= n + a[it - 1] - 2; i++)
      sum = (sum + 2 * dp[k][i]) % MOD;
    dp.assign(k + 1, vector<ll>(2 * n + 1, 0));
    dp[0][n] = 1;
    for (ll i = 1; i <= k; i++) {
      ll x = a[i - 1];
      if (i == it) {
        dp[i] = dp[i - 1];
        continue;
      }
      for (ll j = 0; j <= 2 * n; j++) {
        if (j - x >= 0)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
        if (j + x <= 2 * n)
          dp[i][j] = (dp[i][j] + dp[i - 1][j + x]) % MOD;
      }
    }
    sum = (sum + 2 * (dp[k][n - a[it - 1] + 1] + dp[k][n + a[it - 1] - 1])) % MOD;
    answer[it - 1] = ansforsz[a[it - 1]] = sum;
  }
  vector <vector <ll>> dp(k + 1, vector <ll>(2 * n + 1));
  dp[0][n] = 1;
  for (ll i = 1; i <= k; i++) {
    ll x = a[i - 1];
    for (ll j = 0; j <= 2 * n; j++) {
      if (j - x >= 0)
        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
      if (j + x <= 2 * n)
        dp[i][j] = (dp[i][j] + dp[i - 1][j + x]) % MOD;
    }
  }
  ll s = dp[k][n];
  if (s < 0)
    s += MOD;
  for (auto &now : answer)
    s = (s + now) % MOD;
  cout << s;
  return 0;
}