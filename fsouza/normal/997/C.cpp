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

const int mod = 998244353, maxn = 1e6;

int modpow(int x, lint y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p - 2, p); }

vector<int> fact, inv_fact;

void prepare_binom(int lim) {
  fact.resize(lim + 1);
  fact[0] = 1;
  for (int i = 1; i <= lim; ++i)
    fact[i] = (lint)i * fact[i - 1] % mod;

  inv_fact.resize(lim + 1);
  inv_fact[lim] = inv(fact[lim], mod);
  for (int i = lim - 1; i >= 0; --i)
    inv_fact[i] = (lint)(i + 1) * inv_fact[i + 1] % mod;
}

int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (lint)fact[a] * inv_fact[b] % mod * inv_fact[a - b] % mod;
}

int main() {
  prepare_binom(maxn);

  int n;
  scanf("%d", &n);

  int result = 0;
  for (int nc = 1; nc <= n; ++nc) {
    int res = (lint)binom(n, nc) *
              modpow(3, (lint)n * n - (lint)n * nc + nc, mod) % mod;
    if (nc % 2 == 1) {
      result += res;
      if (result >= mod) result -= mod;
    } else {
      result -= res;
      if (result < 0) result += mod;
    }
  }
  result *= 2;
  if (result >= mod) result -= mod;

  int inv3 = inv(3, mod);

  for (int a = 1; a <= n; ++a) {
    int mult_by =
        (lint)binom(n, a) * modpow(3, (lint)n * n + 1 - (lint)a * n, mod) % mod;
    if (a % 2 == 1) {
      mult_by = mod - mult_by;
      if (mult_by >= mod) mult_by -= mod;
    }

    int k = modpow(inv3, n - a, mod) - 1;
    if (k < 0) k += mod;
    int res = modpow(k, n, mod);

    if (n % 2 == 0) {
      res = res - 1;
      if (res < 0) res += mod;
    } else {
      res = res + 1;
      if (res >= mod) res -= mod;
    }
    if (n % 2 == 1) {
      res = mod - res;
      if (res >= mod) res -= mod;
    }

    result = (result - (lint)res * mult_by) % mod;
    if (result < 0) result += mod;
  }

  printf("%d\n", result);

  return 0;
}