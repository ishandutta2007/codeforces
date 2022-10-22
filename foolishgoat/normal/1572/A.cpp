#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  vector<int> din(n, 0);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    din[i] = k;
    for (int j = 0; j < k; ++j) {
      int u;
      cin >> u;
      --u;
      g[u].push_back(i);
    }
  }
  vector<int> topo;
  vector<int> dp(n, 1);
  for (int i = 0; i < n; ++i) {
    if (din[i] == 0) {
      topo.push_back(i);
    }
  }
  for (int i = 0; i < (int)topo.size(); ++i) {
    int v = topo[i];
    for (int u : g[v]) {
      --din[u];
      dp[u] = max(dp[u], dp[v] + (u < v));
      if (din[u] == 0) {
        topo.push_back(u);
      }
    }
  }
  if ((int)topo.size() != n)
    cout << "-1\n";
  else {
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}