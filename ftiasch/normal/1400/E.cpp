#include <bits/stdc++.h>

const int N = 5'000;

int n, a[N];

int solve(int l, int r, int b) {
  if (l == r) {
    return 0;
  }
  int m = std::min_element(a + l, a + r) - a;
  int result = r - l;
  result =
      std::min(result, solve(l, m, a[m]) + solve(m + 1, r, a[m]) + (a[m] - b));
  return result;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  printf("%d\n", solve(0, n, 0));
}