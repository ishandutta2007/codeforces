#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vector <bool> used;
vi col;
vvi g, _g;
vvi newg;

void dfs(int v, vi &ord, vvi &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs(u, ord, g);
  ord.push_back(v);
}

void sol(int v, vi &ans, vvi &g) {
  ans[v] = 1;
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u])
      sol(u, ans, g);
    ans[v] = max(ans[v], ans[u] + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n), _g.resize(n);
  for (int i = 1; i < n; i++) {
    char c;
    cin >> c;
    if (c != 'R') {
      g[i].push_back(i - 1);
      _g[i - 1].push_back(i);
    }
    if (c != 'L') {
      g[i - 1].push_back(i);
      _g[i].push_back(i - 1);
    }
  }
  vi ord;
  used.resize(n);
  for (int v = 0; v < n; v++) {
    if (used[v])
      continue;
    dfs(v, ord, g);
  }
  used.assign(n, false);
  int cnt = 0;
  col.resize(n);
  for (int i = n - 1; i >= 0; i--) {
    int v = ord[i];
    if (used[v])
      continue;
    vi comp;
    dfs(v, comp, _g);
    for (int u : comp)
      col[u] = cnt;
    cnt++;
  }
  newg.resize(cnt);
  for (int v = 0; v < n; v++)
    for (int u : g[v])
      if (col[u] != col[v])
        newg[col[u]].push_back(col[v]);
  used.assign(cnt, false);
  vi ans(cnt);
  for (int v = 0; v < cnt; v++)
    if (!used[v])
      sol(v, ans, newg);
  for (int v = 0; v < n; v++)
    cout << ans[col[v]] << ' ';
  return 0;
}