// April 12, 2020
// https://codeforces.com/contest/1338/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 100005;

int n;
vector<int> g[N];

int children[N];
int depth[N];
int dp[N]; // maximum

void dfs(int v, int p) {
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    depth[u] = depth[v] + 1;
    children[v]++;
    dfs(u, v);
  }
}

void dfs2(int v, int p) {
  bool has_leaf_child = false;
  dp[v] = 0;
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    if (children[u] == 0) {
      has_leaf_child = true;
      continue;
    }
    dfs2(u, v);
    dp[v] += dp[u] + 1;
  }
  if (has_leaf_child) {
    dp[v]++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int x = 0;
  while ((int) g[x].size() == 1) {
    x++; // n >= 3
  }
  depth[x] = 0;
  dfs(x, -1);
  dfs2(x, -1);
  vector<bool> f(2, false);
  for (int i = 0; i < n; i++) {
    if (children[i] == 0) {
      f[depth[i] % 2] = true;
    }
  }
  cout << (f[0] && f[1] ? 3 : 1) << ' ' << dp[x] << '\n';


  return 0;
}