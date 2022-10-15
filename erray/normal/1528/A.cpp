// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    
    vector<vector<long long>> dp(n, vector<long long>(2));
    function<void(int, int)> Dfs = [&](int v, int pr) {
      for (auto u : g[v]) {
        if (u == pr) {
          continue;
        }
        Dfs(u, v);
        dp[v][0] += max(dp[u][0] + abs(l[v] - l[u]), dp[u][1] + abs(l[v] - r[u]));
        dp[v][1] += max(dp[u][0] + abs(r[v] - l[u]), dp[u][1] + abs(r[v] - r[u]));
      }
    };
    Dfs(0, -1);
    cout << max(dp[0][1], dp[0][0]) << '\n';
  }
}