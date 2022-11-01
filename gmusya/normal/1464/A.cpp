#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(int v, vector <bool> &used, vector <vector <int>> &g, int &cnta, int &cntb) {
  used[v] = true;
  cnta += g[v].size();
  cntb++;
  for (int u : g[v]) {
    if (used[u])
      continue;
    dfs(u, used, g, cnta, cntb);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);
    int ans = 0;
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (x == y)
        continue;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector <bool> used(n);
    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;
      int cnta = 0, cntb = 0;
      dfs(i, used, g, cnta, cntb);
      ans += cntb - 1;
      if (cnta == 2 * cntb)
        ans += 2;
    }
    cout << ans << '\n';
  }
  return 0;
}