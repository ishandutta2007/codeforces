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

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

const int mod = 1e9 + 7;

int inv(int a, int p) { return modpow(a, p - 2, p); }

// K = 1.

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  const int lim = N + K;
  vector<int> fact(lim + 1);
  fact[0] = 1;
  for (int i = 1; i <= lim; ++i)
    fact[i] = (lint)i * fact[i - 1] % mod;

  vector<int> invfact(lim + 1);
  invfact[lim] = inv(fact[lim], mod);
  for (int i = lim - 1; i >= 0; --i)
    invfact[i] = (lint)(i + 1) * invfact[i + 1] % mod;

  auto seg_mult = [&](int a, int b) {
    int result = fact[b];
    if (a - 1 >= 0) result = (lint)result * invfact[a - 1] % mod;
    return result;
  };

  auto base_case = [&](int n) {
    if (n >= N)
      return 0;
    int result = seg_mult(n + 1, N) - seg_mult(n, N - 1);
    if (result < 0) result += mod;
    return result;
  };

  vector<int> dp(N + 1);
  dp[N] = 0;
  for (int n = N - 1; n >= 1; --n) {
    lint res = dp[n + 1];
    if (n + K + 1 < N) {
      res -= (lint)seg_mult(n + 1, n + K) * base_case(n + K + 1) % mod;
      if (res < 0) res += mod;
      res -= (lint)seg_mult(n + 1, n + K - 1) * dp[n + K + 1] % mod;
      res %= mod;
      if (res < 0) res += mod;
    }
    res = (lint)res * n % mod;
    res += dp[n + 1];
    if (n + K < N) {
      res += (lint)seg_mult(n, n + K - 1) * base_case(n + K) % mod;
    }
    res %= mod;
    if (res < 0) res += mod;
    dp[n] = res;
  }

  printf("%d\n", dp[1]);

  return 0;
}