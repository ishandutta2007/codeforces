#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> used;
vector<vector<int>> g;
int list = 0, pochka = 0, tmp = 0;

bool dfs(int v) {
  used[v] = true;
  int pochka_kids = 0;
  int list_kids = 0;
  for (int u : g[v]) {
    if (used[u]) {
      continue;
    }
    bool flag = dfs(u);
    if (flag) {
      pochka_kids++;
    } else {
      if (v == 0) {
        tmp = 1;
      }
      list_kids++;
    }
  }
  if (!v) {
    return false;
  }
  if (!list_kids) {
    list++;
    return false;
  } else {
    pochka++;
    return true;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    g.assign(n, {});
    used.assign(n, false);
    for (int i = 0; i + 1 < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    list = 0;
    pochka = 0;
    tmp = 0;
    dfs(0);
    cout << list - pochka + (1 - tmp) << '\n';
  }
  return 0;
}