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
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  vector<set<int>> st(N);
  vector<int> p(N);
  int ans = 0;
  function<void(int, int)> Dfs = [&](int v, int pr) {
    p[v] ^= A[v];
    st[v].insert(p[v]);
    for (auto u : g[v]) {
      if (u != pr) {
        p[u] = p[v];
        Dfs(u, v);
        if (int(st[u].size()) > int(st[v].size())) {
          swap(st[v], st[u]);
        }
      }
    }
    bool bad = false;
    for (auto u : g[v]) {
      if (u != pr) {
        for (auto x : st[u]) {
          debug(x);
          bad |= st[v].count(x ^ A[v]);
        }
        for (auto x : st[u]) {
          st[v].insert(x);
        }
      }
    }
    if (bad) {
      st[v].clear();
      ans += 1;
    }
  };
  Dfs(0, -1);
  debug(p);
  cout << ans << '\n';
}