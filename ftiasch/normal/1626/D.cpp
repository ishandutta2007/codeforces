#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'001;

int n, sum[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    std::fill(sum, sum + (n + 1), 0);
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      sum[a]++;
    }
    for (int i = 1; i <= n; ++i) {
      sum[i] += sum[i - 1];
    }
    int result = INT_MAX;
    for (int p1 = 1; (p1 >> 1) < n; p1 <<= 1) {
      int i =
          static_cast<int>(std::upper_bound(sum, sum + (n + 1), p1) - sum) - 1;
      // sum[i] - sum[0] <= p1
      for (int p2 = 1; (p2 >> 1) < n; p2 <<= 1) {
        int j = static_cast<int>(
                    std::upper_bound(sum, sum + (n + 1), sum[i] + p2) - sum) -
                1;
        // sum[j] - sum[i] <= p2
        int p3 = 1;
        while (sum[n] - sum[j] > p3) {
          p3 <<= 1;
        }
        result = std::min(result, p1 + p2 + p3 - sum[n]);
      }
    }
    printf("%d\n", result);
  }
}