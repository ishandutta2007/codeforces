#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    if (n & 1) {
      int diff = 1 + 2 * (k % (n >> 1));
      printf("%d\n", (diff + (n - 1 - k % n)) % n + 1);
    } else {
      printf("%d\n", k % n + 1);
    }
  }
}