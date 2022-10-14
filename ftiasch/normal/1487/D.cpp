#include <bits/stdc++.h>

int solve(int n) {
  // ((2k+1)^2 + 1) / 2 <= n
  // <=> (2k+1)^2 <= 2n - 1
  int s = (int)sqrt(2 * n - 1) + 1;
  while (s * s > 2 * n - 1) {
    s--;
  }
  return (s - 1) >> 1;
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