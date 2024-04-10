#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long result = 0;
  std::vector<int> diff(n - 1);
  for (int i = 0, last = -1, a; i < n; ++i) {
    scanf("%d", &a);
    if (i == 0) {
      result -= a;
    }
    if (i + 1 == n) {
      result += a;
    }
    if (~last) {
      diff[i - 1] = last - a;
    }
    last = a;
  }
  std::nth_element(diff.begin(), diff.begin() + (m - 1), diff.end());
  result += std::accumulate(diff.begin(), diff.begin() + (m - 1), 0LL);
  printf("%lld\n", result);
}