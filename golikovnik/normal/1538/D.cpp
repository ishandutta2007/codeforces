//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

#ifndef MODMUL64_H
#define MODMUL64_H
i64 modmul64(i64 x, i64 y, i64 p) {
  ui64 q = (long double) x * y / p;
  i64 res = i64(ui64(x) * y - q * p);
  if (res >= p) res -= p;
  if (res < 0) res += p;
  return res;
}
#endif

namespace factorization {
  i64 pw(i64 a, i64 n, i64 p) {
    i64 res = 1;
    while (n) {
      if (n & 1) res = modmul64(res, a, p);
      a = modmul64(a, a, p);
      n >>= 1;
    }
    return res;
  }

  bool check_composite(i64 n, int s, i64 d, i64 a) {
    i64 x = pw(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int it = 1; it < s; ++it) {
      x = modmul64(x, x, n);
      if (x == n - 1) return false;
    }
    return true;
  }

  bool is_prime(i64 n) {
    if (n < 4) return n > 1;
    int s = 0;
    i64 d = n - 1;
    while (!(d & 1)) {
      d >>= 1;
      ++s;
    }
    static vector<i64> primes32{2, 7, 61};
    static vector<i64> primes64{2, 325, 9375, 28178, 450775, 9780504,
                                1795265022};
    static i64 const BOUND = i64(4759123141ll);
    for (i64 a : (n <= BOUND ? primes32 : primes64)) {
      if (n == a) return true;
      if (check_composite(n, s, d, a)) return false;
    }
    return true;
  }

  i64 find_divisor(i64 n, int c = 2) {
    auto f = [&](i64 x) {
      auto r = modmul64(x, x, n) + c;
      if (r >= n) r -= n;
      return r;
    };
    i64 x = c;
    i64 g = 1;
    i64 q = 1;
    i64 xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
      y = x;
      for (int i = 1; i < l; ++i) {
        x = f(x);
      }
      int k = 0;
      while (k < l && g == 1) {
        xs = x;
        for (int i = 0; i < m && i < l - k; ++i) {
          x = f(x);
          q = modmul64(q, llabs(y - x), n);
        }
        g = gcd(q, n);
        k += m;
      }
      l *= 2;
    }
    if (g == n) {
      do {
        xs = f(xs);
        g = gcd(llabs(xs - y), n);
      } while (g == 1);
    }
    return g == n ? find_divisor(n, c + 1) : g;
  }

  vector<pair<i64, int>> factorize(i64 m) {
    if (m == 1) {
      return {};
    }
    vector<i64> fac;
    auto rec = [&fac](auto&& rec, i64 m) -> void {
      if (is_prime(m)) {
        fac.push_back(m);
        return;
      }
      auto d = m % 2 == 0 ? 2 : find_divisor(m);
      rec(rec, d);
      rec(rec, m / d);
    };
    rec(rec, m);
    sort(fac.begin(), fac.end());
    vector<pair<i64, int>> ans;
    for (auto x : fac) {
      if (ans.empty() || ans.back().first != x) {
        ans.emplace_back(x, 0);
      }
      ++ans.back().second;
    }
    return ans;
  }
}
using factorization::factorize;
using factorization::is_prime;

int const BOUND = 1005;
bool is_prime_pre[BOUND];
vector<int> primes;

int getSum(int x) {
  int res = 0;
  for (int p : primes) {
    if (p * p * p > x) {
      break;
    }

    while (x % p == 0) {
      x /= p;
      ++res;
    }
  }
  return res + (x > 1) * (2 - is_prime(x));
}

void solve(int) {
  int a, b, k;
  cin >> a >> b >> k;
  int sa = getSum(a);
  int sb = getSum(b);

  if (k == 0) {
    cout << (a == b ? "Yes" : "No") << '\n';
    return;
  }
  if (k == 1) {
    cout << (a != b && (a % b == 0 || b % a == 0) ? "Yes" : "No") << '\n';
    return;
  }

  int mx = sa + sb;
  cout << (k <= mx ? "Yes" : "No") << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(is_prime_pre + 2, is_prime_pre + BOUND, true);
  for (int p = 2; p < BOUND; ++p) {
    if (is_prime_pre[p]) {
      primes.push_back(p);
      for (int p2 = p + p; p2 < BOUND; p2 += p) {
        is_prime_pre[p2] = false;
      }
    }
  }

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}