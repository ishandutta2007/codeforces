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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    for (int i = 0; i < N - 1; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      g[X].push_back(Y);
      g[Y].push_back(X);
    }
    vector<int> d(N);
    vector<int> mx(N, -1);
    vector<int> mx_2(N, -1);
    vector<int> next(N, -1);
    vector<int> par(N, -1);
    function<void(int)> Dfs = [&](int v) {
      for (auto u : g[v]) {
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        d[u] = d[v] + 1;
        par[u] = v;
        Dfs(u);
        if (mx[u] > mx[v]) {
          next[v] = u;
          mx[v] = mx[u];
        }
      }
      if (mx[v] == -1) {
        mx[v] = d[v];
      }
      for (auto u : g[v]) {
        if (next[v] != u) {
          mx_2[v] = max(mx_2[v], mx[u]);
        }
      }
      if (mx_2[v] == -1) {
        mx_2[v] = d[v];
      }
    };
    Dfs(0);
    debug(mx_2);
    debug(mx);
    vector<int> chain;
    {
      int v = 0;
      while (v != -1) {
        chain.push_back(v);
        v = next[v]; 
      }
    }

    debug(chain);
    
    int size = int(chain.size());
    vector<int> pref(size + 1);
    for (int i = 0; i < size; ++i) {
      pref[i + 1] = max(pref[i], mx_2[chain[i]]);
    }

    vector<int> suf(size + 1, -int(1e9));
    for (int i = 0; i < size; ++i) {
      suf[i] = max(suf[i + 1], mx_2[chain[i]] - 2 * i);
    }
    int max_depth = size - 1;
    vector<int> ans(N + 1);
    int p = size - 1;
    int v = size - 1;
    const int inf = int(1e9);
    int ms = -inf;    
    for (int c = N; c >= 1; --c) {
      auto Up = [&] {
        if (p != 0 && p - 1 >= (v - p + c + 1)) {
          //insert
          --p;
        }
      };
      Up();
      auto Get = [&] {
        int delta = v - c;
        //-delta + depth
        return max({max_depth - delta, pref[p], suf[p] + v + c});
      };

      if (v - 1 > c) {
        int start = Get();
        --v;
        int old_p = p;
        Up();
        if (Get() > start) {
          p = old_p;
          v += 1;
        } 
      }
      debug(c, v, p, ms, pref[p], "delta", v - c);
      ans[c] = min(max_depth, Get());
    }
    for (int i = 1; i <= N; ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}