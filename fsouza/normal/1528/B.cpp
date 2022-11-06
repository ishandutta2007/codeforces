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

const int mod = 998244353;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> dp(n + 1), acc_dp(n + 1);
  dp[0] = 1;
  acc_dp[0] = dp[0];
  for (int i = 1; i <= n; ++i) {
    dp[i] = acc_dp[i - 1];
    if (dp[i] >= mod) dp[i] -= mod;
    acc_dp[i] = acc_dp[i - 1] + dp[i];
    if (acc_dp[i] >= mod) acc_dp[i] -= mod;
  }

  int result = 0;
  for (int a = 1; a <= n; ++a)
    for (int b = 1; a * b <= n; ++b) {
      int remain = n - a * b;
      result += dp[remain];
      if (result >= mod) result -= mod;
    }
  printf("%d\n", result);

  return 0;
}