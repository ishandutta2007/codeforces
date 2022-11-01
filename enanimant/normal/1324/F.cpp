// March 21, 2020
// https://codeforces.com/problemset/problem/1324/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      a[i] = -1;
    }
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> dp(n);
  function<void(int, int)> dfs = [&](int v, int p) {
    dp[v] = a[v];
    for (int u : g[v]) {
      if (u == p) {
        continue;
      }
      dfs(u, v);
      dp[v] += max(dp[u], 0);
    }
  };
  dfs(0, -1);
  vector<int> ans(n);
  function<void(int, int)> dfs2 = [&](int v, int p) {
    ans[v] = dp[v];
    for (int u : g[v]) {
      if (u == p) {
        continue;
      }
      dp[v] -= max(dp[u], 0);
      dp[u] += max(dp[v], 0);
      dfs2(u, v);
      dp[u] -= max(dp[v], 0);
      dp[v] += max(dp[u], 0);
    }
  };
  dfs2(0, -1);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << '\n';


  return 0;
}