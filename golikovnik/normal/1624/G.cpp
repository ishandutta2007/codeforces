//  Copyright 2021 Nikita Golikov

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
};

void solveTest() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.emplace_back(u, v, w);
  }
  int ans = 0;
  for (int bit = 29; bit >= 0; --bit) {
    DSU dsu(n);
    vector<tuple<int, int, int>> nedges;
    for (auto[u, v, w] : edges) {
      if (!(w >> bit & 1)) {
        nedges.emplace_back(u, v, w);
        dsu.unite(u, v);
      }
    }
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      ok &= dsu.same(i, 0);
    }
    if (ok) {
      edges = nedges;
    } else {
      ans += 1 << bit;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}