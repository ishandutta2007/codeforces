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

template <class MOD>
struct modular {
  int val{};

  constexpr static int mod() {
    return MOD::value;
  }

  constexpr static int norm(i64 x) {
    int res = -mod() <= x && x < mod() ? x : int(x % mod());
    if (res < 0) {
      res += mod();
    }
    return res;
  }

  constexpr modular(i64 x = 0) : val(norm(x)) {}

  explicit operator int() const {
    return val;
  }

  explicit operator i64() const {
    return val;
  }

  modular& operator+=(modular other) {
    val += other.val;
    if (val >= mod()) {
      val -= mod();
    }
    return *this;
  }

  friend modular operator+(modular x, modular y) {
    return x += y;
  }

  modular& operator-=(modular other) {
    val -= other.val;
    if (val < 0) {
      val += mod();
    }
    return *this;
  }

  friend modular operator-(modular x, modular y) {
    return x -= y;
  }

  modular& operator++() {
    if (++val == mod()) {
      val = 0;
    }
    return *this;
  }

  modular& operator--() {
    if (--val < 0) {
      val = mod() - 1;
    }
    return *this;
  }

  friend modular operator*(modular x, modular y) {
    return modular{(i64) x.val * y.val};
  }

  modular operator*=(modular other) {
    return *this = *this * other;
  }

  friend bool operator<(modular x, modular y) {
    return int(x) < int(y);
  }

  friend bool operator==(modular x, modular y) {
    return int(x) == int(y);
  }

  friend bool operator!=(modular x, modular y) {
    return int(x) != int(y);
  }

  modular operator-() const {
    return 0 - *this;
  }

  friend istream& operator>>(istream& in, modular& x) {
    i64 t;
    in >> t;
    x.val = norm(t);
    return in;
  }

  friend ostream& operator<<(ostream& out, modular x) {
    return out << x.val;
  }

  explicit operator bool() const {
    return bool(val);
  }

  modular power(i64 deg) const {
    auto x = *this;
    if (!x) {
      return !deg;
    }
    deg %= modular<MOD>::mod() - 1;
    if (deg < 0) {
      deg += modular<MOD>::mod() - 1;
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

  modular inv() const {
    return power(-1);
  }

  modular operator/(modular y) const {
    return (*this) * y.inv();
  }

  modular& operator/=(modular other) {
    return *this = *this / other;
  }
};

struct DynamicMod {
  static int value;
};
int DynamicMod::value;

int const MOD = (int) 1e9 + 7;
//int const MOD = 998244353;
using mint = modular<integral_constant<int, MOD>>;
//using mint = modular<DynamicMod>;

void solve(int) {
  int n, m;
  cin >> n >> m;
  int nz = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char ch : s) nz += ch == '0';
  }
  auto ans = mint(2).power(n * m - nz);
  if (nz == 0) --ans;
  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

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