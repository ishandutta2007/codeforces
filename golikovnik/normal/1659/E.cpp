//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

struct DSU {
  int n;
  vector<int> dsu;

  DSU(int n_) : n(n_), dsu(n, -1) {}

  int find(int v) {
    return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (-dsu[u] > -dsu[v]) swap(u, v);
    dsu[v] += dsu[u];
    dsu[u] = v;
    return true;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  int size(int v) {
    return -dsu[find(v)];
  }

  void clear() {
    fill(dsu.begin(), dsu.end(), -1);
  }
};

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
  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
    edges[i] = {u, v, w};
  }

  int const B = 30;
  vector compId(B, vector<int>(n));

  for (int b = 0; b < B; ++b) {
    DSU dsu(n);
    for (auto[u, v, w] : edges) {
      if (w >> b & 1) {
        dsu.unite(u, v);
      }
    }
    for (int i = 0; i < n; ++i) {
      compId[b][i] = dsu.find(i);
    }
  }

  vector<bool> goodStart(n);
  for (int b = 1; b < B; ++b) {
    DSU dsu(n);
    for (auto[u, v, w] : edges) {
      if (w & 1) {
        if (w >> b & 1) {
          dsu.unite(u, v);
        }
      }
    }
    vector<bool> goodComp(n);
    for (int i = 0; i < n; ++i) {
      int id = dsu.find(i);
      for (auto[j, w] : graph[i]) {
        if (!(w & 1)) {
          goodComp[id] = true;
        }
      }
    }
    for (int v = 0; v < n; ++v) {
      if (goodComp[dsu.find(v)]) {
        goodStart[v] = true;
      }
    }
  }

  int q; cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    bool zero = false;
    for (int b = 0; b < B; ++b) {
      if (compId[b][u] == compId[b][v]) {
        zero = true;
      }
    }
    if (zero) {
      cout << 0 << '\n';
    } else {
      cout << 2 - goodStart[u] << '\n';
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}