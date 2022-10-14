#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    // int x = 0;
    // while ((x ^ n) <= m) {
    //   x++;
    // }
    int result = INT_MAX;
    for (int i = 30; i--;) {
      if (~m >> i & 1) {
        result = std::min(result, (n ^ m ^ (1 << i)) & ~((1 << i) - 1));
      }
    }
    printf("%d\n", result);
  }
}