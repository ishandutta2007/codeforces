#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int t;
      scanf("%d", &t);
      result += t != 2;
    }
    printf("%d\n", result);
  }
}