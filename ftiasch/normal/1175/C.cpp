#include <bits/stdc++.h>

const int N = 200'000;

int a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::pair<int, int> result{INT_MAX, 0};
    for (int i = k; i < n; ++i) {
      result = std::min(result, {
                                    (a[i] - a[i - k] + 1) >> 1,
                                    (a[i] + a[i - k]) >> 1,
                                });
    }
    printf("%d\n", result.second);
  }
}