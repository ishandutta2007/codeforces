#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <set <int>> g(n), leaves(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].insert(v);
      g[v].insert(u);
    }
    if (k == 1) {
      cout << n - 1 << '\n';
      continue;
    }
    set <pair <int, int>> s;
    for (int v = 0; v < n; v++) {
      int cnt = 0;
      for (int u : g[v])
        if (g[u].size() == 1)
          leaves[v].insert(u);
      int k = leaves[v].size();
      s.insert({-k, v});
    }
    int ans = 0;
    while (!s.empty()) {
      auto now = *s.begin();
      s.erase(now);
      int cnt = -now.first, v = now.second;
      if (cnt < k) break;
      ans++;
      int x = k;
      while (x--) {
        int u = *leaves[v].begin();
        leaves[v].erase(u);
        g[v].erase(u);
      }
      if (g[v].size() == 1) {
        int u = *g[v].begin();
        int k = leaves[u].size();
        s.erase({-k, u});
        s.insert({-(k + 1), u});
        leaves[u].insert(v);
      }
      s.insert({-(cnt - k), v});
    }
    cout << ans << '\n';
  }
  return 0;
}