#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, s;
  cin >> n >> m >> s;
  --s;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }
  i64 const INF = numeric_limits<i64>::max() / 2;
  vector<i64> d(n, INF);
  d[s] = 0;
  set<pair<i64, int>> st;
  st.emplace(0, s);
  vector<vector<int>> in_edges(n);
  vector<int> ts;
  while (!st.empty()) {
    auto[dst, v] = *st.begin();
    st.erase(st.begin());
    ts.push_back(v);
    for (auto[u, w] : graph[v]) {
      auto new_dist = dst + w;
      if (new_dist < d[u]) {
        in_edges[u].clear();
        in_edges[u].push_back(v);
        st.erase({d[u], u});
        d[u] = new_dist;
        st.emplace(d[u], u);
      } else if (new_dist == d[u]) {
        in_edges[u].push_back(v);
      }
    }
  }
  
  int const LOG = 18;
  vector<vector<int>> up(n, vector<int>(LOG, -1));
  fill(up[s].begin(), up[s].end(), s);
  vector<int> depth(n);
  ts.erase(ts.begin());
  
  auto lca = [&](int v, int u) {
    auto dv = depth[v];
    auto du = depth[u];
    if (dv < du) {
      swap(u, v);
      swap(du, dv);
    }
    auto dlt = dv - du;
    for (int k = 0; dlt; k++, dlt /= 2) {
      if (dlt & 1) {
        v = up[v][k];
      }
    }
    if (v == u) {
      return v;
    }
    for (int k = LOG - 1; k >= 0; --k) {
      auto pv = up[v][k];
      auto pu = up[u][k];
      if (pv != pu) {
        v = pv;
        u = pu;
      }
    }
    return up[v][0];
  };
  auto add = [&](int v, int p) {
    depth[v] = depth[p] + 1;
    up[v][0] = p;
    for (int k = 0; k + 1 < LOG; ++k) {
      up[v][k + 1] = up[up[v][k]][k];
    }
  };
  for (int i : ts) {
    int par = -1;
    for (int j : in_edges[i]) {
      if (par < 0) {
        par = j;
        continue;
      }
      par = lca(par, j);
    }
    assert(par >= 0);
    add(i, par);
  }
  vector<int> sz(n, 1);
  reverse(ts.begin(), ts.end());
  int ans = 0;
  for (int i : ts) {
    auto par = up[i][0];
    ans = max(ans, sz[i]);
    sz[par] += sz[i];
  }
  cout << ans << '\n';
  return 0;
}