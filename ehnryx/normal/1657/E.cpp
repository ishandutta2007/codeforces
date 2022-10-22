#include <bits/stdc++.h>
using namespace std;

//%:include "utility/fast_input.h"
//%:include "utility/output.h"

// START %:include "number/mod_int.h"

// START #include "../math/extended_gcd.h"

#include <utility>

template <typename T>
constexpr std::tuple<T, T, T> extended_gcd(T a, T b) {
  if (b == 0) return std::tuple(a, 1, 0);
  auto [g, y, x] = extended_gcd(b, a % b);
  return std::tuple(g, x, y - x * (a / b));
}

// END #include "../math/extended_gcd.h"
#include <iostream>

template <long long mod_value, bool is_prime = true>
struct mod_int {
  static_assert(mod_value > 0);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic" // ISO C++ __int128
  using mod_t = std::conditional_t < mod_value < 1LL << 31, int, long long>;
  using larger_t = std::conditional_t < mod_value < 1LL << 31, long long, __int128>;
#pragma GCC diagnostic pop
  static constexpr mod_t mod = mod_value;
  mod_t v;
  mod_int(): v(0) {}
  mod_int(mod_t c): v(c) {
    if (abs(v) >= mod) v %= mod;
    if (v < 0) v += mod;
  }
  mod_int(larger_t c) {
    v = (mod_t) (abs(c) >= mod ? c % mod : c);
    if (v < 0) v += mod;
  }
  void assign(mod_t c) { v = c; }
  template <typename fast_input_t>
  void fast_read(fast_input_t& in) {
    in >> v;
    if (abs(v) >= mod) v %= mod;
    if (v < 0) v += mod;
  }
  friend std::istream& operator >> (std::istream& is, mod_int& num) {
    is >> num.v;
    if (abs(num.v) >= mod) num.v %= mod;
    if (num.v < 0) num.v += mod;
    return is;
  }
  friend std::ostream& operator << (std::ostream& os, const mod_int& num) {
    return os << num.v;
  }
  mod_t value() const { return v; }
  mod_t legible_value() const { return 2*v <= mod ? v : v - mod; }
  bool operator == (const mod_int& o) const { return v == o.v; }
  bool operator != (const mod_int& o) const { return v != o.v; }
  mod_int operator + (const mod_int& o) const { return mod_int(*this) += o; }
  mod_int operator - (const mod_int& o) const { return mod_int(*this) -= o; }
  mod_int operator * (const mod_int& o) const { return mod_int(*this) *= o; }
  mod_int operator / (const mod_int& o) const { return mod_int(*this) /= o; }
  mod_int operator - () const { return mod_int(*this).negate(); }
  mod_int& negate() {
    if (v != 0) v = mod - v;
    return *this;
  }
  mod_int& operator += (const mod_int& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  mod_int& operator -= (const mod_int& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }
  mod_int& operator *= (const mod_int& o) {
    v = (mod_t)((larger_t)v * o.v % mod);
    return *this;
  }
  mod_int& operator /= (const mod_int& o) {
    return operator *= (o.inverse());
  }
  mod_int pow(long long exponent) const {
    if (exponent == 0) return mod_int(1);
    if (v == 0) {
      if (exponent < 0) {
        throw std::invalid_argument("raising zero to a negative power");
      }
      return mod_int(0);
    }
    if constexpr (is_prime) {
      if (abs(exponent) >= mod - 1) exponent %= mod - 1;
      if (exponent < 0) exponent += mod - 1;
      mod_int res(1), base(*this);
      for (; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    } else {
      mod_int res(1), base(exponent < 0 ? inverse() : *this);
      for (; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    }
  }
  mod_int inverse() const {
    auto [g, x, y] = extended_gcd(mod, v);
    if (g != 1) {
      throw std::invalid_argument("taking the inverse of a non-coprime number");
    }
    // assert(operator * (mod_int(y)) == 1);
    return mod_int(y);
  }
};

// END %:include "number/mod_int.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using Int = mod_int<MOD>;

//#define MULTI_TEST
void solve_main([[maybe_unused]] int testnum, [[maybe_unused]] auto& cin) {
  int n, k;
  cin >> n >> k;

  vector ncr(n+1, vector<Int>(n+1));
  for(int i=0; i<=n; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for(int j=1; j<i; j++) {
      ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
    }
  }

  vector pk(k+1, vector<Int>(n * (n-1) / 2 + 1));
  for(int i=1; i<=k; i++) {
    pk[i][0] = 1;
    for(int j=1; j<size(pk[i]); j++) {
      pk[i][j] = pk[i][j-1] * i;
    }
  }

  n -= 1; // exclude 1

  vector dp(k+1, vector<Int>(n+1));
  dp[0][0] = 1;
  for(int i=1; i<=k; i++) {
    for(int j=0; j<=n; j++) {
      for(int t=0; t<=j; t++) {
        // choose t of n-j+t to have value k
        int edges = t * (t-1) / 2 + t * (n-j);
        dp[i][j] += dp[i-1][j-t] * ncr[n-j+t][t] * pk[i][edges];
      }
    }
  }

  cout << dp[k][n] << nl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T = 1;
#ifdef MULTI_TEST
  cin >> T;
#endif
  for(int testnum=1; testnum<=T; testnum++) {
    solve_main(testnum, cin);
  }

  return 0;
}