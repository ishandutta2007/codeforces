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
  vector<tuple<int, int, int>> edges(n - 1);
  DSU dsu(2 * n);

  auto add = [&](int u, int v, int p) {
    if (p == 0) {
      dsu.unite(u, v);
      dsu.unite(u + n, v + n);
    } else {
      dsu.unite(u, v + n);
      dsu.unite(u + n, v);
    }
  };

  for (int i = 0; i < n - 1; ++i) {
    int u, v, val;
    cin >> u >> v >> val;
    --u, --v;
    edges[i] = {u, v, val};
    if (val >= 0) {
      add(u, v, __builtin_parity(val));
    }
  }

  while (m--) {
    int u, v, p;
    cin >> u >> v >> p;
    --u, --v;
    add(u, v, p);
  }

  for (int v = 0; v < n; ++v) {
    if (dsu.same(v, v + n)) {
      cout << "NO\n";
      return;
    }
  }

  auto f = [&](int v) {
    return dsu.find(v) < dsu.find(v + n);
  };

  cout << "YES\n";
  for (auto [u, v, val] : edges) {
    if (val < 0) {
      val = f(u) ^ f(v);
    }
    cout << u + 1 << ' ' << v + 1 << ' ' << val << '\n';
  }
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