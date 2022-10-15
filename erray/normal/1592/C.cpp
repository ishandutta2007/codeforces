// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      tot ^= a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<array<bool, 3>> dp(n, {false, false, false});
    vector<int> X = a;
    function<void(int)> Dfs = [&](int v) {
      for (auto u : g[v]) {
        g[u].erase(find(g[u].begin(), g[u].end(), v));
        Dfs(u);
        X[v] ^= X[u];
      }
      
      {
        int cnt = 0;
        int from = 0;
        for (auto u : g[v]) {
          cnt += dp[u][1];
          from += (X[u] == tot);
          if ((X[u] == 0 && dp[u][1]) || dp[u][2]) {
            dp[v][2] = true;
          }
          dp[v][2] |= (from + cnt > 1);
        }
      }
      {
        for (auto u : g[v]) {
          if (X[u] == tot || dp[u][1]) {
            dp[v][1] = true;
          }
        }
      }
      dp[v][0] = true;
    }; 
    Dfs(0);
    cout << (tot == 0 || (k > 2 && dp[0][2]) ? "YES" : "NO") << '\n';
  }
}