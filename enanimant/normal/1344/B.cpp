// May 6, 2020
// https://codeforces.com/contest/1344/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 1005;

int n, m;
int a[N][N];

bool was[N][N];
pair<int, int> DIRS[4] = {
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1}
};

bool row_all_0[N];
bool col_all_0[N];

bool in_range(int r, int c) {
  return (0 <= r && r < n && 0 <= c && c < m);
}

void dfs(int r, int c) {
  for (const auto &p : DIRS) {
    int nr = r + p.first;
    int nc = c + p.second;
    if (!in_range(nr, nc) || was[nr][nc] || !a[r][c]) {
      continue;
    }
    was[nr][nc] = true;
    dfs(nr, nc);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    row_all_0[i] = true;
  }
  for (int j = 0; j < m; j++) {
    col_all_0[j] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '#');
      row_all_0[i] &= (a[i][j] == 0);
      col_all_0[j] &= (a[i][j] == 0);
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (row_all_0[i]) {
      bool any = false;
      for (int j = 0; j < m; j++) {
        any |= col_all_0[j];
      }
      if (!any) {
        ok = false;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    if (col_all_0[j]) {
      bool any = false;
      for (int i = 0; i < n; i++) {
        any |= row_all_0[i];
      }
      if (!any) {
        ok = false;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int l = m, r = -1;
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        l = min(l, j);
        r = max(r, j);
      }
    }
    if (l == m) {
      continue;
    }
    for (int j = l; j <= r; j++) {
      ok &= a[i][j];
    }
  }
  for (int j = 0; j < m; j++) {
    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
      if (a[i][j]) {
        l = min(l, i);
        r = max(r, i);
      }
    }
    if (l == n) {
      continue;
    }
    for (int i = l; i <= r; i++) {
      ok &= a[i][j];
    }
  }
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!was[i][j] && a[i][j]) {
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << '\n';


  return 0;
}