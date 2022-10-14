#include <bits/stdc++.h>

const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int inverse(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inverse(MOD % a) % MOD;
}

const int N = 50;

int binom[N + 1][N + 1], ifact[N + 1];

int sub_count(long long lis, const long long *steps, const long long *y,
              int n) {
  //   printf("n=%d\n", n);
  static int dp[N], cross_ways[N + 1];
  // y[0] (steps[0]) y[1] ... (steps[n - 1]) y[n]
  if (n <= 0) {
    return 0;
  }
  std::vector<long long> yvalues;
  for (int i = 0; i <= n; ++i) {
    yvalues.push_back(y[i]);
  }
  std::sort(yvalues.begin(), yvalues.end());
  yvalues.erase(std::unique(yvalues.begin(), yvalues.end()), yvalues.end());
  if (yvalues.back() - yvalues.front() + 1 != lis) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    dp[i] = y[i] == yvalues[0];
  }
  // n <= 50
  // n segments
  // (n + 1) points
  for (int yindex = 1; yindex < static_cast<int>(yvalues.size()); ++yindex) {
    long long ydelta = yvalues[yindex] - yvalues[yindex - 1] - 1;
    for (int crosses = 1; crosses <= n; crosses += 2) {
      cross_ways[crosses] = 0;
    }
    for (int d = 0; d <= (n >> 1) && d <= ydelta; ++d) {
      int y0 = (ydelta + MOD - d) % MOD;
      int numerator = 1;
      for (int crosses = 1; crosses <= n; crosses += 2) {
        int ups = (crosses + 1) >> 1;
        int downs = crosses >> 1;
        if (d <= downs) {
          add(cross_ways[crosses],
              1LL * numerator * ifact[ups - 1] % MOD * binom[downs][d] % MOD);
        }
        numerator = 1LL * numerator * (y0 + ups) % MOD;
      }
    }
    // printf("y=%lld\n", yvalues[yindex]);
    for (int j = n; j--;) {
      bool contained_j;
      if (steps[j] > 0) {
        contained_j = y[j] <= yvalues[yindex] && yvalues[yindex] <= y[j + 1];
      } else {
        contained_j = y[j] > yvalues[yindex] && yvalues[yindex] > y[j + 1];
      }
      //   printf("\tj=%d contained=%d\n", j, contained_j);
      if (contained_j) {
        int crosses = 0;
        int result = 0;
        for (int i = j; i >= 0; --i) {
          if (steps[i] > 0) {
            crosses += 2 * y[i] < 2 * yvalues[yindex] - 1 &&
                       2 * yvalues[yindex] - 1 < 2 * y[i + 1];
            // if (dp[i]) {
            //   printf("\t\t%d->%d crosses=%d\n", i, j, crosses);
            // }
            add(result, 1LL * dp[i] * cross_ways[crosses] % MOD);
          } else {
            // if (dp[i]) {
            //   printf("\t\t%d->%d crosses=%d\n", i, j, crosses);
            // }
            add(result, 1LL * dp[i] * cross_ways[crosses] % MOD);
            if (i < j) {
              crosses += 2 * y[i] > 2 * yvalues[yindex] - 1 &&
                         2 * yvalues[yindex] - 1 > 2 * y[i + 1];
            }
          }
        }
        dp[j] = result;
      } else {
        dp[j] = 0;
      }
    }
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    add(result, dp[i]);
  }
  return result;
}

int main() {
  for (int i = 0; i <= N; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  ifact[0] = 1;
  for (int i = 1; i <= N; ++i) {
    ifact[i] = 1LL * ifact[i - 1] * inverse(i) % MOD;
  }
  static long long steps[N], y[N + 2];
  int n0;
  while (scanf("%d%*d", &n0) == 1) {
    int n = 0;
    while (n0--) {
      int x;
      scanf("%d", &x);
      if (x != 0) {
        if (n && (steps[n - 1] >= 0) == (x >= 0)) {
          steps[n - 1] += x;
        } else {
          steps[n++] = x;
        }
      }
    }
    y[0] = 0;
    for (int i = 0; i < n; ++i) {
      y[i + 1] = y[i] + steps[i];
    }
    long long lis = 1;
    {
      long long min_y = 0;
      for (int i = 1; i <= n; ++i) {
        lis = std::max(lis, y[i] - min_y + 1);
        min_y = std::min(min_y, y[i]);
      }
    }
    if (lis == 1) {
      int ways = 1;
      for (int i = 0; i < n; ++i) {
        add(ways, std::abs(steps[i]) % MOD);
      }
      printf("1 %d\n", ways);
      continue;
    }
    int result = 0;
    for (int i0 = 0, i = 1; i <= n + 1; ++i) {
      if (i == n + 1 || y[i] < y[i0]) {
        add(result, sub_count(lis, steps + i0, y + i0, i - i0 - 1));
        i0 = i;
      }
    }
    printf("%lld %d\n", lis, result);
  }
}