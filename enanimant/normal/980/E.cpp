// August 26, 2019
// https://codeforces.com/contest/980/problem/E

/*
William Li brought this problem up.

As per usual, submit this tomorrow morning.
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


  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> pv(n);
  function<void(int, int)> dfs = [&](int v, int p) {
    // check tourist's new DFS implementation from his submission to 1208H
    pv[v] = p;
    for (int to : g[v]) {
      if (to == p) {
        continue;
      }
      dfs(to, v);
    }
  };
  dfs(n - 1, -1);
  int h = 0;
  while ((1 << h) < n) {
    h++;
  }
  vector<vector<int>> pr(h, vector<int>(n));
  for (int i = 0; i < n; i++) {
    pr[0][i] = pv[i];
  }
  for (int i = 1; i < h; i++) {
    for (int j = 0; j < n; j++) {
      pr[i][j] = (pr[i - 1][j] == -1 ? -1 : pr[i - 1][pr[i - 1][j]]);
    }
  }
  vector<bool> take(n, false);
  int rem = n - k;
  take[n - 1] = true;
  rem--;
  for (int i = n - 2; i >= 0; i--) {
    if (take[i]) {
      continue;
    }
    int x = i;
    int cnt = 0;
    for (int j = h - 1; j >= 0; j--) {
      if (pr[j][x] != -1 && !take[pr[j][x]]) {
        x = pr[j][x];
        cnt |= 1 << j;
      }
    }
    x = pv[x];
    cnt++;
    if (cnt > rem) {
      continue;
    }
    rem -= cnt;
    for (int j = i; j != x; j = pv[j]) {
      take[j] = true;
    }
  }
  bool first = true;
  for (int i = 0; i < n; i++) {
    if (!take[i]) {
      if (!first) {
        cout << ' ';
      }
      first = false;
      cout << i + 1;
    }
  }
  cout << '\n';


  return 0;
}