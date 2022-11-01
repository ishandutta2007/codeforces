#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vector <bool> used;

void dfs(int v, vi &ord, vvi &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs(u, ord, g);
  ord.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vvi g(n), _g(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    v--;
    if (v == -1)
      continue;
    g[v].push_back(i);
    _g[i].push_back(v);
  }
  vvi t = g, _t = _g;
  vi next(n, -1), prev(n, -1);
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    next[u] = v;
    prev[v] = u;
    t[u].push_back(v);
    t[v].push_back(u);
    _t[u].push_back(v);
    _t[v].push_back(u);
  }
  used.assign(n, false);
  vi ord;
  for (int v = 0; v < n; v++)
    if (!used[v])
      dfs(v, ord, t);
  reverse(ord.begin(), ord.end());
  vi p(n);
  for (int i = 0; i < n; i++)
    p[ord[i]] = i;
  used.assign(n, false);
  vi ans;
  for (int v : ord) {
    if (used[v])
      continue;
    vi comp;
    int hm = 0;
    dfs(v, comp, _t);
    int root = -1;
    for (int u : comp)
      if (prev[u] == -1)
        root = u;
    if (root == -1) {
      cout << 0;
      return 0;
    }
    do {
      hm++;
      if (hm > comp.size()) {
        cout << 0;
        return 0;
      }
      ans.push_back(root);
      root = next[root];
    } while (root != -1);
    if (hm != comp.size()) {
      cout << 0;
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
    p[ans[i]] = i;
  for (int v = 0; v < n; v++)
    for (int u : g[v])
      if (p[v] > p[u]) {
        cout << 0;
        return 0;
      }
  for (int i = 0; i < n; i++)
    cout << ans[i] + 1 << ' ';
  return 0;
}