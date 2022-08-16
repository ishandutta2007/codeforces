#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

template< typename T >
struct Enumeration {
private:
  static vector< T > _fact, _finv, _inv;

  inline static void expand(size_t sz) {
    if(_fact.size() < sz + 1) {
      int pre_sz = max(1, (int) _fact.size());
      _fact.resize(sz + 1, T(1));
      _finv.resize(sz + 1, T(1));
      _inv.resize(sz + 1, T(1));
      for(int i = pre_sz; i <= sz; i++) {
        _fact[i] = _fact[i - 1] * T(i);
      }
      _finv[sz] = T(1) / _fact[sz];
      for(int i = (int) sz - 1; i >= pre_sz; i--) {
        _finv[i] = _finv[i + 1] * T(i + 1);
      }
      for(int i = pre_sz; i <= sz; i++) {
        _inv[i] = _finv[i] * _fact[i - 1];
      }
    }
  }

public:
  explicit Enumeration(size_t sz = 0) { expand(sz); }

  static inline T fact(int k) {
    expand(k);
    return _fact[k];
  }

  static inline T finv(int k) {
    expand(k);
    return _finv[k];
  }

  static inline T inv(int k) {
    expand(k);
    return _inv[k];
  }

  static T P(int n, int r) {
    if(r < 0 || n < r) return 0;
    return fact(n) * finv(n - r);
  }

  static T C(int p, int q) {
    if(q < 0 || p < q) return 0;
    return fact(p) * finv(q) * finv(p - q);
  }

  static T H(int n, int r) {
    if(n < 0 || r < 0) return 0;
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

template< typename T >
vector< T > Enumeration< T >::_fact = vector< T >();
template< typename T >
vector< T > Enumeration< T >::_finv = vector< T >();
template< typename T >
vector< T > Enumeration< T >::_inv = vector< T >();

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  if(count(begin(S), end(S), '1') < K) {
    cout << 1 << endl;
    return 0;
  }
  modint ret = 1;
  using E = Enumeration< modint >;
  for(int l = 0; l < N; l++) {
    int one = S[l] == '1';
    int zero = S[l] == '0';
    for(int r = l + 1; r < N; r++) {
      one += S[r] == '1';
      zero += S[r] == '0';
      if(one <= K) {
        if(S[l] == '1') {
          if(S[r] == '1') {
            ret += E::C(one + zero - 2, zero - 2);
          } else {
            ret += E::C(one + zero - 2, zero - 1);
          }
        } else {
          if(S[r] == '0') {
            ret += E::C(one + zero - 2, one - 2);
          } else {
            ret += E::C(one + zero - 2, one - 1);
          }
        }
      }
    }
  }
  cout << ret << "\n";
}