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

void solve(int) {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [l, r] : a) {
    cin >> l >> r;
  }
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  auto f = [](i64 x, i64 y) -> i64 {
    return abs(x - y);
  };
  auto dfs = [&](auto&& dfs, int v, int p = -1) -> pair<i64, i64> {
    i64 c0 = 0;
    i64 c1 = 0;
    for (int u : graph[v]) {
      if (u == p) continue;
      auto[u0, u1] = dfs(dfs, u, v);
      c0 += max(u0 + f(a[u].first, a[v].first), u1 + f(a[u].second, a[v].first));
      c1 += max(u0 + f(a[u].first, a[v].second), u1 + f(a[u].second, a[v].second));
    }
    return make_pair(c0, c1);
  };
  auto[c0, c1] = dfs(dfs, 0);
  cout << max(c0, c1) << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}