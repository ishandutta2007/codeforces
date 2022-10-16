//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<bool> alive(n, true);
  vector<pair<int, int>> ans;

  auto add_edge = [&](int u, int v) {
    if (u == v) return;
    if (u > v) swap(u, v);
    ans.emplace_back(u, v);
  };

  vector<int> sz(n);
  auto solve = [&](auto&& solve, int root) -> void {
    auto calc_sz = [&](auto&& calc_sz, int v, int par = -1) -> void {
      sz[v] = 1;
      for (int u : graph[v]) {
        if (alive[u] && u != par) {
          calc_sz(calc_sz, u, v);
          sz[v] += sz[u];
        }
      }
    };
    auto find_centroid = [&](int v, int size, int r) {
      int par = -1;
      while (true) {
        bool found = false;
        for (int u : graph[v]) {
          if (!alive[u] || u == par) continue;
          if (sz[u] > size / r) {
            par = v;
            v = u;
            found = true;
            break;
          }
        }
        if (!found) return make_pair(v, par);
      }
    };
    calc_sz(calc_sz, root);
    auto first = find_centroid(root, sz[root], 3);
    auto c = first.first;
    auto par_c = first.second;
    auto go_down = [&](auto&& go_down, int v, int to1, int to2 = -1,
        int par = -1) -> void {
      add_edge(v, to1);
      if (to2 >= 0) {
        add_edge(v, to2);
      }
      for (int u : graph[v]) {
        if (alive[u] && u != par) {
          go_down(go_down, u, to1, to2, v);
        }
      }
    };
    go_down(go_down, c, c, -1, par_c);
    alive[c] = false;
    for (int u : graph[c]) {
      if (alive[u] && u != par_c) {
        solve(solve, u);
      }
    }
    int first_c = c;
    if (par_c < 0) {
      return;
    }
    calc_sz(calc_sz, par_c);
    first = find_centroid(par_c, sz[par_c], 2);
    c = first.first;
    par_c = first.second;
    add_edge(c, first_c);
    for (int u : graph[c]) {
      if (u == par_c) {
        go_down(go_down, u, c, first_c, c);
      } else if (alive[u]) {
        go_down(go_down, u, c, -1, c);
      }
    }
    alive[c] = false;
    for (int u : graph[c]) {
      if (alive[u]) {
        solve(solve, u);
      }
    }
  };
  solve(solve, 0);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  cout << ans.size() << '\n';
  assert(ans.size() <= n * 10);
  for (auto[u, v] : ans) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}