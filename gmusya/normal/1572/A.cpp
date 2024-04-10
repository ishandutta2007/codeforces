#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<bool> used;
vector<int> order;
vector<vector<int>> g;

void dfs(int v) {
  used[v] = true;
  for (int u : g[v]) {
    if (used[u]) {
      continue;
    }
    dfs(u);
  }
  order.push_back(v);
}

void top_sort() {
  used.assign(n, false);
  order.assign(0, 0);
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      g[i].resize(k);
      for (int j = 0; j < k; j++) {
        cin >> g[i][j];
        --g[i][j];
      }
    }
    top_sort();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[order[i]] = i;
    }
    bool flag = true;
    for (int v = 0; v < n; v++) {
      for (int u : g[v]) {
        if (p[v] <= p[u]) {
          flag = false;
        }
      }
    }
    if (!flag) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> ans(n, 1);
    for (int v : order) {
      for (int u : g[v]) {
        ans[v] = max(ans[v], ans[u] + (u > v));
      }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
  }
  return 0;
}