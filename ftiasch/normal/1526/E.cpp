#include <bits/stdc++.h>

const int MOD = 998244353;

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> sa(n), rank(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &sa[i]);
    rank[sa[i]] = i;
  }
  rank[n] = -1;
  for (int i = 0; i + 1 < n; ++i) {
    if (rank[sa[i] + 1] < rank[sa[i + 1] + 1]) {
      k++;
    }
  }
  long long numer = 1, denom = 1;
  for (int i = 0; i < n; ++i) {
    (numer *= k - i) %= MOD;
    (denom *= i + 1) %= MOD;
  }
  printf("%d\n", static_cast<int>(numer * inv(denom) % MOD));
}