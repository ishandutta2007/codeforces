#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timer = 0;

void dfs(int v, vector <bool> &used, vector <int> &tin, vector <int> &tout, vector <int> &ord, vector <vector <int>> &g) {
  used[v] = true;
  tin[v] = timer++;
  ord[tin[v]] = v;
  for (int u : g[v])
    if (!used[u])
      dfs(u, used, tin, tout, ord, g);
  tout[v] = timer - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <vector <int>> g(n);
  for (int v = 1; v < n; v++) {
    int u;
    cin >> u;
    u--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int v = 0; v < n; v++)
    sort(g[v].begin(), g[v].end());
  vector <bool> used(n);
  vector <int> tin(n), tout(n), ord(n);
  dfs(0, used, tin, tout, ord, g);
  while (q--) {
    int v, k;
    cin >> v >> k;
    v--;
    k--;
    if (tin[v] + k > tout[v])
      cout << -1 << '\n';
    else
      cout << ord[tin[v] + k] + 1 << '\n';
  }
  return 0;
}