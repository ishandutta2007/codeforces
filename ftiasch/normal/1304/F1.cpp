#include <bits/stdc++.h>

const int N = 50;
const int M = 20000;

void update(int &x, int a) { x = std::max(x, a); }

int n, m, window, a[N][M + 1], dp[2][M], queue[M];

int main() {
  while (scanf("%d%d%d", &n, &m, &window) == 3) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i] + j);
      }
      for (int j = m; j--;) {
        a[i][j] += a[i][j + 1];
      }
    }
    m -= window - 1;
    for (int j = 0; j < m; ++j) {
      dp[n - 1 & 1][j] = a[n - 1][j] - a[n - 1][j + window];
    }
    for (int i = n - 1; i--;) {
      memset(dp[i & 1], 0, sizeof(dp[i & 1]));
      {
        int head = 0, rear = 0, prefix_max = 0;
        auto cost = [&](int j) {
          return dp[i + 1 & 1][j] + a[i + 1][j + window];
        };
        for (int j = 0; j < m; ++j) {
          int row = a[i][j] - a[i][j + window];
          if (j >= window) {
            update(prefix_max, dp[i + 1 & 1][j - window]);
          }
          update(dp[i & 1][j],
                 prefix_max + a[i + 1][j] - a[i + 1][j + window] + row);
          while (head < rear && cost(queue[rear - 1]) <= cost(j)) {
            rear--;
          }
          queue[rear++] = j;
          while (head < rear && j - queue[head] > window) {
            head++;
          }
          update(dp[i & 1][j], cost(queue[head]) - a[i + 1][j + window] + row);
        }
      }
      {
        int head = 0, rear = 0, suffix_max = 0;
        auto cost = [&](int j) {
          return dp[i + 1 & 1][j] - a[i + 1][j];
        };
        for (int j = m; j--;) {
          int row = a[i][j] - a[i][j + window];
          if (j + window < m) {
            update(suffix_max, dp[i + 1 & 1][j + window]);
          }
          update(dp[i & 1][j],
                 suffix_max + a[i + 1][j] - a[i + 1][j + window] + row);
          while (head < rear && cost(queue[rear - 1]) <= cost(j)) {
            rear--;
          }
          queue[rear++] = j;
          while (head < rear && queue[head] - j > window) {
            head++;
          }
          update(dp[i & 1][j], cost(queue[head]) + a[i + 1][j] + row);
        }
      }
    }
    printf("%d\n", *std::max_element(dp[0], dp[0] + m));
  }
}