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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      g[X].push_back(Y);
      g[Y].push_back(X);
    }
    vector<int> d(N, -1);
    vector<int> par(N, -1);
    vector<int> c(N);
    int odd = 0;
    vector<int> ord;
    int t = -1;
    function<void(int)> Dfs = [&](int v) {
      for (auto u : g[v]) {
        if (d[u] == -1) {
          d[u] = d[v] + 1;
          par[u] = v;
          Dfs(u);
        } else if (d[u] < d[v]) {
          if (u == par[v]) {
            continue;
          }
          if ((d[u] + d[v]) % 2 == 0) {
            t = v;
            odd += 1;
            c[v] += 1;
            c[u] -= 1;
            debug("odd", v, u);
          } else {
            debug("even", v, u);
            c[v] -= 1;
            c[u] += 1; 
          }
        }
      }
      ord.push_back(v);
    };
    par[0] = -1;
    d[0] = 0;
    Dfs(0);
    debug(ord, par);

    debug(c);
    for (auto v : ord) {
      if (par[v] != -1) {
        c[par[v]] += c[v];
      }
    }
    debug(c);
    
    if (odd <= 1) {
      int flip = (t == -1 || d[t] % 2 == 0);
      cout << "YES\n";
      for (int i = 0; i < N; ++i) {
        cout << ((d[i] % 2) ^ flip);
      }
      cout << '\n';
    } else {
      int good = -1;
      if ([&] {
        for (int i = 0; i < N; ++i) {
          if (c[i] == odd) {
            good = i;
            return true;
          }
        }
        return false;
      }()) {
        cout << "YES\n";
        vector<int> flip(N);
        reverse(ord.begin(), ord.end());
        for (auto v : ord) {
          flip[v] |= (v == good);
          for (auto u : g[v]) {
            if (par[u] == v) {
              flip[u] |= flip[v];
            }
          }
        }

        bool rev = ((d[good] % 2) ^ flip[good]) == 0;
        for (int i = 0; i < N; ++i) {
          cout << ((d[i] % 2) ^ flip[i] ^ rev);
        }
        cout << '\n';
      } else {
        cout << "NO\n";
      }
    }
  }
}