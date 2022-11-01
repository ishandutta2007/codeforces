// May 12, 2020
// https://codeforces.com/contest/1349/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 1005;
pair<int, int> DIRS[4] = {
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1}
};

int n, m, t;
int a[N][N];
int dist[N][N];

bool in_range(int r, int c) {
  return (0 <= r && r < n && 0 <= c && c < m);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = (int) (c - '0');
      dist[i][j] = -1;
    }
  }
  queue<pair<int, int>> q;
  bool any = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ok = false;
      for (const auto &p : DIRS) {
        int ii = i + p.first;
        int jj = j + p.second;
        if (in_range(ii, jj)) {
          ok |= (a[ii][jj] == a[i][j]);
        }
      }
      if (ok) {
        any = true;
        dist[i][j] = 0;
        q.emplace(i, j);
      }
    }
  }
  while (!q.empty()) {
    int i, j;
    tie(i, j) = q.front();
    q.pop();
    for (const auto &p : DIRS) {
      for (const auto &p : DIRS) {
        int ii = i + p.first;
        int jj = j + p.second;
        if (!in_range(ii, jj) || dist[ii][jj] != -1) {
          continue;
        }
        dist[ii][jj] = dist[i][j] + 1;
        q.emplace(ii, jj);
      }
    }
  }
  while (t--) {
    int i, j;
    long long p;
    cin >> i >> j >> p;
    i--; j--;
    int ans = a[i][j];
    if (p >= dist[i][j]) {
      p -= dist[i][j];
      if (p & 1) {
        ans ^= 1;
      }
    }
    if (!any) {
      ans = a[i][j];
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}