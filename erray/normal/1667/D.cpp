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
    vector<int> deg(N);      
    for (int i = 0; i < N - 1; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X, --Y;
      deg[X] += 1;
      deg[Y] += 1;
      g[X].push_back(Y);
      g[Y].push_back(X);
    }

    vector<int> dp(N);
    vector<array<array<vector<int>, 2>, 2>> aux(N);
    function<void(int)> Dfs = [&](int v) {
      array<vector<int>, 3> c = {};
      for (auto u : g[v]) {
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        Dfs(u);
        if (dp[u] == 0) {
          return;
        }
        c[dp[u] - 1].push_back(u);
      }
      debug(v, c);

      for (int p = 0; p < 2; ++p) {
        int need = (deg[v] + 1) / 2;
        if (v != 0) {
          need -= p;
        }
        int l = int(c[1].size());
        int s = int(c[2].size());
        if (need >= l && need <= l + s) {
          dp[v] |= 1 << p;
          aux[v][p][0] = c[0];
          aux[v][p][1] = c[1];
          for (auto e : c[2]) {
            aux[v][p][need > 0].push_back(e);
            --need;
          }
        }
      }
    };
    Dfs(0);
    debug(dp);
    debug(aux);
    if (dp[0]) {
      cout << "YES\n";
      vector<array<int, 2>> ans;
      vector<int> id(N);
      function<void(int)> F = [&](int v) {
        for (int j = 0; j < 2; ++j) {
          for (auto u : aux[v][id[v]][j]) {
            id[u] = j;
          }
        }
        for (auto u : g[v]) {
          F(u);
        }
      };
      F(0);
      debug(id);
      function<void(int, int)> Gen = [&](int v, int type) {
        bool used = false;
        debug(v, type);
        while (type ? !used : deg[v] > 0) {
          int b = deg[v] % 2;
          auto& a = aux[v][id[v]][b];
          assert(!a.empty());
          int u = a.back();
          a.pop_back();
          if ((deg[v] + deg[u]) % 2 != 0) {
            Gen(u, 1);
          }
          ans.push_back({v, u});
          --deg[u];
          --deg[v];
          Gen(u, 0);          
          used = true;
        }
      };
      Gen(0, 0);
      for (auto[v, u] : ans) {
        cout << v + 1 << ' ' << u + 1 << '\n';
      }
    } else {
      cout << "NO\n";
    }
  }
}