//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

// int const MOD = (int) 1e9 + 7;
int const MOD = 998244353;
using mint = modular<integral_constant<int, MOD>>;
//using mint = modular<DynamicMod>;

int const BITS = 20;
int const N = 1 << BITS;
mint gen;
int rev[N];
mint roots[N];
bool ntt_precalced;

void ntt_precalc() {
  for (gen = 2; ; ++gen) {
    if (mint(gen).power((MOD - 1) / 2) != 1) break;
  }
  for (int i = 1; i < N; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (BITS - 1));
  }
  for (int k = 1; k < N; k *= 2) {
    auto const root = mint(gen).power((MOD - 1) / (2 * k));
    roots[k] = 1;
    for (int i = 1; i < k; ++i) {
      roots[k + i] = i & 1 ? roots[(k + i) >> 1] * root : roots[(k + i) >> 1];
    }
  }
  ntt_precalced = true;
}

void fft(vector<mint>& a) {
  if (!ntt_precalced) ntt_precalc();

  int n = (int) a.size();
  int bits = __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    int j = rev[i] >> (BITS - bits);
    if (i < j) swap(a[i], a[j]);
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        auto u = a[i + j];
        auto v = a[i + j + k] * roots[j + k];
        a[i + j] = u + v;
        a[i + j + k] = u - v;
      }
    }
  }
}

vector<mint> multiply(vector<mint> a, vector<mint> b) {
  if (a.empty() || b.empty()) return {};
  int need = int(a.size()) + int(b.size()) - 1;
  int pw = 1;
  while (pw < need) pw *= 2;
  a.resize(pw);
  b.resize(pw);
  bool eq = a == b;
  fft(a);
  if (eq) b = a; else fft(b);
  for (int i = 0; i < pw; ++i) a[i] *= b[i];
  fft(a);
  reverse(a.begin() + 1, a.end());
  a.resize(need);
  auto inv_pw = mint(pw).inv();
  for (auto& x : a) x *= inv_pw;
  return a;
}

void add(vector<mint>& a, vector<mint> const& b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0; i < int(b.size()); ++i) a[i] += b[i];
}

struct Matrix {
  vector<mint> a[2][2]{};
};

Matrix mult(Matrix const& A, Matrix const& B) {
  Matrix C{};
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        add(C.a[i][j], multiply(A.a[i][k], B.a[k][j]));
      }
    }
  }
  return C;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> len;
  for (int i = 0; i < n; ) {
    int l = a[i];
    bool bad = i + l > n;
    for (int j = 0; j < l && i + j < n; ++j) {
      bad |= a[i + j] != l;
    }
    if (bad) {
      cout << 0 << '\n';
      return 0;
    }
    len.push_back(l);
    i += l;
  }
  Matrix zero{}, one{};
  zero.a[0][1] = {0, 2};
  zero.a[1][1] = {1, 2};
  one.a[0][0] = {0, -1};
  one.a[0][1] = {0, 2};
  one.a[1][0] = {0, -1};
  one.a[1][1] = {1, 2};
  auto solve = [&](auto&& solve, int l, int r) -> Matrix {
    if (l + 1 == r) {
      return len[l] == 1 ? one : zero;
    }
    int m = (l + r) / 2;
    return mult(solve(solve, l, m), solve(solve, m, r));
  };
  auto A = solve(solve, 0, int(len.size()));
  auto poly = A.a[0][0];
  add(poly, A.a[0][1]);
  mint ans = 0;
  mint fact = 1;
  for (int k = 1; k <= int(len.size()); ++k) {
    fact *= k;
    ans += fact * (k % 2 == int(len.size()) % 2 ? 1 : -1) * poly[k];
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}