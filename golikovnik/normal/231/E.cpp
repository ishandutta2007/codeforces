#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> d(n), new_id(n, -1);
  vector<bool> used(n), is_back_edge_top(n), is_single(n);
  int ei = 0;
  function<void(int, int)> dfs = [&](int v, int p) {
    used[v] = true;
    if (~p) {
      d[v] = d[p] + 1;
    }
    for (int u : graph[v]) {
      if (u == p) {
        continue;
      }
      if (!used[u]) {
        dfs(u, v);
      } else {
        if (d[u] < d[v]) {
          new_id[v] = ei++;
        } else {
          is_back_edge_top[v] = true;
        }
      }
    }
    if (~new_id[v]) {
      return;
    }
    for (int u : graph[v]) {
      if (u == p) {
        continue;
      }
      if (!is_single[new_id[u]] && !is_back_edge_top[u]) {
        new_id[v] = new_id[u];
        return;
      }
    }
    if (!~new_id[v]) {      
      is_single[new_id[v] = ei++] = true;
    }
  };
  dfs(0, -1);
  vector<vector<int>> new_graph(ei);
  for (int i = 0; i < n; ++i) {
    auto from = new_id[i];
    for (int j : graph[i]) {
      auto to = new_id[j];
      if (from == to) {
        continue;
      }
      new_graph[from].push_back(to);
    }
  }
  vector<int> cnt(ei), tin(ei), tout(ei);
  int timer = 0;
  int const LOG = 18;
  vector<vector<int>> up(ei, vector<int>(LOG));
  function<void(int, int)> dfs2 = [&](int v, int p) {
    tin[v] = timer++;
    up[v][0] = p;
    for (int k = 0; k + 1 < LOG; ++k) {
      up[v][k + 1] = up[up[v][k]][k];
    }
    cnt[v] = cnt[p] + !is_single[v];
    for (int u : new_graph[v]) {
      if (u != p) {
        dfs2(u, v);
      }
    }
    tout[v] = timer;
  };
  dfs2(0, 0);
  auto is_ancestor = [&](int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
  };
  auto lca = [&](int v, int u) {
    if (is_ancestor(v, u)) {
      return v;
    }
    for (int k = LOG - 1; k >= 0; --k) {
      auto pv = up[v][k];
      if (!is_ancestor(pv, u)) {
        v = pv;
      }
    }
    return up[v][0];
  };
  int const MOD = (int) 1e9 + 7;
  vector<int> pw(ei + 1);
  pw[0] = 1;
  for (int i = 1; i <= ei; ++i) {
    pw[i] = 2 * pw[i - 1];
    if (pw[i] >= MOD) {
      pw[i] -= MOD;
    }
  }
  auto get = [&](int from, int to) {
    auto l = lca(from, to);
    auto dst = cnt[from] + cnt[to] - cnt[l] - (l ? cnt[up[l][0]] : 0);
    return pw[dst];
  };
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << get(new_id[u - 1], new_id[v - 1]) << '\n';
  }
  return 0;
}