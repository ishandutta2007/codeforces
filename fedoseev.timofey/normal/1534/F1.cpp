#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <char>> a(n, vector <char> (m));
  vector <vector <int>> id(n, vector <int> (m, -1));
  int uk = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        id[i][j] = uk++;
      }
    }
  }
  vector <int> need(m);
  for (int i = 0; i < m; ++i) {
    cin >> need[i];
  }
  
  vector <vector <int>> g(uk), rg(uk);
  auto add_edge = [&] (int u, int v) {
    g[u].push_back(v);
    rg[v].push_back(u);
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#') {
        if (i > 0 && a[i - 1][j] == '#') {
          add_edge(id[i][j], id[i - 1][j]);
        }
        for (int k = i; k < n; ++k) {
          if (j > 0 && a[k][j - 1] == '#') add_edge(id[i][j], id[k][j - 1]);
          if (j + 1 < m && a[k][j + 1] == '#') add_edge(id[i][j], id[k][j + 1]);
          if (a[k][j] == '#' && k != i) {
            add_edge(id[i][j], id[k][j]);
            break;
          }
        }
      }
    }
  }
  vector <int> t;
  vector <int> used(uk);
  function <void(int)> find_t = [&] (int u) {
    used[u] = 1;
    for (auto v : g[u]) {
      if (!used[v]) {
        find_t(v);
      }
    }
    t.push_back(u);
  };
  for (int i = 0; i < uk; ++i) {
    if (!used[i]) {
      find_t(i);
    }
  }
  reverse(t.begin(), t.end());
  for (int i = 0; i < uk; ++i) used[i] = 0;
  int cnt = 0;
  vector <int> cmp(uk, -1);
  function <void(int)> dfs = [&] (int u) {
    used[u] = 1;
    cmp[u] = cnt;
    for (auto v : rg[u]) {
      if (!used[v]) {
        dfs(v);
      }
    }
  };
  for (int u : t) {
    if (!used[u]) {
      dfs(u);
      ++cnt;
    }
  }
  vector <int> ok(cnt, 1);
  for (int i = 0; i < uk; ++i) {
    for (int j : g[i]) {
      if (cmp[i] != cmp[j]) {
        ok[cmp[j]] = 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < cnt; ++i) ans += ok[i];
  cout << ans << '\n';
}