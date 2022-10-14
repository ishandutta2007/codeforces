#include <bits/stdc++.h>

const int N = 2021;
const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

struct Solver {
  int gen(int num, int len, int sum) {
    if (!num) {
      return 0;
    }
    int result = gen(num - 1, len, sum);
    while (len < n) {
      sum += (lst[2][len++] = num);
      if (sum <= n && check(len, sum)) {
        result += 1 + gen(num - 1, len, sum);
      } else {
        break;
      }
    }
    return result;
  }

  bool check(int len, int sum) {
    memcpy(lst[m & 1], lst[2], sizeof(int) * len);
    for (int k = m; k > 1; --k) {
      int oldlen = len, start = sum;
      len = sum, sum = 0;
      for (int i = 0; i < oldlen; ++i) {
        for (int j = 0; j < lst[k & 1][i] && sum <= n; ++j) {
          assert(start);
          sum += (lst[k + 1 & 1][--start] = i + 1);
        }
      }
      if (sum > n) {
        return false;
      }
    }
    return true;
  }

  int n, m, lst[3][N];
};

int solve(int n, int m) {
  if (m == 1) {
    static int dp[N];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        add(dp[j], dp[j - i]);
      }
    }
    int result = 0;
    for (int i = 1; i <= n; ++i) {
      add(result, dp[i]);
    }
    return result;
  }
  if (m == 2) {
    static int dp[N][N];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = n; i; --i) {
      for (int j = 1; i * j <= n; ++j) {
        for (int s = i * j; s <= n; ++s) {
          add(dp[j][s], dp[j - 1][s - i * j]);
        }
      }
    }
    int result = 0;
    for (int j = 1; j <= n; ++j) {
      for (int s = 1; s <= n; ++s) {
        add(result, dp[j][s]);
      }
    }
    return result;
  }
  return Solver{n, m}.gen(n, 0, 0);
}

int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    printf("%d\n", solve(n, k));
  }
}