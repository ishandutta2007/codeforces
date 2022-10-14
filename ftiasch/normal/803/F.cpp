#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100000;
const int MOD = 1'000'000'007;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, count[N + 1], mu[N + 1], power_of_two[N + 1];

int main() {
  scanf("%d", &n);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    count[a]++;
  }
  power_of_two[0] = 1;
  for (int i = 1; i <= n; ++i) {
    power_of_two[i] = power_of_two[i - 1] * 2 % MOD;
  }
  mu[1] = 1;
  int result = 0;
  for (int d = 1; d <= N; ++d) {
    if (mu[d]) {
      int sum = 0;
      for (int i = d; i <= N; i += d) {
        sum += count[i];
      }
      add(result, (power_of_two[sum] - 1LL) * mu[d] % MOD);
      for (int i = d + d; i <= N; i += d) {
        add(mu[i], MOD - mu[d]);
      }
    }
  }
  printf("%d\n", result);
}