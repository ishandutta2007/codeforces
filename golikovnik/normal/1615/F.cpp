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

//  by https://codeforces.com/profile/Nyaan
//  example submission:
//  https://codeforces.com/contest/1603/submission/133688639
template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;
 
  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }
 
  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");
 
  u32 a;
 
  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};
 
  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }
 
  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator++() {
    return *this += 1;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator--() {
    return *this -= 1;
  }
 
  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }
 
  constexpr mint &operator/=(const mint &b) {
    *this *= b.inv();
    return *this;
  }
 
  constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
  constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
  constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
  constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
  constexpr bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }
 
  constexpr mint power(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  
  constexpr mint inv() const { return power(mod - 2); }
 
  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }
 
  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }
  
  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  constexpr explicit operator bool() const {
    return bool(get());
  }
 
  static constexpr u32 get_mod() { return mod; }
};
 
template <typename T>
struct Binomial {
  vector<T> f, g, h;
  Binomial(int MAX = 0) : f(1, T(1)), g(1, T(1)), h(1, T(1)) {
    extend(MAX + 1);    
  }

  void extend(int m) {
    int n = f.size();

    if (n >= m) {
      return;
    }

    f.resize(m);
    g.resize(m);
    h.resize(m);
    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);
    g[m - 1] = f[m - 1].inv();
    h[m - 1] = g[m - 1] * f[m - 2];
    for (int i = m - 2; i >= n; i--) {
      g[i] = g[i + 1] * T(i + 1);
      h[i] = g[i] * f[i - 1];
    } 
  }

  void extend() {
    extend(2 * f.size());
  }
 
  T fact(int i) {
    if (i < 0) return T(0);
    while (i >= (int)f.size()) extend();
    return f[i];
  }
 
  T ifact(int i) {
    if (i < 0) return T(0);
    while (i >= (int)g.size()) extend();
    return g[i];
  }
 
  T inv(int i) {
    if (i < 0) return -inv(-i);
    while (i >= (int)h.size()) extend();
    return h[i];
  }
 
  T C(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fact(n) * ifact(n - r) * ifact(r);
  }
 
  inline T operator()(int n, int r) { return C(n, r); }
 
  template <typename I>
  T multinomial(const vector<I>& r) {
    static_assert(is_integral<I>::value == true);
    int n = 0;
    for (auto& x : r) {
      if(x < 0) return T(0);
      n += x;
    }
    T res = fact(n);
    for (auto& x : r) res *= ifact(x);
    return res;
  }
 
  template <typename I>
  T operator()(const vector<I>& r) {
    return multinomial(r);
  }
 
  T C_naive(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    T ret = T(1);
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
    return ret;
  }
 
  T A(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fact(n) * ifact(n - r);
  }
 
  T CR(int n, int r) {
    if (n < 0 || r < 0) return T(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
// int const MOD = 998244353;
int const MOD = int(1e9 + 7);
using mint = LazyMontgomeryModInt<MOD>;
Binomial<mint> C;

void solveTest() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  for (int i = 0; i < n; i += 2) {
    if (s[i] != '?') {
      s[i] = '0' ^ '1' ^ s[i];
    }
    if (t[i] != '?') {
      t[i] = '0' ^ '1' ^ t[i];
    }
  }
  s.insert(s.begin(), '1');
  t.insert(t.begin(), '1');
  s.push_back('1');
  t.push_back('1');
  n += 2;

  struct item {
    mint cnt{};
    mint sum{};

    item& operator+=(item const& other) {
      cnt += other.cnt;
      sum += other.sum;
      return *this;
    }

    item& operator-=(item const& other) {
      cnt -= other.cnt;
      sum -= other.sum;
      return *this;
    }
  };

  vector dp(n, vector<item>(n));
  dp[0][0].cnt = 1;
  vector<int> ps(n), pt(n);
  for (int i = 1; i < n; ++i) {
    ps[i] = ps[i - 1];
    pt[i] = pt[i - 1];
    if (s[i - 1] == '1') {
      ps[i] = i - 1;
    }
    if (t[i - 1] == '1') {
      pt[i] = i - 1;
    }
  }
  vector pref(n + 1, vector<item>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i] != '0' && t[j] != '0') {
        mint cval = abs(i - j);
        auto rect = pref[i][j];
        rect -= pref[i][pt[j]];
        rect -= pref[ps[i]][j];
        rect += pref[ps[i]][pt[j]];
        dp[i][j].cnt += rect.cnt;
        dp[i][j].sum += rect.sum + cval * rect.cnt;
      }
      pref[i + 1][j] += pref[i][j];
      pref[i][j + 1] += pref[i][j];
      pref[i + 1][j + 1] -= pref[i][j];
      pref[i + 1][j + 1] += dp[i][j];
    }
  }

  cout << dp[n - 1][n - 1].sum << '\n';
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