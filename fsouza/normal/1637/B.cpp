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

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    vector<vector<int>> mexp1(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      const int max_mex = n + 3;
      vector<bool> has_value(max_mex, false);
      int mex = 0;
      for (int j = i; j < n; ++j) {
        if (values[j] < max_mex)
          has_value[values[j]] = true;
        while (has_value[mex]) ++mex;
        mexp1[i][j] = mex + 1;
      }
    }
    lint result = 0LL;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int s = 1; s <= n; ++s)
      for (int i = 0; i + s - 1 < n; ++i) {
        const int j = i + s - 1;

        dp[i][j] = mexp1[i][j];
        for (int k = i; k + 1 <= j; ++k)
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);

        result += dp[i][j];
      }
    printf("%lld\n", result);
  }
  return 0;
}