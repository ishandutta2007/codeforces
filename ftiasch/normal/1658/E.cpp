#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  std::vector<std::pair<int, int>> position(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0, v; j < n; ++j) {
      scanf("%d", &v);
      position[v - 1] = {i, j};
    }
  }
  int min_x = INT_MIN, max_x = INT_MAX, min_y = INT_MIN, max_y = INT_MAX;
  // x = i - j
  // y = i + j
  std::vector<std::vector<bool>> lose(n, std::vector<bool>(n, false));
  for (int v = n * n; v--;) {
    auto [i, j] = position[v];
    int x = i - j;
    int y = i + j;
    if (min_x <= x && x <= max_x && min_y <= y && y <= max_y) {
      min_x = std::max(min_x, x - d);
      max_x = std::min(max_x, x + d);
      min_y = std::max(min_y, y - d);
      max_y = std::min(max_y, y + d);
    } else {
      lose[i][j] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      putchar("MG"[lose[i][j]]);
    }
    puts("");
  }
}