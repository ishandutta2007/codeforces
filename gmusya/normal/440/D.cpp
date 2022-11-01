#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <int> from;
vector <vector <int>> dp;
vector <vector <pair <int, int>>> g;
vector <vector <vector <pair <int, int>>>> p;

void dfs(int v, int par) {
  for (int i = 1; i <= k; i++)
    dp[v][i] = n;
  dp[v][1] = 0;
  for (auto &now : g[v]) {
    int u = now.first, w = now.second;
    if (u == par)
      continue;
    from[u] = w;
    dfs(u, v);
    for (int i = k; i >= 1; i--) {
      dp[v][i]++;
      int tmp = 0;
      for (int j = 1; j < i; j++)
        if (dp[v][i - j] + dp[u][j] < dp[v][i])
          dp[v][i] = dp[v][i - j] + dp[u][j], tmp = j;
      p[v][i] = p[v][i - tmp];
      p[v][i].push_back({u, tmp});
    }
  }
}

void recovery(int v, int i) {
  for (auto &now : p[v][i]) {
    if (now.second)
      recovery(now.first, now.second);
    else
      cout << from[now.first] << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  g.resize(n);
  from.resize(n);
  dp.resize(n, vector <int>(k + 1));
  p.resize(n, vector <vector <pair <int, int>>>(k + 1));
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  dfs(0, -1);
  int ans = dp[0][k], id = 0;
  for (int i = 1; i < n; i++)
    if (dp[i][k] + 1 < ans) {
      ans = dp[i][k] + 1;
      id = i;
    }
  cout << ans << '\n';
  if (id != 0)
    cout << from[id] << ' ';
  recovery(id, k);
  return 0;
}