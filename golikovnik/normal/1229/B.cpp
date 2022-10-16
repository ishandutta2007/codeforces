#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<i64> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans = 0;
  int const MOD = (int) 1e9 + 7;
  function<void(int, int, vector<pair<i64, int>>)> dfs = [&](int v, int p,
      auto const& vec) {
    vector<pair<i64, int>> my_vec{{a[v], 1}};
    for (auto[g, len] : vec) {
      auto[prev_g, prev_len] = my_vec.back();
      auto new_g = gcd(g, prev_g);
      if (new_g == prev_g) {
        my_vec.back().second += len;
      } else {
        my_vec.emplace_back(new_g, len);
      }
    }
    for (auto[g, len] : my_vec) {
      ans += (int) (g * len % MOD);
      if (ans >= MOD) {
        ans -= MOD;
      }
    }
    for (auto u : graph[v]) {
      if (u != p) {
        dfs(u, v, my_vec);
      }
    }
  };
  dfs(0, -1, {});
  cout << ans << '\n';
  return 0;
}