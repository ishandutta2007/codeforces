/*
 * author:  ADMathNoob
 * created: 10/15/22 10:35:12
 * problem: https://codeforces.com/contest/1746/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      --p;
      g[p].push_back(i);
    }
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<map<int, long long>> dp(n);
    function<long long(int, int)> Dfs = [&](int v, int cov) -> long long {
      // for all v, this can only ever be called with two possible values of cov
      {
        auto it = dp[v].find(cov);
        if (it != dp[v].end()) {
          return it->second;
        }
      }
      if (g[v].empty()) {
        return dp[v][cov] = cov * s[v];
      }
      int children = g[v].size();
      if (cov % children == 0) {
        long long ret = cov * s[v];
        for (int u : g[v]) {
          ret += Dfs(u, cov / children);
        }
        return dp[v][cov] = ret;
      }
      int small = cov / children;
      int large = small + 1;
      int cnt_large = cov % children;
      for (int u : g[v]) {
        Dfs(u, small);
        Dfs(u, large);
      }
      sort(g[v].begin(), g[v].end(), [&](int i, int j) {
        return dp[i][large] - dp[i][small] > dp[j][large] - dp[j][small];
      });
      long long ret = cov * s[v];
      for (int j = 0; j < cnt_large; j++) {
        ret += dp[g[v][j]][large];
      }
      for (int j = cnt_large; j < children; j++) {
        ret += dp[g[v][j]][small];
      }
      return dp[v][cov] = ret;
    };
    cout << Dfs(0, k) << '\n';
  }
  return 0;
}