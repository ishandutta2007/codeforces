#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n, m, min_x, max_x, min_y, max_y, count;
bool visited[N][N];
char s[N][N + 1];

void dfs(int x, int y) {
  if (0 <= x && x < n && 0 <= y && y < m && s[x][y] == '1' && !visited[x][y]) {
    visited[x][y] = true;
    min_x = std::min(min_x, x);
    max_x = std::max(max_x, x);
    min_y = std::min(min_y, y);
    max_y = std::max(max_y, y);
    count++;
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
      std::fill(visited[i], visited[i] + m, false);
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '1' && !visited[i][j]) {
          min_x = min_y = INT_MAX;
          max_x = max_y = INT_MIN;
          count = 0;
          dfs(i, j);
          ok &= count == (max_x - min_x + 1) * (max_y - min_y + 1);
        }
      }
    }
    puts(ok ? "YES" : "NO");
  }
}