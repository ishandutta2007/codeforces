#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", (std::max(n, m) * 2 - 1) + (n == m));
  }
}