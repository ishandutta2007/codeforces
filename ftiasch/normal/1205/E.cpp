#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int power(int a, int n) {
  int result = 1;
  while (n) {
    if (n & 1) {
      result = 1LL * result * a % MOD;
    }
    a = 1LL * a * a % MOD;
    n >>= 1;
  }
  return result;
}

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 100000;

int mu[N], mpowers[N], minvs[N];
std::vector<int> divs[N], sfdivs[N];

int gsum(int g, int n) { return (1LL + MOD - mpowers[g * n]) * minvs[g] % MOD; }

int main() {
  mu[1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divs[j].push_back(i);
      if (mu[i]) {
        sfdivs[j].push_back(i);
      }
    }
    for (int j = i + i; j < N; j += i) {
      mu[j] -= mu[i];
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  if (m == 1) {
    printf("%d\n", (int)(1LL * (n - 1) * (n - 1) % MOD));
  } else {
    mpowers[0] = 1;
    for (int i = 1; i < n; ++i) {
      mpowers[i] = 1LL * mpowers[i - 1] * m % MOD;
      minvs[i] = 1LL * mpowers[i] * power(1 + MOD - mpowers[i], MOD - 2) % MOD;
    }
    int inv_kn = power(m, 1LL * n * (MOD - 2) % (MOD - 1));
    int result = 1LL * power(gsum(1, n - 1), 2) * inv_kn % MOD;
    for (int p = 1; p < n; ++p) {
      for (int g : divs[p]) {
        int le_count = 0, le_sum = 0;
        for (int _ : sfdivs[p / g]) {
          int gg = g * _;
          int count = std::min(n - 1, n + g - p) / gg;
          le_count += mu[_] * count;
          int sum = gsum(gg, count);
          add(le_sum, mu[_] > 0 ? sum : MOD - sum);
        }
        add(result, 1LL * le_count * mpowers[g] % MOD);
        add(result, MOD - 1LL * le_sum * mpowers[p] % MOD * inv_kn % MOD);
      }
    }
    printf("%d\n", (int)(1LL * result * inv_kn % MOD));
  }
}