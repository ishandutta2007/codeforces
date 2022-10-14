#include <bits/stdc++.h>

const int N = 2'000;

char s[N][N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int all_ones = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%s", s[i]);
      all_ones += std::count(s[i], s[i] + n, '1');
    }
    int result = n * n;
    for (int offset = 0; offset < n; ++offset) {
      int diag_ones = 0;
      for (int i = 0; i < n; ++i) {
        diag_ones += s[i][(offset + i) % n] == '1';
      }
      result = std::min(result, all_ones - diag_ones + (n - diag_ones));
    }
    printf("%d\n", result);
  }
}