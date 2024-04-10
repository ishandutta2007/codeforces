#include <bits/stdc++.h>

const int N = 20;
const int M = 50'000;
const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int n, m, d[M][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", d[j] + i);
    }
  }
  int result = 0;
  int fact = 1;
  for (int i = 1; i <= n; ++i) {
    fact = 1LL * fact * i % MOD;
  }
  for (int j = 0; j < m; ++j) {
    std::sort(d[j], d[j] + n);
    int prod = 1;
    for (int i = 0; i < n; ++i) {
      prod = 1LL * prod * std::max(d[j][i] - 1 - i, 0) % MOD;
    }
    add(result, fact);
    add(result, MOD - prod);
  }
  printf("%d\n", static_cast<int>(1LL * result * inv(fact) % MOD));
}