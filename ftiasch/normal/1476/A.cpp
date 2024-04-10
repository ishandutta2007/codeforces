#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", (1LL * n + (n + k - 1) / k * k - 1) / n);
  }
}