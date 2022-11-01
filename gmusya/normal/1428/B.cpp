#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(int v, vector <bool> &used, vector <int> &order, vector <vector <int>> &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs(u, used, order, g);
  order.push_back(v);
}

void dfs2(int v, int &cnt, vector <bool> &used, vector <vector <int>> &g) {
  used[v] = true;
  cnt++;
  for (int u : g[v])
    if (!used[u])
      dfs2(u, cnt, used, g);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <int>> g(n), _g(n);
    string s;
    cin >> s;
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] != '<') {
        g[i].push_back(i + 1);
        _g[i + 1].push_back(i);
      }
      if (s[i] != '>') {
        g[i + 1].push_back(i);
        _g[i].push_back(i + 1);
      }
    }
    if (s[n - 1] != '<') {
      g[n - 1].push_back(0);
      _g[0].push_back(n - 1);
    }
    if (s[n - 1] != '>') {
      g[0].push_back(n - 1);
      _g[n - 1].push_back(0);
    }
    vector <bool> used(n);
    vector <int> order;
    for (int v = 0; v < n; v++)
      if (!used[v])
        dfs(v, used, order, g);
    used.assign(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int v = order[n - i - 1];
      if (used[v])
        continue;
      int cnt = 0;
      dfs2(v, cnt, used, _g);
      if (cnt != 1)
        ans += cnt;
    }
    cout << ans << '\n';
  }
  return 0;
}