//  Copyright 2020 Nikita Golikov

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

template <int MOD>
struct modular {
  int val{};

  static int norm(i64 x) {
    int res = -MOD <= x && x < MOD ? x : (int) (x % MOD);
    if (res < 0) {
      res += MOD;
    }
    return res;
  }

  modular(i64 x = 0) : val(norm(x)) {}

  int to_int() const {
    return val;
  }
  modular& operator+=(modular other) {
    val += other.val;
    if (val >= MOD) {
      val -= MOD;
    }
    return *this;
  }
  friend modular operator+(modular x, modular y) {
    return x += y;
  }
  modular& operator-=(modular other) {
    val -= other.val;
    if (val < 0) {
      val += MOD;
    }
    return *this;
  }
  friend modular operator-(modular x, modular y) {
    return x -= y;
  }
  modular& operator++() {
    if (++val == MOD) {
      val = 0;
    }
    return *this;
  }
  modular& operator--() {
    if (--val < 0) {
      val = MOD - 1;
    }
    return *this;
  }
  friend modular operator*(modular x, modular y) {
    return modular{(i64) x.val * y.val};
  }
  modular operator*=(modular other) {
    return *this = *this * other;
  }
  friend bool operator==(modular x, modular y) {
    return x.to_int() == y.to_int();
  }
  friend bool operator!=(modular x, modular y) {
    return x.to_int() != y.to_int();
  }
  modular operator-() const {
    return 0 - *this;
  }
  friend istream& operator>>(istream& in, modular& x) {
    return in >> x.val;
  }
  friend ostream& operator<<(ostream& out, modular x) {
    return out << x.val;
  }
  explicit operator bool() const {
    return bool(val);
  }
};

template <int MOD>
modular<MOD> power(modular<MOD> x, i64 deg) {
  if (!x) {
    return !deg;
  }
  deg %= MOD - 1;
  if (deg < 0) {
    deg += MOD - 1;
  }
  modular<MOD> res = 1;
  while (deg) {
    if (deg & 1) {
      res *= x;
    }
    x *= x;
    deg /= 2;
  }
  return res;
}

template <int MOD>
modular<MOD> inv(modular<MOD> x) {
  return power(x, -1);
}

template <int MOD>
modular<MOD> operator/(modular<MOD> x, modular<MOD> y) {
  return x * inv(y);
}

template <int MOD>
modular<MOD>& operator/=(modular<MOD>& x, modular<MOD> other) {
  return x = x / other;
}

int const MOD = 998244353;
using mint = modular<MOD>;

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int const INF = n + m + 5;
  vector<mint> fact(INF + 1);
  fact[0] = 1;
  for (int i = 1; i <= INF; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  vector<mint> ifact(INF + 1);
  ifact.back() = inv(fact.back());
  for (int i = INF - 1; i >= 0; --i) {
    ifact[i] = ifact[i + 1] * (i + 1);
  }
  auto choose = [&](int x, int y) -> mint {
    if (x < 0 || y < 0 || y > x) return 0;
    return fact[x] * ifact[y] * ifact[x - y];
  };
  vector<mint> f(n + 1);
  mint pref_f = 0;
  mint pref = fact[m - 1];
  mint pref_prog = pref;
  for (int k = 1; k <= n; ++k) {
    auto glob = m * ifact[n + m] * fact[k] * fact[n - k];
    auto me = fact[m - 1 + k] * ifact[k];
    pref += me;
    pref_prog += pref;
    f[k] += glob * choose(n + m + 1, m + k + 1) * pref_prog;
    f[k] += glob * choose(n + m, m + k) * pref_f;
    f[k] /= (1 - glob * choose(n + m, m + k) * me);
    pref_f += f[k] * me;
  }
  cout << f.back() << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}