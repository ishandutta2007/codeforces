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
    int N, K;
    cin >> N >> K;
    vector<int> P(N, -1);
    vector<vector<int>> g(N);
    for (int i = 1; i < N; ++i) {
      cin >> P[i];
      --P[i];
      g[P[i]].push_back(i);
    }
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
    }
    vector<vector<long long>> dp(N, vector<long long>(2));
    function<void(int, int)> Dfs = [&](int v, int c) {
      int s = int(g[v].size());
      dp[v][0] = 1LL * S[v] * c;
      dp[v][1] = S[v];
      for (auto u : g[v]) {
        Dfs(u, c / s);
        dp[v][0] += dp[u][0];
      }
      if (s > 0) {
        sort(g[v].begin(), g[v].end(), [&](int x, int y) {
          return dp[x][1] > dp[y][1];
        });
        for (int i = 0; i < c % s; ++i) {
          dp[v][0] += dp[g[v][i]][1];
        }
        int next = g[v][c % s];
        dp[v][1] += dp[next][1];
      }
    };
    Dfs(0, K);
    cout << dp[0][0] << '\n';
  }
}