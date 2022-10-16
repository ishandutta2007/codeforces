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

int const MOD = 31607;
//int const MOD = 998244353;
using mint = modular<integral_constant<int, MOD>>;
//using mint = modular<DynamicMod>;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mint const DENOM = mint(10000).inv();
  int n;
  cin >> n;
  vector a(n, vector<mint>(n));
  vector ia(n, vector<mint>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      mint val = x * DENOM;
      a[i][j] = val;
      ia[i][j] = a[i][j].inv();
    }
  }
  vector<mint> row(n, 1), col(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      row[i] *= a[i][j];
      col[j] *= a[i][j];
    }
  }

  vector prod(1 << n, vector<mint>(n, 1));
  int bit = 0;
  for (int m = 1; m < (1 << n); ++m) {
    if (m == (1 << (bit + 1))) bit++;
    for (int i = 0; i < n; ++i) {
      prod[m][i] = prod[m ^ (1 << bit)][i] * ia[bit][i];
    }
  }

  vector<mint> rowProd(1 << n);
  rowProd[0] = 1;
  mint const NONE = -1;
  mint ans = 0;
  bit = 0;
  for (int mr = 0; mr < (1 << n); ++mr) {
    if (mr == (1 << (bit + 1))) bit++;
    if (mr > 0) {
      rowProd[mr] = rowProd[mr ^ (1 << bit)] * row[bit] * NONE;
    }
    for (int m1 : {0, 1}) {
      for (int m2 : {0, 1}) {
        mint dp = rowProd[mr];
        for (int j = 0; j < n; ++j) {
          mint ndp = 0;
          {
            //  take jth column
            auto nval = dp * col[j] * NONE;
            nval *= prod[mr][j];
            ndp += nval;
          }
          {
            //  skip jth column
            auto nval = dp;
            bool did = false;
            if (m1 && ((mr >> j & 1) == 0)) {
              nval *= a[j][j];
              did = true;
            }
            if (m2 && ((mr >> (n - 1 - j) & 1) == 0) && (!did || n % 2 == 0 || j != n / 2)) {
              nval *= a[n - 1 - j][j];
            }
            ndp += nval;
          }
          dp = ndp;
        }
        auto add = dp * (m1 ? NONE : 1) * (m2 ? NONE : 1);
        if (mr == 0 && m1 == 0 && m2 == 0) {
          add -= 1;
        }
        ans += add;
      }
    }
  }
  cout << -ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}