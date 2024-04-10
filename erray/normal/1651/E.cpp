// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> g(N * 2);
  for (int i = 0; i < 2 * N; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }

  vector<bool> vis(N * 2);
  long long dec = 0;
  for (int s = 0; s < N; ++s) {
    if (vis[s]) {
      continue;
    }
    vector<int> a;
    function<void(int)> Dfs = [&](int v) {
      vis[v] = true;
      a.push_back(v);
      for (auto u : g[v]) {
        if (!vis[u]) {
          Dfs(u);
        }
      }
    };
    Dfs(s);
    for (auto& e : a) {
      e -= (e >= N) * N;
    }
    debug(a);
    int n = int(a.size());
    long long res = 0;
    for (int it = 0; it < n; ++it) {
      rotate(a.begin(), a.begin() + 1, a.end());
      array<int, 2> emp = {N, -1};
      array<array<int, 2>, 2> d = {emp, emp};
      auto Upd = [&](auto& x, int i) {
        x[i % 2][0] = min(x[i % 2][0], a[i]);
        x[i % 2][1] = max(x[i % 2][1], a[i]);      
      };

      auto Calc = [&](auto& x) {
        long long ret = 1;
        for (int i = 0; i < 2; ++i) {
          int l = x[i][0];
          int r = x[i][1];
          if (l > r) {
            ret *= N * (N + 1) / 2;
          } else {
            ret *= (l + 1) * (N - r);
          }  
        }
        return ret;
      };

      auto T = [&](vector<int> x) {
        auto use = d;
        for (auto e : x) {
          Upd(use, e);
        }
        return Calc(use);
      };

      for (int i = 0; i < n; ++i) {
        Upd(d, i);
        if (i % 2 == 0) {
          long long r = T({}) - T({i + 1}) - T({n - 1}) + T({i + 1, n - 1});
          debug(a, i, d, r);
          res += r;
        }
      }
    }
    dec += res;
    debug(res);
  }


  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    ans += (i + 1) * (i + 2) / 2;  
  }
  ans *= N * (N + 1);  
  debug(ans, dec);
  ans -= dec;
  cout << ans / 2 << '\n';
}