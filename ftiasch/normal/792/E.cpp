#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  long long result = std::numeric_limits<long long>::max();
  auto work = [&](int sz) {
    if (sz) {
      long long sum = 0;
      for (int a : a) {
        if (a % sz > a / sz) {
          return;
        }
        sum += (a + sz) / (sz + 1);
      }
      result = std::min(result, sum);
    }
  };

  int min_a = *std::min_element(a.begin(), a.end());
  for (int sz = 1; sz * sz <= min_a; ++sz) {
    work(sz);
    work(min_a / sz);
    work(min_a / sz - 1);
  }
  printf("%lld\n", result);
}