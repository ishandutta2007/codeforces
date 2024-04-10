#line 1 "sol.cpp"
#include <bits/stdc++.h>

int solve(int n) {
  if (n % 7 == 0) {
    return n;
  }
  n -= n % 10;
  for (int r = 0; r < 9; ++r) {
    if ((n + r) % 7 == 0) {
      return n + r;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
  }
}