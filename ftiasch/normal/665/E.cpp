#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, limit;
  scanf("%d%d", &n, &limit);
  std::vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i--;) {
    a[i] ^= a[i + 1];
  }
  std::sort(a.begin(), a.end());
  limit--;
  long long result = 0;
  for (int j = 30; j--;) {
    if (~limit >> j & 1) {
      for (int i = 0; i <= n; ++i) {
        int low = (a[i] ^ limit ^ (1 << j)) & ~((1 << j) - 1);
        result += std::lower_bound(a.begin(), a.end(), low + (1 << j)) -
                  std::lower_bound(a.begin(), a.end(), low);
      }
    }
  }
  printf("%lld\n", result >> 1);
}