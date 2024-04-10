#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int down = n - m + 1;
    int up = m - down;
    for (int i = 1; i <= up; ++i) {
      printf("%d ", i);
    }
    for (int i = 0; i < down; ++i) {
      printf("%d ", m - i);
    }
    puts("");
  }
}