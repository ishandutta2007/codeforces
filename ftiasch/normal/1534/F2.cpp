#include <bits/stdc++.h>

namespace {

using Grid = std::vector<std::vector<char>>;

struct Solver {
  Solver(int n_, int m_, const Grid &grid_)
      : n(n_), m(m_), grid(grid_), visit(n, std::vector<int>(m, -1)) {}

  void dfs(int source, int x, int y) {
    if (!~visit[x][y]) {
      visit[x][y] = source;
      if (x) {
        dfs(source, x - 1, y);
      }
      if (y && grid[x][y - 1] == '#') {
        dfs(source, x, y - 1);
      }
      if (y + 1 < m && grid[x][y + 1] == '#') {
        dfs(source, x, y + 1);
      }
      if (x + 1 < n && grid[x + 1][y] == '#') {
        dfs(source, x + 1, y);
      }
    }
  }

  const std::vector<int> &operator[](int i) const { return visit[i]; }

  int n, m;
  const Grid &grid;
  std::vector<std::vector<int>> visit;
};

} // namespace

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::vector<char>> grid(n, std::vector<char>(m + 1));
  for (int i = n; i--;) {
    scanf("%s", grid[i].data());
  }
  std::vector<std::vector<int>> column(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '#') {
        column[j].push_back(i);
      }
    }
  }
  Solver left(n, m, grid), right(n, m, grid);
  for (int j = 0; j < m; ++j) {
    if (!column[j].empty()) {
      left.dfs(j, column[j].back(), j);
    }
  }
  for (int j = m; j--;) {
    if (!column[j].empty()) {
      right.dfs(j, column[j].back(), j);
    }
  }
  std::vector<std::pair<int, int>> intervals;
  for (int j = 0, a; j < m; ++j) {
    scanf("%d", &a);
    if (a) {
      int i = column[j][a - 1];
      intervals.emplace_back(right[i][j], left[i][j]);
    }
  }
  std::sort(intervals.begin(), intervals.end());
  int result = 0, last = -1;
  for (auto &&[r, l] : intervals) {
    if (last < l) {
      result++;
      last = r;
    }
  }
  printf("%d\n", result);
}