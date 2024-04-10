#include <iostream>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef gp_hash_table <int, int> ht;

int ans = -1;
vector <ht> dp;
vi d, arr;
vvi g;

void dfs(int v, int p = -1) {
  for (int u : g[v])
    if (u != p) {
      d[u] = d[v] + 1;
      dfs(u, v);
    }
}

void solve(int v, int p = -1) {
  for (int u : g[v])
    if (u != p) {
      solve(u, v);
      for (auto &now : dp[u]) {
        if (arr[v] % now.first)
          continue;
        ans = max(ans, dp[u][now.first] + dp[v][now.first] - 2 * d[v]);
      }
      for (auto &now : dp[u]) {
        if (arr[v] % now.first)
          continue;
        dp[v][now.first] = max(dp[v][now.first], now.second);
      }
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > 1)
      ans = 0;
  }
  vi a = arr;
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  d.resize(n);
  dfs(0);
  dp.resize(n);
  for (int v = 0; v < n; v++) {
    for (int j = 2; j * j <= a[v]; j++) {
      if (a[v] % j)
        continue;
      while (a[v] % j == 0)
        a[v] /= j;
      dp[v][j] = d[v];
    }
    if (a[v] > 1)
      dp[v][a[v]] = d[v];
  }
  solve(0);
  cout << ans + 1;
  return 0;
}