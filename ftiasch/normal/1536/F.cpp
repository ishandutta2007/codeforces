#include <bits/stdc++.h>

namespace {

static const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

struct Binom {
  Binom(int n) : fact(n + 1), inv_fact(n + 1) {
    fact[0] = inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv_fact[i] = 1LL * (MOD - MOD / i) * inv_fact[MOD % i] % MOD;
    }
    for (int i = 1; i <= n; ++i) {
      fact[i] = 1LL * fact[i - 1] * i % MOD;
      inv_fact[i] = 1LL * inv_fact[i - 1] * inv_fact[i] % MOD;
    }
  }

  int operator()(int n, int k) {
    return k > n ? 0
                 : 1LL * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
  }

  std::vector<int> fact, inv_fact;
};

} // namespace

int main() {
  int n;
  scanf("%d", &n);
  Binom binom{n};
  int result = 0;
  for (int x = 0; x < n; x += 2) {
    add(result, 1LL * (binom(x, n - x) + binom(x - 1, n - x - 1)) *
                    binom.fact[x] % MOD);
  }
  if (~n & 1) {
    add(result, binom.fact[n]);
  }
  add(result, result);
  printf("%d\n", result);
}