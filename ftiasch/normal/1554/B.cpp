#include <bits/stdc++.h>

const int N = 100000;

int n, m, a[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    long long result = std::numeric_limits<long long>::min();
    for (int j = n; j >= 1; --j) {
      for (int i = j - 1; i >= 1; --i) {
        if (1LL * i * j < result) {
          break;
        }
        result = std::max(result, 1LL * i * j - 1LL * m * (a[i] | a[j]));
      }
    }
    std::cout << result << std::endl;
  }
}