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

void solveTest() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int const INF = int(1e6);

  auto check = [&](int diam) {
    auto dfs = [&](auto&& self, int v, int p = -1) -> array<int, 2> {
      array<int, 2> dp{};
      for (int u : graph[v]) {
        if (u == p) {
          continue;
        }
        auto ch = self(self, u, v);

        array<int, 2> ndp{INF, INF};
        for (int he : {0, 1}) {
          for (int me : {0, 1}) {
            int ndiam = ch[he] + (he != me) + dp[me];
            if (ndiam <= diam) {
              smin(ndp[me], max(dp[me], ch[he] + (he != me)));
            }
          }
        }
        dp = ndp;
      }
      if (a[v] > 0) {
        dp[a[v] - 1] = INF;
      }
      return dp;
    };
    auto[x, y] = dfs(dfs, 0);
    return min(x, y) != INF;
  };
  
  int left = -1;
  int right = n;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    (check(mid) ? right : left) = mid;
  }
  cout << (right + 3) / 2 << '\n';
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