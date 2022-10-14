#include <bits/stdc++.h>

const int N = 50000;

int r[N][5];

int cmp(int i, int j) {
  int result = 0;
  for (int k = 0; k < 5; ++k) {
    if (r[i][k] < r[j][k]) {
      result++;
    }
  }
  return result > 2;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        scanf("%d", r[i] + j);
      }
    }
    int winner = 0;
    for (int i = 1; i < n; ++i) {
      if (!cmp(winner, i)) {
        winner = i;
      }
    }
    for (int i = 0; i < n && ~winner; ++i) {
      if (winner != i && !cmp(winner, i)) {
        winner = -1;
      }
    }
    printf("%d\n", ~winner ? winner + 1 : -1);
  }
}