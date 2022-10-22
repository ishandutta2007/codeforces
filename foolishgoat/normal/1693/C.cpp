#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;

vector<int> dp, cnt, din;

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  const int inf = 1e9 + 7;
  dp.assign(n, inf);
  cnt.assign(n, 0);
  din.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ++din[u];
    g[v].push_back(u);
  }
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, n-1);
  dp[n-1] = 0;
  while (!pq.empty()) {
    int v = pq.top().second, w = -pq.top().first;
    pq.pop();
    if (dp[v] != w) {
      continue;
    }
    for (int u : g[v]) {
      ++cnt[u];
      int ndp = dp[v] + 1 + din[u] - cnt[u];
      if (dp[u] > ndp) {
        dp[u] = ndp;
        pq.emplace(-ndp, u);
      }
    }
  }
  cout << dp[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}