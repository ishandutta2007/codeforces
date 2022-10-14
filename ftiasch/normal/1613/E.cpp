#include <bits/stdc++.h>

const int DELTA_X[] = {-1, 0, 0, 1};
const int DELTA_Y[] = {0, -1, 1, 0};

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<char>> grid(n + 2, std::vector<char>(m + 2, '#'));
    {
      std::vector<char> buffer(m + 2);
      for (int i = 1; i <= n; ++i) {
        scanf("%s", buffer.data() + 1);
        memcpy(grid[i].data() + 1, buffer.data() + 1, sizeof(char) * m);
      }
    }
    std::vector<std::vector<int>> deg(n + 2, std::vector<int>(m + 2));
    std::queue<std::pair<int, int>> queue;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (grid[i][j] == 'L') {
          queue.emplace(i, j);
        }
        for (int k = 0; k < 4; ++k) {
          int x = i + DELTA_X[k];
          int y = j + DELTA_Y[k];
          deg[i][j] += (grid[x][y] != '#');
        }
      }
    }
    while (!queue.empty()) {
      auto [i, j] = queue.front();
      queue.pop();
      for (int k = 0; k < 4; ++k) {
        int x = i + DELTA_X[k];
        int y = j + DELTA_Y[k];
        if (grid[x][y] == '.') {
          deg[x][y]--;
          if (deg[x][y] <= 1) {
            grid[x][y] = '+';
            queue.emplace(x, y);
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      grid[i][m + 1] = '\0';
      puts(grid[i].data() + 1);
    }
  }
}