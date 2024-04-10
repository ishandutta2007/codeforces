//  Copyright 2021 Nikita Golikov

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

  while (true) {
    int n, npaths;
    cin >> n >> npaths;
    if (n == 0) break;
    struct edge {
      int to;
      int id;
    };
    vector<vector<edge>> graph(n);
    int m = 0;
    for (int i = 0; i < npaths; ++i) {
      int cnt;
      cin >> cnt;
      int prev;
      cin >> prev;
      --prev;
      --cnt;
      while (cnt--) {
        int nxt;
        cin >> nxt;
        --nxt;
        graph[prev].push_back({nxt, m});
        graph[nxt].push_back({prev, m++});
        prev = nxt;
      }
    }
    vector<int> bad(m);
    {
      vector<bool> used(n);
      vector<edge> par(n);
      vector<int> dep(n);
      auto dfs = [&](auto&& dfs, int v, int p = -1) -> void {
        used[v] = true;
        for (auto e : graph[v]) {
          if (e.to == p) continue;
          if (!used[e.to]) {
            dep[e.to] = dep[v] + 1;
            par[e.to] = {v, e.id};
            dfs(dfs, e.to, v);
            continue;
          }
          if (dep[e.to] < dep[v]) {
            bad[e.id] = true;
            int cur = v;
            while (cur != e.to) {
              bad[par[cur].id] = true;
              cur = par[cur].to;
            }
          }
        }
      };
      for (int i = 0; i < n; ++i) if (!used[i]) dfs(dfs, i);
    }
    vector<int> deg(n);
    for (int v = 0; v < n; ++v) {
      for (auto e : graph[v]) {
        if (!bad[e.id]) {
          deg[v] ^= 1;
        }
      }
    }
    {
      vector<bool> used(n);
      vector<bool> dead(n);
      auto dfs = [&](auto&& dfs, int v, int p = -1) -> void {
        used[v] = true;
        for (auto e : graph[v]) {
          if (!bad[e.id]) {
            auto u = e.to;
            if (u == p) continue;
            dfs(dfs, u, v);
            if (!dead[v] && !dead[u] && deg[u] && deg[v]) {
              dead[u] = dead[v] = true;
              deg[u] ^= 1;
              deg[v] ^= 1;
              bad[e.id] = true;
            }
          }
        }
      };
      for (int i = 0; i < n; ++i) if (!used[i]) dfs(dfs, i);
    }
    vector<pair<int, int>> ans;
    vector<bool> used(n);
    auto dfs = [&](auto&& dfs, int v, int p = -1) -> int {
      used[v] = true;
      int myPath = deg[v] ? v : -1;
      for (auto e : graph[v]) {
        if (bad[e.id]) continue;
        auto u = e.to;
        if (u == p) continue;
        auto hisPath = dfs(dfs, u, v);
        if (hisPath >= 0) {
          if (myPath >= 0) {
            ans.emplace_back(myPath, hisPath);
            myPath = -1;
          } else {
            myPath = hisPath;
          }
        }
      }
      return myPath;
    };
    for (int i = 0; i < n; ++i) if (!used[i] && !deg[i]) dfs(dfs, i);
    cout << ans.size() << '\n';
    for (auto[u, v] : ans) cout << u + 1 << ' ' << v + 1 << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}