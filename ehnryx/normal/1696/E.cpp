#include <bits/stdc++.h>
using namespace std;

//%:include "utility/defines.h"
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
// START #include "../utility/fast_input.h"

// START #include "member_function_checker.h"

#define MEMBER_FUNCTION_CHECKER(FUNCTION) \
  template <typename __class_t, typename... __args_t> \
  struct _has_##FUNCTION { \
    template <typename __class> \
    static constexpr auto check(__class*) -> \
      typename std::is_void<std::void_t< \
        decltype(std::declval<__class&>().FUNCTION(std::declval<__args_t>()...))>>::type; \
    template <typename __dummy> \
    static constexpr auto check(...) -> std::false_type; \
    using type = decltype(check<__class_t>(0)); \
    static constexpr bool value = type::value; \
  }

// END #include "member_function_checker.h"

#include <complex>
#include <string>
#include <tuple>
#include <vector>

template <size_t buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c = 0;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  explicit operator bool() const { return c != EOF; }

  inline char getc(void) {
    if (c == EOF) return EOF;
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return c = EOF;
    }
    return *S++;
  }

  inline void get(char& x) {
    while (isspace(x = getc()) && x != EOF);
  }

  inline void get(std::string& x) {
    x.clear();
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc()) {
      x.push_back(c);
    }
  }

  inline void get(decltype(std::ignore)) {
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc());
  }

  template <typename var_t, std::enable_if_t<std::is_integral_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != EOF) {
      positive = (c ^ '-');
    }
    for (; isdigit(c) && c != EOF; c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, std::enable_if_t<std::is_floating_point_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.' && c != EOF) {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c) && c != EOF; c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc()) && c != EOF) {
        x = x * 10 + c - '0';
        div *= 10;
      }
      x /= div;
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename T>
  inline void get(std::complex<T>& x) {
    x.real(getv<T>());
    x.imag(getv<T>());
  }

  template <typename T, typename U>
  inline void get(std::pair<T, U>& x) {
    *this >> x.first >> x.second;
  }

  template <size_t index = 0, typename... T>
  inline void get(std::tuple<T...>& x) {
    if constexpr (index < sizeof...(T)) {
      *this >> (std::get<index>(x));
      get<index + 1>(x);
    }
  }

  MEMBER_FUNCTION_CHECKER(get);

  template <typename T>
  inline fast_input& operator >> (T& x) {
    if constexpr (_has_get<fast_input, T&>::value) {
      get(x);
    } else {
      x.fast_read(*this);
    }
    return *this;
  }

  std::string getline() {
    std::string out;
    while ((c = getc()) != '\n' && c != EOF) {
      out.push_back(c);
    }
    return out;
  }

  std::vector<std::string> readlines(int n) {
    std::vector<std::string> out;
    out.reserve(n);
    for (int i = 0; i < n; i++) {
      out.push_back(getline());
    }
    return out;
  }

  template <typename T>
  T getv() {
    T x;
    *this >> x;
    return x;
  }

  template <typename T, int pad_n = 0>
  std::vector<T> read(int n) {
    return readinit<T, pad_n>(n, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> read(int n, int m) {
    return readinit<T, pad_n, pad_m>(n, m, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> read(int n, int m, int h) {
    return readinit<T, pad_n, pad_m, pad_h>(n, m, h, T());
  }

  template <typename T, int pad_n = 0>
  std::vector<T> readinit(int n, T init) {
    std::vector<T> out(n + 2 * pad_n, init);
    for (int i = 0; i < n; i++) {
      *this >> out[pad_n + i];
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> readinit(int n, int m, T init) {
    std::vector out(n + 2 * pad_n, std::vector<T>(m + 2 * pad_m, init));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        *this >> out[pad_n + i][pad_m + j];
      }
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> readinit(int n, int m, int h, T init) {
    std::vector out(n + 2 * pad_n, std::vector(m + 2 * pad_m,
          std::vector<T>(h + 2 * pad_h, init)));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for (int k = 0; k < h; k++) {
          *this >> out[pad_n + i][pad_m + j][pad_h + k];
        }
      }
    }
    return out;
  }
};

// END #include "../utility/fast_input.h"
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
  template <size_t buf_size>
  void fast_read(fast_input<buf_size>& in) {
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
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using Int = mod_int<MOD>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  const int M = 4e5 + 7;
  vector<Int> fact(M), invf(M);
  fact[0] = 1;
  for(int i=1; i<M; i++) {
    fact[i] = fact[i-1] * i;
  }
  invf[M-1] = fact[M-1].inverse();
  for(int i=M-1; i>0; i--) {
    invf[i-1] = invf[i] * i;
  }
  assert(invf[0] == 1);

  auto value = [&](int i, int j) -> Int {
    if(i<0 || j<0) return 0;
    return fact[i+j] * invf[i] * invf[j];
  };

  int n;
  cin >> n;
  vector<int> a(n+1);
  Int ans = 0;
  for(int i=0; i<=n; i++) {
    cin >> a[i];
    ans += value(i + 1, a[i] - 1);
  }
  cout << ans << nl;

  return 0;
}