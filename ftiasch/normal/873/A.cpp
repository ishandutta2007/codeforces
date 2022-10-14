#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  int result = k * x;
  for (int i = 0, a; i < n - k; ++i) {
    scanf("%d", &a);
    result += a;
  }
  printf("%d\n", result);
}