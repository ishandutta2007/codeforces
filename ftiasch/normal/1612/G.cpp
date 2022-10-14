#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = *std::max_element(a.begin(), a.end());
  std::vector<int> cnt(m + 1);
  for (int i = 0; i < n; ++i) {
    cnt[a[i]]++;
  }
  for (int i = m - 2; i >= 0; --i) {
    cnt[i] += cnt[i + 2];
  }
  std::vector<int> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
  }
  int sum = 0, result = fact[cnt[1]], length = cnt[1];
  for (int i = 2; i <= m; ++i) {
    add(sum, (i - 1LL) * cnt[i] % MOD * (length + cnt[i]) % MOD);
    result = 1LL * result * fact[cnt[i]] % MOD * fact[cnt[i]] % MOD;
    add(length, 2 * cnt[i]);
  }
  printf("%d %d\n", sum, result);
}