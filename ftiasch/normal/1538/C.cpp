#include <bits/stdc++.h>

long long solve(int n, const std::vector<int> &a, int bound) {
  long long result = 0;
  for (int i = 0, j = n - 1; i < j; ++i) {
    while (a[i] + a[j] > bound && i < j) {
      j--;
    }
    result += j - i;
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, lo, hi;
    scanf("%d%d%d", &n, &lo, &hi);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    printf("%lld\n", solve(n, a, hi) - solve(n, a, lo - 1));
  }
}