#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int const MOD = 1e9 + 7;
  auto add = [MOD](int x, int y) {
    x += y;
    if (x >= MOD) {
      x -= MOD;
    }
    return x;
  };
  auto mul = [MOD](int x, int y) {
    return static_cast<int>(1LL * x * y % MOD);
  };

  vector<int> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = mul(2, pw[i - 1]);
  }

  auto is_prime = [](int x) {
    for (int p = 2; p < x; ++p) {
      if (!(x % p)) {
        return false;
      }
    }
    return true;
  };

  vector<int> primes;
  int const MAX = 70;
  for (int p = 2; p <= MAX; ++p) {
    if (is_prime(p)) {
      primes.push_back(p);
    }
  }
  int nprimes = (int) primes.size();

  vector<int> basis(nprimes);
  int sz = 0;
  auto to_mask = [&](int x) {
    int y = 0;
    for (int i = 0; i < nprimes; ++i) {
      int d = 0;
      while (!(x % primes[i])) {
        x /= primes[i];
        d ^= 1;
      }
      if (d) {
        y |= (1 << i);
      }
    }
    return y;
  };
  auto insert = [&](int x) {
    x = to_mask(x);
    for (int i = 0; i < nprimes; ++i) {
      if (!(x & (1 << i))) {
        continue;
      }
      if (!basis[i]) {
        basis[i] = x;
        ++sz;
        return;
      }
      x ^= basis[i];
    }
  };
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    insert(x);
  }
  auto result = (pw[n - sz] - 1 + MOD) % MOD;
  cout << result << '\n';
  return 0;
}