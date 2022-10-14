#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 360;

int result[N];

int main() {
  for (int n = N; n >= 3; --n) {
    for (int d = 1; d < n - 1; ++d) {
      if (180 * d % n == 0) {
        result[180 * d / n] = n;
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int a;
    scanf("%d", &a);
    printf("%d\n", result[a]);
  }
}