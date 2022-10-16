//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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
ll modmul64(ll x, ll y, ll p) {
  ull q = (long double) x * y / p;
  ll res = ll(ull(x) * y - q * p);
  if (res >= p) res -= p;
  if (res < 0) res += p;
  return res;
}
#endif

namespace factorization {
  ll pw(ll a, ll n, ll p) {
    ll res = 1;
    while (n) {
      if (n & 1) res = modmul64(res, a, p);
      a = modmul64(a, a, p);
      n >>= 1;
    }
    return res;
  }

  bool check_composite(ll n, int s, ll d, ll a) {
    ll x = pw(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int it = 1; it < s; ++it) {
      x = modmul64(x, x, n);
      if (x == n - 1) return false;
    }
    return true;
  }

  bool is_prime(ll n) {
    if (n < 4) return n > 1;
    if (n % 2 == 0) {
      return false;
    }
    if (n % 3 == 0) {
      return false;
    }
    if (n == 5) {
      return true;
    }
    if (n % 5 == 0) {
      return false;
    }
    int s = 0;
    ll d = n - 1;
    while (!(d & 1)) {
      d >>= 1;
      ++s;
    }
    static vector<ll> primes32{2, 7, 61};
    static vector<ll> primes64{2, 325, 9375, 28178, 450775, 9780504,
                                1795265022};
    static ll const BOUND = ll(4759123141ll);
    for (ll a : (n <= BOUND ? primes32 : primes64)) {
      if (n == a) return true;
      if (check_composite(n, s, d, a)) return false;
    }
    return true;
  }

  ll find_divisor(ll n, int c = 2) {
    auto f = [&](ll x) {
      auto r = modmul64(x, x, n) + c;
      if (r >= n) r -= n;
      return r;
    };
    ll x = c;
    ll g = 1;
    ll q = 1;
    ll xs, y;

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

  vector<pair<ll, int>> factorize(ll m) {
    assert(m > 0);
    if (m == 1) {
      return {};
    }
    vector<ll> fac;
    auto rec = [&fac](auto&& self, ll x) -> void {
      if (is_prime(x)) {
        fac.push_back(x);
        return;
      }
      auto d = x % 2 == 0 ? 2 : find_divisor(x);
      self(self, d);
      self(self, x / d);
    };
    rec(rec, m);
    sort(fac.begin(), fac.end());
    vector<pair<ll, int>> ans;
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

vector<ll> find_divisors(vector<pair<ll, int>> const& fac) {
  vector<ll> ans;
  int cnt = 1;
  for (auto it : fac) cnt *= (it.second + 1);
  ans.reserve(cnt);
  ans.push_back(1);
  for (auto[p, d] : fac) {
    int sz = int(ans.size());
    for (int i = 0; i < sz; ++i) {
      ll mul = 1;
      for (int j = 1; j <= d; ++j) {
        mul *= p;
        ans.push_back(ans[i] * mul);
      }
    }
  }
  assert(int(ans.size()) == cnt);
  return ans;
}

vector<ll> find_divisors(ll x) {
  return find_divisors(factorize(x));
}

ll getPhi(ll x, vector<pair<ll, int>> const& fac) {
  for (auto it : fac) {
    x /= it.first;
    x *= it.first - 1;
  }
  return x;
}

ll getPhi(ll x) {
  return getPhi(x, factorize(x));
}

void solveTest() {
  int w, h;
  cin >> w >> h;

  vector<int> divs;

  auto gen = [&](int d) {
    auto dd = find_divisors(d);
    divs.insert(divs.end(), dd.begin(), dd.end());
  };

  gen(gcd(w - 1, h - 1));
  gen(gcd(w, h - 2));
  gen(gcd(w - 2, h));
  gen(gcd(w, gcd(h - 1, w - 2)));
  gen(gcd(h, gcd(w - 1, h - 2)));
  sort(divs.begin(), divs.end());
  divs.erase(unique(divs.begin(), divs.end()), divs.end());
  cout << divs.size() << ' ';
  for (int x : divs) {
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}