#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n;
long long a[N], b[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld%lld", a + i, b + i);
    }
    long long sum = 0;
    for (int i = 1; i < n; ++i) {
      sum += std::max(a[i] - b[i - 1], 0LL);
    }
    long long result = a[0] + sum;
    for (int i = 1; i < n; ++i) {
      sum -= std::max(a[i] - b[i - 1], 0LL);
      sum += std::max(a[i - 1] - b[(i - 2 + n) % n], 0LL);
      result = std::min(result, sum + a[i]);
    }
    printf("%lld\n", result);
  }
}