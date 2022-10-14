#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000;
const int DELTA_X[]{-1, 0, 0, 1};
const int DELTA_Y[]{0, -1, 1, 0};

int n, m, comp[N][N];
char grid[N][N + 1];
std::vector<int> size;

int dfs(int x, int y, int c) {
  if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] == '.' && !~comp[x][y]) {
    comp[x][y] = c;
    int result = 1;
    for (int k = 0; k < 4; ++k) {
      result += dfs(x + DELTA_X[k], y + DELTA_Y[k], c);
    }
    return result;
  } else {
    return 0;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", grid[i]);
  }
  memset(comp, -1, sizeof(comp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.' && !~comp[i][j]) {
        size.push_back(dfs(i, j, size.size()));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '*') {
        std::vector<std::pair<int, int>> ns;
        for (int k = 0; k < 4; ++k) {
          int x = i + DELTA_X[k];
          int y = j + DELTA_Y[k];
          if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] == '.') {
            ns.emplace_back(comp[x][y], size[comp[x][y]]);
          }
        }
        std::sort(ns.begin(), ns.end());
        ns.erase(std::unique(ns.begin(), ns.end()), ns.end());
        int result = 1;
        for (auto &&[_, s] : ns) {
          result += s;
        }
        grid[i][j] = '0' + (result % 10);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    puts(grid[i]);
  }
}