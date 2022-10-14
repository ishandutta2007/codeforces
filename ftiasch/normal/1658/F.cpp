#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<char> s(n + 1);
    scanf("%s", s.data());
    std::vector<int> sum((n << 1) + 1);
    for (int i = n << 1; i--;) {
      sum[i] = (s[i % n] - '0') + sum[i + 1];
    }
    if (1LL * sum[n] * m % n != 0) {
      puts("-1");
    } else {
      int target = 1LL * sum[n] * m / n;
      for (int i = 0; i < n; ++i) {
        if (sum[i] - sum[(i + m)] == target) {
          if (i + m <= n) {
            printf("1\n%d %d\n", i + 1, i + m);
          } else {
            printf("2\n1 %d\n%d %d\n", i + m - n, i + 1, n);
          }
          break;
        }
      }
    }
  }
}