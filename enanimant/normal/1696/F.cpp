/*
 * author:  ADMathNoob
 * created: 06/25/22 07:35:35
 * problem: https://codeforces.com/contest/1696/problem/F
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

void TestCase() {
  int n;
  cin >> n;
  vector<vector<string>> s(n, vector<string>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> s[i][j];
      s[j][i] = s[i][j];
    }
  }
  vector<vector<int>> eid(n, vector<int>(n, -1));
  int cnt = 0;
  vector<pair<int, int>> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      eid[i][j] = eid[j][i] = cnt++;
      edges.emplace_back(i, j);
    }
  }
  vector<vector<int>> g(cnt);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (i == j || i == k) continue;
        if (s[j][k][i] == '1') {
          int x = eid[i][j];
          int y = eid[i][k];
          g[x].push_back(y);
          g[y].push_back(x);
        }
      }
    }
  }
  
  auto Works = [&](const vector<int>& ids) -> bool {
    if ((int) ids.size() != n - 1) {
      return false;
    }
    vector<vector<int>> mat(n, vector<int>(n, n));
    for (int i = 0; i < n; i++) {
      mat[i][i] = 0;
    }
    for (int id : ids) {
      auto [a, b] = edges[id];
      mat[a][b] = mat[b][a] = 1;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == n) {
          return false;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if ((s[i][j][k] == '1') != (mat[i][k] == mat[j][k])) {
            return false;
          }
        }
      }
    }
    return true;
  };
  
  vector<bool> was(cnt);
  for (int x = 0; x < cnt; x++) {
    if (was[x]) continue;
    vector<int> que(1, x);
    was[x] = true;
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (int u : g[v]) {
        if (was[u]) continue;
        was[u] = true;
        que.push_back(u);
      }
    }
    if (Works(que)) {
      cout << "Yes" << '\n';
      for (int id : que) {
        auto [a, b] = edges[id];
        cout << a + 1 << ' ' << b + 1 << '\n';
      }
      return;
    }
  }
  cout << "No" << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    TestCase();
  }
  return 0;
}