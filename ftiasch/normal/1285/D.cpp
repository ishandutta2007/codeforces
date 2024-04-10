#include <bits/stdc++.h>

const int N = 100000;

int n, a[N];

int solve(int i, int l, int r)
{
  if (i == -1) {
    return 0;
  }
  int m = l;
  while (m < r && (~a[m] >> i & 1)) {
    m ++;
  }
  if (m == l || m == r) {
    return solve(i - 1, l, r);
  }
  return std::min(solve(i - 1, l, m), solve(i - 1, m, r)) | 1 << i;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n);
  printf("%d\n", solve(29, 0, n));
}