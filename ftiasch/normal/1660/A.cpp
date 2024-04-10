#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int result = [&]() -> int {
      if (a == 0) {
        return 1;
      }
      return a + 2 * b + 1;
    }();
    printf("%d\n", result);
  }
}