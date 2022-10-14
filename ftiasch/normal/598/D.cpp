#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000;
const int DELTA_X[]{-1, 0, 0, 1};
const int DELTA_Y[]{0, -1, 1, 0};

int n, m, q, component[N][N];
char s[N][N + 1];
std::vector<int> result;

int dfs(int x, int y, int c) {
  if (~component[x][y]) {
    return 0;
  }
  component[x][y] = c;
  int result = 0;
  for (int k = 0; k < 4; ++k) {
    int xx = x + DELTA_X[k];
    int yy = y + DELTA_Y[k];
    if (s[xx][yy] == '*') {
      result++;
    } else {
      result += dfs(xx, yy, c);
    }
  }
  return result;
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  memset(component, -1, sizeof(component));
  for (int sx = 0; sx < n; ++sx) {
    for (int sy = 0; sy < m; ++sy) {
      if (s[sx][sy] == '.' && !~component[sx][sy]) {
        int saw = dfs(sx, sy, result.size());
        result.push_back(saw);
      }
    }
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", result[component[x - 1][y - 1]]);
  }
}