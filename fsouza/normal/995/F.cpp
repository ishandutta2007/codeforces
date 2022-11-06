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

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p - 2, p); }

const int mod = 1e9 + 7;
const int maxn = 3000;

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

int dp[maxn][maxn + 1];
vector<int> children[maxn];

void dfs(int v, int n) {
  for (int u : children[v])
    dfs(u, n);

  dp[v][0] = 0;
  for (int d = 1; d <= n; ++d) {
    int res = 1;
    for (int u : children[v])
      res = (lint)res * dp[u][d] % mod;

    res += dp[v][d - 1];
    if (res >= mod) res -= mod;

    dp[v][d] = res;
  }
}

int dp2[maxn + 1];

int main() {
  prepare_binom(maxn);

  int n, big_d;
  scanf("%d %d", &n, &big_d);
  for (int i = 1; i < n; ++i) {
    int parent;
    scanf("%d", &parent), --parent;
    children[parent].push_back(i);
  }
  dfs(0, n);

  for (int i = 0; i <= n; ++i)
    dp2[i] = dp[0][i];

  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < i; ++j) {
      dp2[i] = (dp2[i] - (lint)binom(i, j) * dp2[j]) % mod;
      if (dp2[i] < 0) dp2[i] += mod;
    }

  int binom_big_d_i = 1;

  int result = 0;
  for (int i = 1; i <= min(n, big_d); ++i) {
    binom_big_d_i = (lint)binom_big_d_i * (big_d - i + 1) % mod;
    binom_big_d_i = (lint)binom_big_d_i * inv(i, mod) % mod;
    result = (result + (lint)binom_big_d_i * dp2[i]) % mod;
  }
  printf("%d\n", result);

  return 0;
}