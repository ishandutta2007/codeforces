#include <bits/stdc++.h>

const int N = 50;

char s[N + 1], result[N][N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        result[i][j] = "=X"[i == j];
      }
      result[i][n] = '\0';
    }
    std::vector<int> winners;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '2') {
        winners.push_back(i);
      }
    }
    if (winners.size() == 1U || winners.size() == 2U) {
      puts("NO");
    } else {
      for (int i = 0; i < winners.size(); ++i) {
        int x = winners[i];
        int y = winners[(i + 1) % winners.size()];
        result[x][y] = '+';
        result[y][x] = '-';
      }
      puts("YES");
      for (int i = 0; i < n; ++i) {
        puts(result[i]);
      }
    }
  }
}