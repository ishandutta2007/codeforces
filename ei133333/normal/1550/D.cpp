#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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


template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

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
  int T;
  cin >> T;


  while(T--) {
    int N, L, R;
    cin >> N >> L >> R;

    vector< int64 > plus(N), minus(N);
    for(int i = 0; i < N; i++) {
      plus[i] = R - i - 1;
      minus[i] = i - L + 1;
    }

    int64 best = 0;
    for(int i = 1; i < N; i++) {
      chmax(best, 1LL * i * (N - i));
    }
    vector< int > bs;
    for(int i = 1; i < N; i++) {
      if(best == 1LL * i * (N - i)) bs.emplace_back(i);
    }

    vector< int64 > xs{plus};
    xs.emplace_back(0);
    for(int j = 0; j < N; j++) xs.emplace_back(minus[j]);
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));

    modint ret = 0;
    int plus_ptr = 0, minus_ptr = N - 1;
    vector< int > t(N);
    int a = 0, b = 0, c = 0;
    for(int j = (int) xs.size() - 1; j > 0; j--) {
      while(plus_ptr < N and xs[j] <= plus[plus_ptr]) {
        if(t[plus_ptr]++ == 1) --b, ++c;
        else ++a;
        ++plus_ptr;
      }
      while(minus_ptr >= 0 and xs[j] <= minus[minus_ptr]) {
        if(t[minus_ptr]++ == 1) --a, ++c;
        else ++b;
        --minus_ptr;
      }
      if(a + b + c != N) {
        continue;
      }
      for(auto x : bs) {
        int y = N - x;
        int xx = x - a;
        int yy = y - b;
        if(xx < 0 or yy < 0) continue;
        ret += modint(xs[j] - xs[j - 1]) * Enumeration< modint >::C(xx + yy, xx);
      }
    }
    cout << ret << "\n";
  }
}