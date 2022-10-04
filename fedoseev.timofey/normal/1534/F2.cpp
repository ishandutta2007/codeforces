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
  int all_zer = 1;
  for (int i = 0; i < m; ++i) {
    cin >> need[i];
    all_zer &= (need[i] == 0);
  }
  if (all_zer) {
    cout << "0\n";
    return 0;
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
  vector <vector <int>> ng(cnt);
  for (int i = 0; i < uk; ++i) {
    for (int j : g[i]) {
      if (cmp[i] != cmp[j]) {
        ng[cmp[i]].push_back(cmp[j]);
      }
    }
  }
  vector <vector <int>> l(n + 1, vector <int> (m, m));
  vector <vector <int>> r(n + 1, vector <int> (m, -1));
  vector <vector <pair <int, int>>> have(cnt);
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      int x = id[i][j];
      if (x == -1) continue;
      x = cmp[x];
      if (have[x].empty() || have[x].back().first != j) {
        have[x].push_back({j, i});
      }
    }
  }
  auto get = [&] (int cm, int cl) {
    auto it = lower_bound(have[cm].begin(), have[cm].end(), make_pair(cl, -1));
    if (it == have[cm].end() || it->first != cl) return -1;
    return it->second;
  };
  for (int j = 0; j < m; ++j) {
    int vis = 0;
    int up = n;
    for (int i = n - 1; i >= 0; --i) {
      if (id[i][j] == -1) continue;
      ++vis;
      if (get(cmp[id[i][j]], j) != i) continue;
      for (auto v : ng[cmp[id[i][j]]]) {
        int x = get(v, j - 1);
        if (x != -1) up = min(up, x);
      }
      int x = get(cmp[id[i][j]], j - 1);
      if (x != -1) up = min(up, x);
      if (vis >= need[j]) {
        l[i][j] = j;
        if (j > 0) l[i][j] = min(l[i][j], l[up][j - 1]);
      }
    }
    if (need[j] == 0) {
      l[n][j] = j;
      if (j > 0) {
        l[n][j] = min(l[n][j], l[n][j - 1]);
      }
    }
  }
  for (int j = m - 1; j >= 0; --j) {
    int up = n;
    int vis = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[i][j] == -1) continue;
      ++vis;
      if (get(cmp[id[i][j]], j) != i) continue;
      for (auto v : ng[cmp[id[i][j]]]) {
        int x = get(v, j + 1);
        if (x != -1) {
          up = min(up, x);
        }
      }
      int x = get(cmp[id[i][j]], j + 1);
      if (x != -1) {
        up = min(up, x);
      }
      if (vis >= need[j]) {
        r[i][j] = j;
        if (j + 1 < m) r[i][j] = max(r[i][j], r[up][j + 1]);
      }
    }
    if (need[j] == 0) {
      r[n][j] = j;
      if (j + 1 < m) {
        r[n][j] = max(r[n][j], r[n][j + 1]);
      }
    }
  }
 
  vector <pair <int, int>> segs;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (l[i][j] <= r[i][j]) {
        //cout << l[i][j] << ' ' << r[i][j] << endl;
        segs.push_back({l[i][j], r[i][j]});
      }
    }
  }
  sort(segs.begin(), segs.end());
  int cur = 0;
  int ans = 0;
  int max_r = 0;
  for (auto p : segs) {
    if (p.first <= cur) {
      max_r = max(max_r, p.second + 1);
    } else {
      cur = max_r;
      ++ans;
    }
  }
  if (cur != max_r) ++ans;
  cout << ans << '\n';
}