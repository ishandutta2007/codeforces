#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;
const int B = 318;

int n, a[N], result, count[N + B * (N - 1) + 1], dp[N][B + 1];

void work_small_d() {
  for (int d = 0; d <= B; ++d) {
    for (int i = 0; i < n; ++i) {
      result = std::max(result, ++count[a[i] + i * d]);
    }
    for (int i = 0; i < n; ++i) {
      count[a[i] + i * d]--;
    }
  }
}

void work_large_d() {
  for (int i = 0; i < n; ++i) {
    for (int k = 1; k <= B && i + k < n; ++k) {
      count[N + (a[i + k] - a[i]) / k] = INT_MIN;
    }
    for (int j = std::max(i - B, 0); j < i; ++j) {
      int d = (a[i] - a[j]) / (i - j);
      count[N + d] = std::max(count[N + d], dp[j][i - j]);
    }
    for (int k = 1; k <= B && i + k < n; ++k) {
      dp[i][k] = INT_MIN;
      int j = i + k;
      if ((a[j] - a[i]) % k == 0) {
        int d = (a[j] - a[i]) / k;
        dp[i][k] = std::max(2, count[N + d] + 1);
        result = std::max(result, dp[i][k]);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  result = 1;
  work_small_d();
  std::reverse(a, a + n);
  work_small_d();
  work_large_d();
  printf("%d\n", n - result);
}