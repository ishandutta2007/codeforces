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

int const N = 606;
i64 dist[N], dists[N], pref[N];
bool used[N];

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  struct edge {
    int to;
    int w;
  };
  vector<vector<edge>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  i64 const INF = i64(1e14);
  auto solve = [&](int s) {
    for (int i = 0; i < n; ++i) {
      dist[i] = INF;
      used[i] = false;
    }
    dist[s] = 0;
    for (int it = 0; it < n; ++it) {
      int from = -1;
      for (int v = 0; v < n; ++v) {
        if (!used[v] && (from < 0 || dist[v] < dist[from])) {
          from = v;
        }
      }
      assert(from >= 0);
      int rem = int(dist[from] % n);
      used[from] = true;
      for (int i = 0; i < n; ++i) {
        dists[i] = INF;
      }
      for (auto e : graph[from]) {
        int rr = rem + e.to;
        if (rr >= n) rr -= n;
        rr = -rr;
        if (rr < 0) rr += n;
        dists[rr] = e.w;
      }
      for (int i = 0; i < n; ++i) {
        pref[i] = dists[i] + i;
        if (i > 0) {
          smin(pref[i], pref[i - 1]);
        }
      }
      i64 sufMin = INF;
      for (int to = 0; to < n; ++to) {
        i64 add = INF;
        smin(add, pref[n - to - 1] + to);
        smin(add, sufMin + to);
        smin(dist[to], dist[from] + add);
        smin(sufMin, dists[n - to - 1] - to - 1);
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << dist[i] << ' ';
    }
    cout << '\n';
  };

  for (int i = 0; i < n; ++i) {
    solve(i);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}