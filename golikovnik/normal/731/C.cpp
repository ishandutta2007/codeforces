#include <bits/stdc++.h>

using i64 = int64_t;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n);
  for (int& x : c) cin >> x;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  vector<map<int, int>> mp(n);
  for (int i = 0; i < n; ++i) {
    mp[i][c[i]] = 1;
  }
  function<int(int)> find = [&](int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  };
  auto unite = [&](int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (mp[u].size() > mp[v].size()) {
      swap(u, v);
    }
    for (auto[x, y] : mp[u]) {
      mp[v][x] += y;
    }
    p[u] = v;
  };
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    unite(l, r);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (find(i) != i) continue;
    int mx = 0;
    int tot = 0;
    for (auto[x, y] : mp[i]) {
      mx = max(mx, y);
      tot += y;
    }
    ans += tot - mx;
  }
  cout << ans << '\n';
  return 0;
}