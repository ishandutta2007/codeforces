#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 110;

int n;
int a[N];
char s[N];
ll dp[N][N][N * 2];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i)
    s[i] -= '0';
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  fill(**dp, dp[N - 1][N - 1] + N * 2, -1LL << 60);
  for (int i = 1; i <= n + 1; ++i)
    dp[i][i - 1][0] = 0;
  for (int len = 1; len <= n; ++len)
    for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
      for (int c = 0; c < 2; ++c)
        for (int x = 1; x <= len; ++x) {
          int q = c ? (n + x) : x;
          for (int e = 1; e + x <= len; ++e)
            dp[l][r][q] = max(dp[l][r][q], dp[l][l + e - 1][0] + dp[l + e][r][q]);
          if (s[l] == c)
            dp[l][r][q] = max(dp[l][r][q], dp[l + 1][r][(x == 1) ? 0 : (q - 1)]);
        }
      for (int i = 1; i <= n; ++i)
        dp[l][r][0] = max(dp[l][r][0], max(dp[l][r][i], dp[l][r][n + i]) + a[i]);
      /*for (int x = 0; x <= n * 2; ++x) {
        int i = l, j = r;
        if (dp[i][j][x] >= 0) {
          if (x == 0)
            LOG("%d %d %d: %lld\n", i, j, x, dp[i][j][x]);
          else if (x <= n)
            LOG("%d %d 0[%d]: %lld\n", i, j, x, dp[i][j][x]);
          else
            LOG("%d %d 1[%d]: %lld\n", i, j, x - n, dp[i][j][x]);
        }
      }*/
    }
  printf("%lld\n", dp[1][n][0]);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}