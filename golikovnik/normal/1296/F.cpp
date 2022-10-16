#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  int const INF = (int) 1e6;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    graph[v].emplace_back(u, i - 1);
    graph[u].emplace_back(v, i - 1);
  }
  vector<int> p(n), tin(n), tout(n), id(n, -1);
  int timer = 0;
  function<void(int, int)> dfs = [&](int v, int par) {
    p[v] = par;
    tin[v] = timer++;
    for (auto[u, i] : graph[v]) {
      if (u != par) {
        dfs(u, v);
        id[u] = i;
      }
    }
    tout[v] = timer;
  };
  dfs(0, 0);
  auto anc = [&](int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
  };
  vector<int> val(n - 1, INF);
  int m;
  cin >> m;
  vector<tuple<int, int, int>> q(m);
  for (auto&[v, u, x] : q) {
    cin >> v >> u >> x;
    --v, --u;
  }
  sort(q.begin(), q.end(), [](auto& x, auto& y) {
    return get<2>(x) < get<2>(y);
  });
  auto go_up = [&](int v, int u, auto& f) {
    while (!anc(v, u)) {
      f(id[v]);
      v = p[v];
    }
  };
  for (auto[u, v, x] : q) {
    auto f = [&](int i) {
      val[i] = x;
    };
    go_up(u, v, f);
    go_up(v, u, f);
  }
  bool ok = true;
  for (auto[u, v, x] : q) {
    auto mn = INF;
    auto f = [&](int i) {
      mn = min(mn, val[i]);
    };
    go_up(u, v, f);
    go_up(v, u, f);
    ok &= mn == x; 
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  for (auto x : val) {
    cout << x << ' ';
  }
  cout << '\n';
}