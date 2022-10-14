#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 200'000;

int n;
Long x, y, a[N];

int get_exp(Long p, Long x) {
  int e = 0;
  while (x % p == 0) {
    e++;
    x /= p;
  }
  return e;
}

Long solve() {
  if (y % x != 0) {
    return 0;
  }
  // x | y
  std::vector<Long> primes;
  {
    Long t = y;
    for (Long p = 2; p * p <= t && p <= 1'000'000; ++p) {
      if (t % p == 0) {
        primes.push_back(p);
        while (t % p == 0) {
          t /= p;
        }
      }
    }
    // t = p, p^2, p * q
    if (t > 1) {
      Long r = std::sqrt(t) + 2;
      while (r * r > t) {
        r--;
      }
      if (r * r == t) {
        primes.push_back(r);
        t = 1;
      }
    }
    // t = p, p * q
    for (int i = 0; i <= n && t > 1; ++i) {
      Long u = i < n ? a[i] : x;
      Long g = std::__gcd(u, t);
      if (g != 1 && g != t) {
        primes.push_back(g);
        primes.push_back(t / g);
        t = 1;
      }
    }
    if (t > 1) {
      primes.push_back(t);
    }
  }
  {
    std::vector<Long> nprimes;
    for (auto p : primes) {
      if (get_exp(p, x) < get_exp(p, y)) {
        nprimes.push_back(p);
      }
    }
    primes.swap(nprimes);
  }
  int m = primes.size();
  std::vector<int> xexp(m), yexp(m), aexp(m), xcount(1 << m), ycount(1 << m);
  for (int i = 0; i < m; ++i) {
    xexp[i] = get_exp(primes[i], x);
    yexp[i] = get_exp(primes[i], y);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      aexp[j] = get_exp(primes[j], a[i]);
    }
    if (a[i] % x == 0) {
      int xmask = 0;
      for (int j = 0; j < m; ++j) {
        xmask |= (aexp[j] > xexp[j]) << j;
      }
      xcount[xmask]++;
    }
    if (y % a[i] == 0) {
      int ymask = 0;
      for (int j = 0; j < m; ++j) {
        ymask |= (aexp[j] < yexp[j]) << j;
      }
      ycount[ymask]++;
    }
  }
  Long result = 0;
  for (int xmask = 0; xmask < 1 << m; ++xmask) {
    int comp = ((1 << m) - 1) ^ xmask;
    for (int ymask = comp;; ymask = (ymask - 1) & comp) {
      result += 1LL * xcount[xmask] * ycount[ymask];
      if (ymask == 0) {
        break;
      }
    }
  }
  return result;
}

int main() {
  scanf("%d%lld%lld", &n, &x, &y);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }
  printf("%lld\n", solve());
}