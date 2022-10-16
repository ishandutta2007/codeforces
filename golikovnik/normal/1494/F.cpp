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

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].emplace_back(v, i);
    graph[v].emplace_back(u, i);
    deg[u]++;
    deg[v]++;
  }

  vector<bool> dead(m);
  vector<int> ptr(n);
  int nalive = m;
  auto euler = [&](int root) -> vector<pair<int, int>> {
      vector<pair<int, int>> pathE;
      auto rec = [&](auto&& rec, int v) -> void {
        for (; ptr[v] != (int) graph[v].size(); ) {
          auto[u, id] = graph[v][ptr[v]++];
          if (dead[id]) {
            continue;
          }
          dead[id] = true;
          rec(rec, u);
          pathE.emplace_back(u, v);
          //  add edge v -> u, id to back of the path
        }
      };
      rec(rec, root);
      for (int i = 0; i + 1 < int(pathE.size()); ++i) {
        if (pathE[i].second != pathE[i + 1].first) return {};
      }
      if (!pathE.empty() && pathE.back().second != root) return {};
      if (int(pathE.size()) != nalive) return {};
      return pathE;
  };

  for (int v = 0; v < n; ++v) {
    vector<pair<int, int>> oddNeighbors;
    for (auto[u, i] : graph[v]) {
      if (deg[u] % 2) {
        oddNeighbors.emplace_back(u, i);
      }
    }
    int ne = int(oddNeighbors.size());
    for (int u = -1; u < ne; ++u) {
      for (int i = 0; i < ne; ++i) {
        auto[who, id] = oddNeighbors[i];
        if (who == u) continue;
        nalive--;
        dead[id] = true;
      }
      auto pathE = euler(v);
      if (nalive == 0 || !pathE.empty()) {
        vector<int> path;
        if (pathE.empty()) {
          path.push_back(v);
        } else {
          path.push_back(pathE[0].first);
        }
        for (auto p : pathE) path.push_back(p.second);
        path.push_back(-2);
        for (int i = 0; i < ne; ++i) {
          auto[who, id] = oddNeighbors[i];
          if (who == u) continue;
          path.push_back(who);
          path.push_back(v);
        }
        cout << path.size() << '\n';
        for (auto curV : path) cout << curV + 1 << ' ';
        cout << '\n';
        return 0;
      }
      nalive = m;
      fill(dead.begin(), dead.end(), false);
      fill(ptr.begin(), ptr.end(), 0);
    }
  }
  cout << 0 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}