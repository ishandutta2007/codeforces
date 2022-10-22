#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int n) : p(n, -1) {}
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

vector<int> a, b;
vector<vector<int>> g;

bool dfs(int v, int par, int x) {
  if (v == x)
    return true;
  for (int i : g[v]) {
    int u = a[i]^b[i]^v;
    if (u == par) continue;
    if (dfs(u, v, x))
      return true;
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  a.resize(m);
  b.resize(m);
  g.assign(n, {});
  Dsu dsu(n);
  set<int> st;
  string ans(m, '0');
  int invalid = -1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    a[i] = u;
    b[i] = v;
    if (dsu.merge(u, v)) {
      g[u].push_back(i);
      g[v].push_back(i);
      ans[i]++;
    } else {
      st.insert(u);
      st.insert(v);
      invalid = i;
    }
  }
  if (st.size() == 3 && m == n + 2) {
    ++ans[invalid];
    for (int u : g[a[invalid]]) {
      if (dfs(b[u]^a[u]^a[invalid], a[invalid], b[invalid])) {
        --ans[u];
        break;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}