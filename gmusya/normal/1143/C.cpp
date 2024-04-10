#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector <bool> &used, vector <int> &c, vector <vector <int>> &g, vector <int> &ans) {
  used[v] = true;
  ans[v] = c[v];
  for (int u : g[v])
    if (!used[u]) {
      dfs(u, used, c, g, ans);
      if (ans[v] > c[u])
        ans[v] = c[u];
    }
}

int main() {
  int n;
  cin >> n;
  vector <int> c(n), ans(n);
  vector <vector <int>> g(n);
  int root;
  for (int v = 0; v < n; v++) {
    int x;
    cin >> x >> c[v];
    if (x == -1) {
      root = v;
    } else {
      x--;
      g[x].push_back(v);
      g[v].push_back(x);
    }
  }
  c[root] = 0;
  vector <bool> used(n);
  vector <int> answer;
  dfs(root, used, c, g, ans);
  for (int v = 0; v < n; v++)
    if (ans[v])
      answer.push_back(v + 1);
  if (answer.empty()) {
    cout << -1;
  } else {
    for (int v : answer)
      cout << v << ' ';
  }
  return 0;
}