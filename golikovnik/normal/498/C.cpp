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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, vector<pair<int, int>>> fact;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    for (int p = 2; p * p <= x; ++p) {
      if (x % p == 0) {
        int d = 0;
        while (x % p == 0) {
          x /= p;
          ++d;
        }
        fact[p].emplace_back(i, d);
      }
    }
    if (x > 1) {
      fact[x].emplace_back(i, 1);
    }
  }
  vector can(n, vector<bool>(n));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    can[u][v] = can[v][u] = true;
  }
  int ans = 0;
  for (auto& [p, vc] : fact) {
    vector<int> parts[2];
    for (auto[i, d] : vc) {
      for (int j = 0; j < d; ++j) {
        parts[i % 2].push_back(i);
      }
    }
    int L = int(parts[0].size());
    int R = int(parts[1].size());
    vector<vector<int>> graph(L);
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < R; ++j) {
        if (can[parts[0][i]][parts[1][j]]) {
          graph[i].push_back(j);
        }
      }
    }
    vector<int> used(L, -1);
    vector<int> mt(R, -1);
    int tm = 0;
    auto kuhn = [&](auto&& self, int v) -> bool {
      used[v] = tm;
      for (int u : graph[v]) {
        if (mt[u] == -1 || (used[mt[u]] != tm && self(self, mt[u]))) {
          mt[u] = v;
          return true;
        }
      }
      return false;
    };
    for (int i = 0; i < L; ++i) {
      if (kuhn(kuhn, i)) {
        ++ans;
        ++tm;
      }
    }
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}