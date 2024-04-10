#include <bits/stdc++.h>

const int N = 200000;
const int M = 17;

int n, m, count[N + 1][M + 1], next[N + 1][M], dp[1 << M];
char s[N + 1];

bool check(int limit) {
  for (int j = 0; j < m; ++j) {
    next[n][j] = n;
  }
  for (int i = n; i--;) {
    memcpy(next[i], next[i + 1], sizeof(next[i]));
    if (i + limit <= n) {
      for (int j = 0; j < m; ++j) {
        if (count[i][j] - count[i + limit][j] + count[i][m] -
                count[i + limit][m] ==
            limit) {
          next[i][j] = i;
        }
      }
    }
  }
  dp[0] = 0;
  for (int mask = 1; mask < 1 << m; ++mask) {
    dp[mask] = n + 1;
  }
  for (int mask = 0; mask < 1 << m; ++mask) {
    int begin = dp[mask];
    if (begin < n) {
      for (int j = 0; j < m; ++j) {
        if ((~mask >> j & 1) && next[begin][j] < n) {
          int new_mask = mask | 1 << j;
          dp[new_mask] = std::min(dp[new_mask], next[begin][j] + limit);
        }
      }
    }
  }
  return dp[(1 << m) - 1] <= n;
}

int main() {
  scanf("%d%d%s", &n, &m, s);
  for (int i = n; i--;) {
    memcpy(count[i], count[i + 1], sizeof(count[i]));
    if (s[i] == '?') {
      count[i][m]++;
    } else {
      count[i][s[i] - 'a']++;
    }
  }
  int low = 0;
  int high = n / m;
  while (low < high) {
    int middle = low + high + 1 >> 1;
    if (check(middle)) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  printf("%d\n", low);
}