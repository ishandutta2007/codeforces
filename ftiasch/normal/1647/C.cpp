#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

char s[N][N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
    }
    if (s[0][0] == '1') {
      puts("-1");
    } else {
      std::vector<std::tuple<int, int, int, int>> plan;
      for (int i = n; i-- > 1;) {
        for (int j = 0; j < m; ++j) {
          if (s[i][j] == '1') {
            plan.emplace_back(i - 1, j, i, j);
          }
        }
      }
      for (int j = m; j-- > 1;) {
        if (s[0][j] == '1') {
          plan.emplace_back(0, j - 1, 0, j);
        }
      }
      printf("%d\n", static_cast<int>(plan.size()));
      for (auto [x1, y1, x2, y2] : plan) {
        printf("%d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
      }
    }
  }
}