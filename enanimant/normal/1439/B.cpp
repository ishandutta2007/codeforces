/*
 * author:  ADMathNoob
 * created: 07/31/21 13:46:16
 * problem: https://codeforces.com/contest/1439/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end());
      deg[i] = (int) g[i].size();
    }
    vector<int> que;
    for (int i = 0; i < n; i++) {
      if (deg[i] < k) {
        que.push_back(i);
      }
    }
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (int u : g[v]) {
        if (--deg[u] == k - 1) {
          que.push_back(u);
        }
      }
    }
    if ((int) que.size() < n) {
      vector<int> ret;
      for (int i = 0; i < n; i++) {
        if (deg[i] >= k) {
          ret.push_back(i);
        }
      }
      int cnt = (int) ret.size();
      cout << 1 << ' ' << cnt << '\n';
      for (int i = 0; i < cnt; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << ret[i] + 1;
      }
      cout << '\n';
      continue;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      pos[que[i]] = i;
    }
    bool found = false;
    for (int v : que) {
      vector<int> c;
      for (int u : g[v]) {
        if (pos[u] > pos[v]) {
          c.push_back(u);
        }
      }
      if ((int) c.size() < k - 1) {
        continue;
      }
      sort(c.begin(), c.end());
      bool ok = true;
      for (int j = 0; j < k - 1; j++) {
        int x = c[j];
        int last = -1;
        for (int jj = 0; jj < j; jj++) {
          int y = c[jj];
          auto it = lower_bound(g[x].begin() + last + 1, g[x].end(), y);
          if (it == g[x].end() || *it != y) {
            ok = false;
            goto checked;
          }
          last = (it - g[x].begin());
        }
      }
checked:
      if (ok) {
        cout << 2 << '\n';
        cout << v + 1;
        for (int u : c) {
          cout << ' ' << u + 1;
        }
        cout << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      cout << -1 << '\n';
    }
  }
  return 0;
}