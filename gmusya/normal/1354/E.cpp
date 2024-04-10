#include <iostream>
#include <vector>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;

void dfs(int v, vb &used, vi &col, vi &all, vvi &g) {
  used[v] = true;
  for (int u : g[v]) {
    if (used[u])
      continue;
    col[u] = 1 - col[v];
    dfs(u, used, col, all, g);
  }
  all.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vvi g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vvi comp;
  vi col(n);
  vb used(n);
  vi a, b;
  for (int v = 0; v < n; v++) {
    if (used[v])
      continue;
    comp.push_back({});
    dfs(v, used, col, comp.back(), g);
    int cnt0 = 0, cnt1 = 0;;
    for (int u : comp.back()) {
      if (col[u] == 0)
        cnt0++;
      else
        cnt1++;
    }
    a.push_back(cnt0);
    b.push_back(cnt1);
  }
  for (int v = 0; v < n; v++)
    for (int u : g[v])
      if (col[u] == col[v]) {
        cout << "NO";
        return 0;
      }
  int k = (int)a.size();
  vvi dp(k + 1, vi(n + 1, -1));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    int cnt0 = a[i - 1], cnt1 = b[i - 1];
    for (int w = 0; w <= n; w++) {
      if (dp[i - 1][w] == -1)
        continue;
      if (w + cnt0 <= n)
        dp[i][w + cnt0] = 0;
      if (w + cnt1 <= n)
        dp[i][w + cnt1] = 1;
    }
  }
  if (dp[k][n2] == -1) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  int w = n2;
  for (int i = k; i >= 1; i--) {
    int cnt0 = a[i - 1], cnt1 = b[i - 1];
    if (dp[i][w] == 0) {
      w -= cnt0;
    } else {
      w -= cnt1;
      for (int v : comp[i - 1])
        col[v] = 1 - col[v];
    }
  }
  for (int i = 0; i < n; i++) {
    if (col[i] == 0) {
      cout << 2;
      continue;
    }
    if (n1) {
      cout << 1;
      n1--;
    } else {
      cout << 3;
    }
  }
  return 0;
}