#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timer = 0;

void dfs (int v, vector <int> &p, vector <int> &d, vector <int> &tin, vector <int> &tout, vector <vector <int>> &g) {
  tin[v] = timer++;
  for (int u : g[v]) {
    p[u] = v;
    d[u] = d[v] + 1;
    dfs(u, p, d, tin, tout, g);
  }
  tout[v] = timer - 1;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> roots;
  vector <vector <int>> g(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0)
      roots.push_back(i);
    else {
      x--;
      g[x].push_back(i);
    }
  }
  vector <int> p(n), d(n), tin(n), tout(n);
  for (auto &now : roots) {
    p[now] = now;
    dfs(now, p, d, tin, tout, g);
  }
  vector <int> lg(n + 1);
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i / 2] + 1;
  vector <vector <int>> binp(lg[n] + 1, vector <int>(n));
  for (int i = 0; i < n; i++)
    binp[0][i] = p[i];
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++)
      binp[pow][i] = binp[pow - 1][binp[pow - 1][i]];
  vector <vector <int>> keks(n);
  for (int i = 0; i < n; i++)
    keks[d[i]].push_back(tin[i]);
  for (int i = 0; i < n; i++)
    if (!keks[i].empty())
      sort(keks[i].begin(), keks[i].end());
  int q;
  cin >> q;
  while (q--) {
    int v, len;
    cin >> v >> len;
    v--;
    int dep = d[v];
    if (d[v] < len) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = 0; i <= lg[n]; i++)
      if (len & (1 << i))
        v = binp[i][v];
    int l = tin[v], r = tout[v];
    cout << upper_bound(keks[dep].begin(), keks[dep].end(), r) - lower_bound(keks[dep].begin(), keks[dep].end(), l) - 1 << '\n';
  }
  return 0;
}