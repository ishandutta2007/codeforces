#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
const int mod = 998244353;

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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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

/**
 * @brief Montgomery ModInt
 */
template< uint32_t mod, bool fast = false >
struct MontgomeryModInt {
  using mint = MontgomeryModInt;
  using i32 = int32_t;
  using i64 = int64_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for(i32 i = 0; i < 4; i++) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;

  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 x;

  MontgomeryModInt() : x{} {}

  MontgomeryModInt(const i64 &a)
      : x(reduce(u64(fast ? a : (a % mod + mod)) * n2)) {}

  static constexpr u32 reduce(const u64 &b) {
    return u32(b >> 32) + mod - u32((u64(u32(b) * r) * mod) >> 32);
  }

  mint &operator+=(const mint &p) {
    if(i32(x += p.x - 2 * mod) < 0) x += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &p) {
    if(i32(x -= p.x) < 0) x += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &p) {
    x = reduce(u64(x) * p.x);
    return *this;
  }

  mint &operator/=(const mint &p) {
    *this *= p.inverse();
    return *this;
  }

  mint operator-() const { return mint() - *this; }

  mint operator+(const mint &p) const { return mint(*this) += p; }

  mint operator-(const mint &p) const { return mint(*this) -= p; }

  mint operator*(const mint &p) const { return mint(*this) *= p; }

  mint operator/(const mint &p) const { return mint(*this) /= p; }

  bool operator==(const mint &p) const { return (x >= mod ? x - mod : x) == (p.x >= mod ? p.x - mod : p.x); }

  bool operator!=(const mint &p) const { return (x >= mod ? x - mod : x) != (p.x >= mod ? p.x - mod : p.x); }

  u32 get() const {
    u32 ret = reduce(x);
    return ret >= mod ? ret - mod : ret;
  }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  mint inverse() const {
    return pow(mod - 2);
  }

  friend ostream &operator<<(ostream &os, const mint &p) {
    return os << p.get();
  }

  friend istream &operator>>(istream &is, mint &a) {
    i64 t;
    is >> t;
    a = mint(t);
    return is;
  }

  static u32 get_mod() { return mod; }
};

using modint = MontgomeryModInt< mod >;

/**
 * @brief Binomial()
 * @docs docs/binomial.md
 */


vector< modint > invs(12);

template< typename T >
T binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  T ret = 1;
  for(int64_t i = 1; i <= K; ++i) {
    ret *= N;
    N--;
    ret *= invs[i];
  }
  return ret;
}

int main() {
  modint dp[14][12][12] = {
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},
      {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 3,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  1,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 2, 12, 2, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 2, 12, 4,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 9,  6,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 3,  6,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   4,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   1,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 5, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 3, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 4, 35, 29, 1, 0, 0, 0, 0, 0, 0, 0,}, {0, 3, 35, 41,  4,  0, 0, 0, 0, 0, 0, 0,}, {0, 1, 30,  44,  7,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  17,  45,  7,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  8,   30,   11,   0,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 6, 20, 6,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 4, 55, 50, 3, 0, 0, 0, 0, 0, 0, 0,}, {0, 6, 80, 118, 18, 0, 0, 0, 0, 0, 0, 0,}, {0, 6, 95,  186, 48,  0, 0, 0, 0, 0, 0, 0,}, {0, 6,  101, 230, 85,  2,  0, 0, 0, 0, 0, 0,}, {0, 2,  94,  260,  113,  4,   0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 7, 35, 21, 1, 0, 0, 0, 0, 0, 0, 0,}, {0, 5, 96, 145, 26, 0, 0, 0, 0, 0, 0, 0,}, {0, 8, 155, 358, 124, 3, 0, 0, 0, 0, 0, 0,}, {0, 9,  207, 616, 313, 16, 0, 0, 0, 0, 0, 0,}, {0, 11, 250, 859,  567,  53,  0, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 8, 56, 56,  8,  0, 0, 0, 0, 0, 0, 0,}, {0, 6, 154, 350, 126, 4, 0, 0, 0, 0, 0, 0,}, {0, 10, 268, 898, 552, 48, 0, 0, 0, 0, 0, 0,}, {0, 12, 389, 1654, 1404, 204, 1, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 9, 84,  126, 36,  1, 0, 0, 0, 0, 0, 0,}, {0, 7,  232, 742, 448, 43, 0, 0, 0, 0, 0, 0,}, {0, 12, 427, 1967, 1887, 357, 6, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 10, 120, 252, 120, 10, 0, 0, 0, 0, 0, 0,}, {0, 8,  333, 1428, 1302, 252, 5, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 11, 165, 462,  330,  55,  1, 0, 0, 0, 0, 0,},},
      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,  0,   0,  0, 0, 0, 0, 0, 0, 0,}, {0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,   0,   0,  0, 0, 0, 0, 0, 0,}, {0, 0,  0,   0,    0,    0,   0, 0, 0, 0, 0, 0,},},


  };

  for(int i = 0; i < 12; i++) invs[i] = modint(i).inverse();

  /*
  auto dp = make_v< modint >(13, 12, 12); // BlockLen, Inv, Rev
   vector< int > dame(1 << 12);
  for(int i = 0; i < 12; i++) {
    dame[(1 << i) - 1] = 1;
  }
  auto dp1 = make_v< modint >(1 << 12, 12, 12, 12);
  dp1[0][0][0][0] = 1;
  for(int j = 0; j < 4; j++) {
    auto dp2 = make_v< modint >(1 << 12, 12, 12, 12);
    for(int n = 0; n <= j; n++) {
      for(int last = 0; last < 12; last++) {
        for(int l = 0; l < (1 << 12); l++) {
          for(int k = 0; k < 12; k++) {
            int inv = 0;
            for(int m = 0; m < 12; m++) {
              if((l >> m) & 1) continue;
              int ninv = k + inv;
              inv++;
              if(ninv >= 12) continue;
              int nrev = n + (m < last);
              if(nrev >= 12) continue;
              if(dame[l | (1 << m)]) {
                dp[j + 1][ninv][nrev] += dp1[l][k][n][last];
              } else {
                dp2[l | (1 << m)][ninv][nrev][m] += dp1[l][k][n][last];
              }
            }
          }
        }
      }
    }
    dp1 = dp2;
  }
   */

  // 2Block,,inv,rev
  auto dp2 = make_v< modint >(12, 24, 12, 12);
  dp2[0][0][0][0] = 1;
  for(int s = 0; s < 11; s++) {
    for(int i = 0; i < 24; i++) {
      for(int j = 0; j < 12; j++) {
        for(int l = 0; l < 12; l++) {
          for(int block = 2; block < 14 and i + block < 24; block++) {
            for(int add_inv = 0; j + add_inv <= 11; add_inv++) {
              for(int add_rev = 0; l + add_rev <= 11; add_rev++) {
                dp2[s + 1][i + block][j + add_inv][l + add_rev] += dp2[s][i][j][l] * dp[block][add_inv][add_rev];
              }
            }
          }
        }
      }
    }
  }


  int t;
  cin >> t;
  while(t--) {
    int n, k, x;
    cin >> n >> k >> x;
    modint ret = 0;
    for(int j = 1; j <= min(n, 23); j++) {
      for(int i = 1; i < 12; i++) {
        ret += dp2[i][j][k][x] * binomial< modint >(n - j + i, i);
      }
    }
    cout << ret << "\n";
  }
}