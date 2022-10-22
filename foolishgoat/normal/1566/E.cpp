#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> state;

int dfs(int v, int par = -1) {
  int ret = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    ret += dfs(u, v);
    if (state[u] == 0) {
      if (state[v] == 0) {
        state[v] = 1;
      }
    } else if (state[u] == 1) {
    } else {
      state[v] = 2;
    }
  }
  if (state[v] == 0)
    ++ret;
  else if (state[v] == 1 && v > 0)
    --ret;
  return ret;
}

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  state.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int ans = dfs(0);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    solve();
  }
  return 0;
}