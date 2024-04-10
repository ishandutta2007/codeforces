#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vi deg;

bool cmp(int u, int v) {
  if (deg[u] != deg[v])
    return deg[u] > deg[v];
  return u > v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    deg.assign(n, 0);
    vvi g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      deg[u]++, deg[v]++;
      g[u].push_back(v), g[v].push_back(u);
    }
    vi a(n);
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
      sort(g[i].rbegin(), g[i].rend(), cmp);
    vector <bool> del(n);
    vvi t(n), _t(n);
    for (int v = 0; v < n; v++)
      for (int u : g[v])
        if (v < u && !del[v] && !del[u]) {
          t[v].push_back(u);
          _t[u].push_back(v);
        }
    vector <bool> d1(n, false);
    for (int v = 0; v < n; v++) {
      for (int u : _t[v])
        if (d1[u] && !del[u])
          del[v] = true;
      if (del[v])
        continue;
      for (int u : t[v])
        if (!del[u])
          d1[u] = true;
    }
    vi ans;
    for (int v = 0; v < n; v++)
      if (del[v])
        ans.push_back(v);
    cout << ans.size() << '\n';
    for (int v : ans)
      cout << v + 1 << ' ';
    cout << '\n';
  }
  return 0;
}