#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

namespace FastPrimeFactorization {

  template< typename word, typename dword, typename sword >
  struct UnsafeMod {
    UnsafeMod() : x(0) {}

    UnsafeMod(word _x) : x(init(_x)) {}

    bool operator==(const UnsafeMod &rhs) const {
      return x == rhs.x;
    }

    bool operator!=(const UnsafeMod &rhs) const {
      return x != rhs.x;
    }

    UnsafeMod &operator+=(const UnsafeMod &rhs) {
      if((x += rhs.x) >= mod) x -= mod;
      return *this;
    }

    UnsafeMod &operator-=(const UnsafeMod &rhs) {
      if(sword(x -= rhs.x) < 0) x += mod;
      return *this;
    }

    UnsafeMod &operator*=(const UnsafeMod &rhs) {
      x = reduce(dword(x) * rhs.x);
      return *this;
    }

    UnsafeMod operator+(const UnsafeMod &rhs) const {
      return UnsafeMod(*this) += rhs;
    }

    UnsafeMod operator-(const UnsafeMod &rhs) const {
      return UnsafeMod(*this) -= rhs;
    }

    UnsafeMod operator*(const UnsafeMod &rhs) const {
      return UnsafeMod(*this) *= rhs;
    }

    UnsafeMod pow(uint64_t e) const {
      UnsafeMod ret(1);
      for(UnsafeMod base = *this; e; e >>= 1, base *= base) {
        if(e & 1) ret *= base;
      }
      return ret;
    }

    word get() const {
      return reduce(x);
    }

    static constexpr int word_bits = sizeof(word) * 8;

    static word modulus() {
      return mod;
    }

    static word init(word w) {
      return reduce(dword(w) * r2);
    }

    static void set_mod(word m) {
      mod = m;
      inv = mul_inv(mod);
      r2 = -dword(mod) % mod;
    }

    static word reduce(dword x) {
      word y = word(x >> word_bits) - word((dword(word(x) * inv) * mod) >> word_bits);
      return sword(y) < 0 ? y + mod : y;
    }

    static word mul_inv(word n, int e = 6, word x = 1) {
      return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
    }

    static word mod, inv, r2;

    word x;
  };

  using uint128_t = __uint128_t;

  using Mod64 = UnsafeMod< uint64_t, uint128_t, int64_t >;
  template<> uint64_t Mod64::mod = 0;
  template<> uint64_t Mod64::inv = 0;
  template<> uint64_t Mod64::r2 = 0;

  using Mod32 = UnsafeMod< uint32_t, uint64_t, int32_t >;
  template<> uint32_t Mod32::mod = 0;
  template<> uint32_t Mod32::inv = 0;
  template<> uint32_t Mod32::r2 = 0;

  bool miller_rabin_primality_test_uint64(uint64_t n) {
    Mod64::set_mod(n);
    uint64_t d = n - 1;
    while(d % 2 == 0) d /= 2;
    Mod64 e{1}, rev{n - 1};
    // http://miller-rabin.appspot.com/  < 2^64
    for(uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if(n <= a) break;
      uint64_t t = d;
      Mod64 y = Mod64(a).pow(t);
      while(t != n - 1 && y != e && y != rev) {
        y *= y;
        t *= 2;
      }
      if(y != rev && t % 2 == 0) return false;
    }
    return true;
  }

  bool miller_rabin_primality_test_uint32(uint32_t n) {
    Mod32::set_mod(n);
    uint32_t d = n - 1;
    while(d % 2 == 0) d /= 2;
    Mod32 e{1}, rev{n - 1};
    for(uint32_t a : {2, 7, 61}) {
      if(n <= a) break;
      uint32_t t = d;
      Mod32 y = Mod32(a).pow(t);
      while(t != n - 1 && y != e && y != rev) {
        y *= y;
        t *= 2;
      }
      if(y != rev && t % 2 == 0) return false;
    }
    return true;
  }

  bool is_prime(uint64_t n) {
    if(n == 2) return true;
    if(n == 1 || n % 2 == 0) return false;
    if(n < uint64_t(1) << 31) return miller_rabin_primality_test_uint32(n);
    return miller_rabin_primality_test_uint64(n);
  }

  uint64_t pollard_rho(uint64_t n) {
    if(is_prime(n)) return n;
    if(n % 2 == 0) return 2;
    Mod64::set_mod(n);
    uint64_t d;
    Mod64 one{1};
    for(Mod64 c{one};; c += one) {
      Mod64 x{2}, y{2};
      do {
        x = x * x + c;
        y = y * y + c;
        y = y * y + c;
        d = __gcd((x - y).get(), n);
      } while(d == 1);
      if(d < n) return d;
    }
    assert(0);
  }

  vector< uint64_t > prime_factor(uint64_t n) {
    if(n <= 1) return {};
    uint64_t p = pollard_rho(n);
    if(p == n) return {p};
    auto l = prime_factor(p);
    auto r = prime_factor(n / p);
    copy(begin(r), end(r), back_inserter(l));
    return l;
  }
};

int main() {
  int T;
  cin >> T;
  while(T--) {
    int64 X;
    cin >> X;
    while(X % 2 == 0 and X > 2) {
      X /= 2;
    }
    if(X & 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}