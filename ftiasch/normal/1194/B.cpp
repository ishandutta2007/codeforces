#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<char>> grid(n, std::vector<char>(m + 1));
    std::vector<int> row(n), col(m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i].data());
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '.') {
          row[i]++;
          col[j]++;
        }
      }
    }
    int result = n * m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        result = std::min(result, row[i] + col[j] - (grid[i][j] == '.'));
      }
    }
    printf("%d\n", result);
  }
}