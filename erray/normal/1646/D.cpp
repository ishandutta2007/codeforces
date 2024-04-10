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

  if (N == 2) {
    cout << "2 2\n1 1\n";
    return 0;
  }

  debug(g);
  vector<int> dp(N);
  vector<int> sum(N);
  vector<bool> use(N);
  function<void(int)> Dfs = [&](int v) {
    int ign = 0;
    int ign_sum = 0;
    int t = 1;
    int t_sum = deg[v];
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      Dfs(u);
      for (auto nu : g[u]) {
        t += dp[nu];
        t_sum += sum[nu];
      }
      ign += dp[u];
      ign_sum += sum[u];
    }
    if (pair{t, -t_sum} < pair{ign, -ign_sum}) {
      use[v] = false;
      dp[v] = ign;
      sum[v] = ign_sum;
    } else {
      use[v] = true;
      dp[v] = t;
      sum[v] = t_sum;
    }
  };
  Dfs(0);
  debug(use);
  debug(dp);
  vector<bool> take(N);
  function<void(int)> Cons = [&](int v) {
    if (use[v]) {
      take[v] = true;
      for (auto u : g[v]) {
        for (auto nu : g[u]) {
          Cons(nu);
        }
      }  
    } else {
      for (auto u : g[v]) {
        Cons(u);
      }
    }
  };
  Cons(0);

  cout << dp[0] << ' ' << sum[0] + (N - dp[0]) << '\n';
  for (int i = 0; i < N; ++i) {
    cout << (take[i] ? deg[i] : 1) << ' ';
  }
}