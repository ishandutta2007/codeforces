#include <bits/stdc++.h>

const int N = 250000;

int fact[N + 1];

int main() {
  int n, p, result = 0;
  scanf("%d%d", &n, &p);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % p;
  }
  for (int i = 1; i <= n; ++i) {
    result += (n - i + 1LL) * (n - i + 1LL) % p * fact[i] % p * fact[n - i] % p;
    if (result >= p) {
      result -= p;
    }
  }
  printf("%d\n", result);
}