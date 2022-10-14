#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> h(n + 2);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &h[i]);
    }
    long long result = 0;
    for (int i = 1; i <= n + 1; ++i) {
      if (i <= n && h[i] > h[i - 1] && h[i] > h[i + 1]) {
        int new_h = std::max(h[i - 1], h[i + 1]);
        result += h[i] - new_h;
        h[i] = new_h;
      }
      result += std::abs(h[i] - h[i - 1]);
    }
    printf("%lld\n", result);
  }
}