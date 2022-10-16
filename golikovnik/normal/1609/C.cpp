//  Copyright 2021 Nikita Golikov

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

void solveTest() {
  int n, e;
  cin >> n >> e;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  vector<set<int>> pos(e);
  for (int i = 0; i < n; ++i) {
    if (a[i] != 1) {
      pos[i % e].insert(i);
    }
  }

  vector<int> lastby(e);
  for (int i = 0; i < n; ++i) {
    lastby[i % e] = i;
  }

  ll ans = 0;
  
  for (int i = 0; i < n; ++i) {
    if (!is_prime(a[i])) {
      continue;
    }
    int prv = i % e - e;
    {
      auto it = pos[i % e].lower_bound(i);
      if (it != pos[i % e].begin()) {
        prv = *prev(it);
      }
    }
    int nxt = lastby[i % e] + e;
    {
      auto it = pos[i % e].upper_bound(i);
      if (it != pos[i % e].end()) {
        nxt = *it;
      }
    }
    ans += ll((i - prv) / e) * ((nxt - i) / e) - 1;
  }

  cout << ans << '\n';
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