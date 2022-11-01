#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

void dfs(int v, vector<bool> &used, vector<int> &order, vector<vector<int>> &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[v])
      dfs(u, used, order, g);
  order.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n), _g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
    _g[i].push_back(p);
  }
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<bool> used(n);
  vector<int> order;
  for (int i = 0; i < n; i++)
    if (!used[i])
      dfs(i, used, order, _g);
  vector<ll> leaves(n), sum(n), ans(n);
  reverse(order.begin(), order.end());
  for (int &v : order) {
    if (g[v].empty()) {
      leaves[v] = 1;
      sum[v] = ans[v] = a[v];
      continue;
    }
    for (int &u : g[v]) {
      leaves[v] += leaves[u];
      sum[v] += sum[u];
      ans[v] = max(ans[v], ans[u]);
    }
    sum[v] += a[v];
    ans[v] += max(0ll, (sum[v] - leaves[v] * ans[v] + leaves[v] - 1) / leaves[v]);
  }
  cout << ans[0];
  return 0;
}