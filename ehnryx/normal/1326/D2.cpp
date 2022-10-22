#include <bits/stdc++.h>
using namespace std;

// START #include "../../../lca/string/hash_polynomial.h"

// START #include "../number/mod_int.h"

// START #include "../math/extended_gcd.h"

template <typename T>
tuple<T, T, T> extended_gcd(T a, T b) {
  if (b == 0) return tuple(a, 1, 0);
  auto [g, y, x] = extended_gcd(b, a % b);
  return tuple(g, x, y - x * (a / b));
}

// END #include "../math/extended_gcd.h"

template <long long mod_value, bool is_prime = true>
struct mod_int {
  static_assert(mod_value > 0);
  using mod_t = conditional_t < mod_value < 1LL << 31, int, long long>;
  using larger_t = conditional_t < mod_value < 1LL << 31, long long, __int128>;
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
  friend istream& operator >> (istream& is, mod_int& num) {
    is >> num.v;
    if (abs(num.v) >= mod) num.v %= mod;
    if (num.v < 0) num.v += mod;
    return is;
  }
  friend ostream& operator << (ostream& os, const mod_int& num) { return os << num.v; }
  const int& value() const { return v; }
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
      if (exponent < 0) throw invalid_argument("raising zero to a negative power");
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
    if (g != 1) throw invalid_argument("taking the inverse of a non-coprime number");
    assert(operator*(mod_int(y)) == 1);
    return mod_int(y < 0 ? y + mod : y);
  }
};

// END #include "../number/mod_int.h"

template <int mod, int prime>
struct hash_polynomial {
  vector<mod_int<mod>> sum, invp;
  template <typename T>
  hash_polynomial(const basic_string<T>& s): sum(s.size() + 1), invp(s.size() + 1) {
    mod_int<mod> prime_inverse = mod_int<mod>(prime).inverse();
    mod_int<mod> x = invp[0] = 1;
    for (size_t i = 0; i < s.size(); i++) {
      x *= prime;
      sum[i + 1] = sum[i] + x * s[i];
      invp[i + 1] = invp[i] * prime_inverse;
    }
  }
  int get(int i, int len) {
    return ((sum[i + len] - sum[i]) * invp[i]).value();
  }
};

// END #include "../../../lca/string/hash_polynomial.h"
// START #include "../../../lca/string/hash_multi.h"

template <template <int, int> typename hash_single, int mod, int prime, int... others>
struct hash_multi : hash_multi<hash_single, others...>, hash_single<mod, prime> {
  hash_multi(const string& s):
    hash_multi<hash_single, others...>(s), hash_single<mod, prime>(s) {}
  auto get(int i, int len) {
    return tuple_cat(
        tuple(hash_single<mod, prime>::get(i, len)),
        hash_multi<hash_single, others...>::get(i, len));
  }
};

template <template <int, int> typename hash_single, int mod, int prime>
struct hash_multi<hash_single, mod, prime> : hash_single<mod, prime> {
  hash_multi(const string& s): hash_single<mod, prime>(s) {}
  auto get(int i, int len) {
    return tuple(hash_single<mod, prime>::get(i, len));
  }
};

// END #include "../../../lca/string/hash_multi.h"

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using Hasher = hash_multi<
  hash_polynomial,
  (int)1e9+7, 31,
  (int)1e9+9, 37,
  (int)1e9+123, 97,
  (int)1e9+321, 101>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);

  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    int n = size(s);
    Hasher ha(s);
    reverse(begin(s), end(s));
    Hasher hb(s);

    int take = 0;
    for(int i=1; 2*i<=n && s[i-1] == s[n-i]; i++) {
      take++;
    }

    pair<int, int> mid(0, 0);
    for(int i=1; i+2*take<=n; i++) {
      if(ha.get(take, i) == hb.get(n - take - i, i)) {
        mid = max(mid, pair(i, n - take - i));
      }
      if(ha.get(n - take - i, i) == hb.get(take, i)) {
        mid = max(mid, pair(i, take));
      }
    }

    cout << s.substr(0, take) + s.substr(mid.second, mid.first) + s.substr(n - take, take) << nl;
  }

  return 0;
}