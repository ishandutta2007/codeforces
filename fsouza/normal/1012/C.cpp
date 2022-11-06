#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 5000;

lint dp[maxn + 1][maxn + 1][2];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> h(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &h[i]);

  const int maxk = (n + 1) / 2;
  for (int k = 0; k <= maxk; ++k)
    for (int use = 0; use < 2; ++use)
      dp[n][k][use] = LLONG_MAX;
  dp[n][0][0] = 0LL;

  for (int i = n - 1; i >= 0; --i)
    for (int k = 0; k <= maxk; ++k)
      for (int use = 0; use < 2; ++use) {
        lint &result = dp[i][k][use];
        if (k == 0) {
          if (use == 0) result = 0;
          else result = LLONG_MAX;
        } else if (use == 0) {
          result = LLONG_MAX;
          if (dp[i + 1][k][0] != LLONG_MAX)
            result = min(result, dp[i + 1][k][0]);
          if (dp[i + 1][k][1] != LLONG_MAX) {
            result =
                min(result, dp[i + 1][k][1] + max(0, h[i] - (h[i + 1] - 1)));
          }
        } else if (use == 1) {
          if (i == n - 1) {
            result = dp[n][k - 1][0];
          } else {
            result = LLONG_MAX;
            int extra = max(0, h[i + 1] - (h[i] - 1));
            if (dp[i + 2][k - 1][0] != LLONG_MAX)
              result = min(result, dp[i + 2][k - 1][0] + extra);
            if (i + 2 < n) {
              extra = max(0, h[i + 1] - (min(h[i], h[i + 2]) - 1));
              if (dp[i + 2][k - 1][1] != LLONG_MAX)
                result = min(result, dp[i + 2][k - 1][1] + extra);
            }
          }
        } else {
          assert(false);
        }
      }

  for (int k = 1; k <= maxk; ++k) {
    if (k > 1) printf(" ");
    printf("%lld", min(dp[0][k][0], dp[0][k][1]));
  }
  printf("\n");

  return 0;
}