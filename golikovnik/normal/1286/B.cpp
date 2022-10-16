#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> c(n);
  vector<vector<int>> graph(n);
  int root = 0;
  for (int i = 0; i < n; ++i) {
    int p, x;
    cin >> p >> x;
    if (!p) {
      root = i;
    } else {
      graph[p - 1].push_back(i);
    }
    c[i] = x;
  }
  vector<int> a(n, -1);
  function<int(int, int)> add = [&](int v, int d) {
    a[v] += d;
    int mx = a[v];
    for (int u : graph[v]) {
      mx = max(mx, add(u, d));
    }
    return mx;
  };
  function<vector<int>(int)> get_vals = [&](int v) {
    vector<int> r{a[v]};
    for (auto u : graph[v]) {
      auto ru = get_vals(u);
      r.insert(r.end(), ru.begin(), ru.end());
    }
    return r;
  };
  function<int(int, int, bool)> fix = [&](int v, int val, bool root) {
    if (!root && a[v] >= val) {
      a[v]++;
    }
    int mx = a[v];
    for (int u : graph[v]) {
      mx = max(mx, fix(u, val, false));
    }
    return mx;
  };
  function<pair<int, int>(int)> dfs = [&](int v) {
    if (graph[v].empty()) {
      if (c[v]) {
        cout << "NO\n";
        exit(0);
      }
      a[v] = 1;
      return pair{a[v], 1};
    }
    int last_max = 0;
    int who = -1;
    int my_sz = 1;
    for (int u : graph[v]) {
      auto[mx, sz] = dfs(u);
      last_max = add(u, last_max);
      if (who < 0 && c[v] >= mx) {
        c[v] -= mx;
      } else if (who < 0) {
        who = u;
      }
      my_sz += sz;
    }
    if (who < 0 && c[v]) {
      cout << "NO\n";
      exit(0);
    }
    if (who < 0) {
      a[v] = last_max + 1;
    } else {
      auto vals = get_vals(who);
      nth_element(vals.begin(), vals.begin() + c[v], vals.end());
      a[v] = vals[c[v]];
    };
    auto mx = fix(v, a[v], true);
    return pair{mx, my_sz};
  };
  dfs(root);
  cout << "YES\n";
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}