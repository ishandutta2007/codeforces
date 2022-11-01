#include <iostream>
#include <vector>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

bool fib[200001];

void init() {
  int a = 1, b = 1;
  while (a < 200000) {
    fib[a] = true;
    b = a + b;
    swap(a, b);
  }
}

vector <bool> used;
vi sz, cmp, par;
vvi g;

void dfs(int v) {
  cmp.push_back(v);
  sz[v] = 1;
  used[v] = true;
  for (int u : g[v])
    if (!used[u]) {
      dfs(u);
      par[u] = v;
      sz[v] += sz[u];
    }
}

bool solve(int rt) {
  cmp.resize(0);
  dfs(rt);
  int n = sz[rt];
  if (sz[rt] == 1)
    return true;
  for (int v : cmp)
    used[v] = false;
  for (int v : cmp) {
    if (rt == v)
      continue;
    if (fib[sz[v]] && fib[n - sz[v]]) {
      int u = par[v];
      used[u] = true;
      if (!solve(v))
        return false;
      used[v] = true;
      if (!solve(u))
        return false;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  if (!fib[n]) {
    cout << "NO\n";
    return 0;
  }
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  used.assign(n, false);
  sz.assign(n, 0);
  par.assign(n, -1);
  if (solve(0))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}