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

#line 1 "math/fft/fast-fourier-transform.cpp"
namespace FastFourierTransform {
  using real = double;

  struct C {
    real x, y;

    C() : x(0), y(0) {}

    C(real x, real y) : x(x), y(y) {}

    inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

    inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

    inline C conj() const { return C(x, -y); }
  };

  const real PI = acosl(-1);
  int base = 1;
  vector< C > rts = {{0, 0},
                     {1, 0}};
  vector< int > rev = {0, 1};


  void ensure_base(int nbase) {
    if(nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for(int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    while(base < nbase) {
      real angle = PI * 2.0 / (1 << (base + 1));
      for(int i = 1 << (base - 1); i < (1 << base); i++) {
        rts[i << 1] = rts[i];
        real angle_i = angle * (2 * i + 1 - (1 << base));
        rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
      }
      ++base;
    }
  }

  void fft(vector< C > &a, int n) {
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for(int i = 0; i < n; i++) {
      if(i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for(int k = 1; k < n; k <<= 1) {
      for(int i = 0; i < n; i += 2 * k) {
        for(int j = 0; j < k; j++) {
          C z = a[i + j + k] * rts[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  vector< int64_t > multiply(const vector< int > &a, const vector< int > &b) {
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 1;
    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector< C > fa(sz);
    for(int i = 0; i < sz; i++) {
      int x = (i < (int) a.size() ? a[i] : 0);
      int y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = C(x, y);
    }
    fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for(int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
      fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
      fa[i] = z;
    }
    for(int i = 0; i < (sz >> 1); i++) {
      C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
      C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
      fa[i] = A0 + A1 * s;
    }
    fft(fa, sz >> 1);
    vector< int64_t > ret(need);
    for(int i = 0; i < need; i++) {
      ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
  }
};
#line 2 "math/fft/arbitrary-mod-convolution.cpp"

/*
 * @brief Arbitrary Mod Convolution(mod)
 */
template< typename T >
struct ArbitraryModConvolution {
  using real = FastFourierTransform::real;
  using C = FastFourierTransform::C;

  ArbitraryModConvolution() = default;

  static vector< T > multiply(const vector< T > &a, const vector< T > &b, int need = -1) {
    if(need == -1) need = a.size() + b.size() - 1;
    int nbase = 0;
    while((1 << nbase) < need) nbase++;
    FastFourierTransform::ensure_base(nbase);
    int sz = 1 << nbase;
    vector< C > fa(sz);
    for(int i = 0; i < a.size(); i++) {
      fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x >> 15);
    }
    fft(fa, sz);
    vector< C > fb(sz);
    if(a == b) {
      fb = fa;
    } else {
      for(int i = 0; i < b.size(); i++) {
        fb[i] = C(b[i].x & ((1 << 15) - 1), b[i].x >> 15);
      }
      fft(fb, sz);
    }
    real ratio = 0.25 / sz;
    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
    for(int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C a1 = (fa[i] + fa[j].conj());
      C a2 = (fa[i] - fa[j].conj()) * r2;
      C b1 = (fb[i] + fb[j].conj()) * r3;
      C b2 = (fb[i] - fb[j].conj()) * r4;
      if(i != j) {
        C c1 = (fa[j] + fa[i].conj());
        C c2 = (fa[j] - fa[i].conj()) * r2;
        C d1 = (fb[j] + fb[i].conj()) * r3;
        C d2 = (fb[j] - fb[i].conj()) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector< T > ret(need);
    for(int i = 0; i < need; i++) {
      int64_t aa = llround(fa[i].x);
      int64_t bb = llround(fb[i].x);
      int64_t cc = llround(fa[i].y);
      aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;
      ret[i] = aa + (bb << 15) + (cc << 30);
    }
    return ret;
  }
};

#line 2 "math/fps/formal-power-series.cpp"

/**
 * @brief Formal Power Series()
 */
template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;
  using Conv = ArbitraryModConvolution< T >;

  P pre(int deg) const {
    return P(begin(*this), begin(*this) + min((int) this->size(), deg));
  }

  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
  }

  void shrink() {
    while(this->size() && this->back() == T(0)) this->pop_back();
  }

  P operator+(const P &r) const { return P(*this) += r; }

  P operator+(const T &v) const { return P(*this) += v; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator-(const T &v) const { return P(*this) -= v; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(const T &v) const { return P(*this) *= v; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P operator%(const P &r) const { return P(*this) %= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    return *this;
  }

  // https://judge.yosupo.jp/problem/convolution_mod
  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    auto ret = Conv::multiply(*this, r);
    return *this = {begin(ret), end(ret)};
  }

  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }

  P &operator%=(const P &r) {
    return *this -= *this / r * r;
  }

  // https://judge.yosupo.jp/problem/division_of_polynomials
  pair< P, P > div_mod(const P &r) {
    P q = *this / r;
    return make_pair(q, *this - q * r);
  }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    return *this;
  }

  P &operator*=(const T &v) {
    for(int i = 0; i < this->size(); i++) (*this)[i] *= v;
    return *this;
  }

  P dot(P r) const {
    P ret(min(this->size(), r.size()));
    for(int i = 0; i < ret.size(); i++) ret[i] = (*this)[i] * r[i];
    return ret;
  }

  P operator>>(int sz) const {
    if(this->size() <= sz) return {};
    P ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  P operator<<(int sz) const {
    P ret(*this);
    ret.insert(ret.begin(), sz, T(0));
    return ret;
  }

  T operator()(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }

  P diff() const {
    const int n = (int) this->size();
    P ret(max(0, n - 1));
    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
    return ret;
  }

  P integral() const {
    const int n = (int) this->size();
    P ret(n + 1);
    ret[0] = T(0);
    for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
    return ret;
  }

  // https://judge.yosupo.jp/problem/inv_of_formal_power_series
  // F(0) must not be 0
  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }

  // https://judge.yosupo.jp/problem/log_of_formal_power_series
  // F(0) must be 1
  P log(int deg = -1) const {
    assert((*this)[0] == T(1));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  // https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
  P sqrt(int deg = -1, const function< T(T) > &get_sqrt = [](T) { return T(1); }) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if((*this)[0] == T(0)) {
      for(int i = 1; i < n; i++) {
        if((*this)[i] != T(0)) {
          if(i & 1) return {};
          if(deg - i / 2 <= 0) break;
          auto ret = (*this >> i).sqrt(deg - i / 2, get_sqrt);
          if(ret.empty()) return {};
          ret = ret << (i / 2);
          if(ret.size() < deg) ret.resize(deg, T(0));
          return ret;
        }
      }
      return P(deg, 0);
    }
    auto sqr = T(get_sqrt((*this)[0]));
    if(sqr * sqr != (*this)[0]) return {};
    P ret{sqr};
    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
    }
    return ret.pre(deg);
  }

  P sqrt(const function< T(T) > &get_sqrt, int deg = -1) const {
    return sqrt(deg, get_sqrt);
  }

  // https://judge.yosupo.jp/problem/exp_of_formal_power_series
  // F(0) must be 0
  P exp(int deg = -1) const {
    if(deg == -1) deg = this->size();
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }

  // https://judge.yosupo.jp/problem/pow_of_formal_power_series
  P pow(int64_t k, int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    for(int i = 0; i < n; i++) {
      if((*this)[i] != T(0)) {
        T rev = T(1) / (*this)[i];
        P ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
        if(i * k > deg) return P(deg, T(0));
        ret = (ret << (i * k)).pre(deg);
        if(ret.size() < deg) ret.resize(deg, T(0));
        return ret;
      }
    }
    return *this;
  }

  // https://yukicoder.me/problems/no/215
  P mod_pow(int64_t k, P g) const {
    P modinv = g.rev().inv();
    auto get_div = [&](P base) {
      if(base.size() < g.size()) {
        base.clear();
        return base;
      }
      int n = base.size() - g.size() + 1;
      return (base.rev().pre(n) * modinv.pre(n)).pre(n).rev(n);
    };
    P x(*this), ret{1};
    while(k > 0) {
      if(k & 1) {
        ret *= x;
        ret -= get_div(ret) * g;
        ret.shrink();
      }
      x *= x;
      x -= get_div(x) * g;
      x.shrink();
      k >>= 1;
    }
    return ret;
  }

  // https://judge.yosupo.jp/problem/polynomial_taylor_shift
  P taylor_shift(T c) const {
    int n = (int) this->size();
    vector< T > fact(n), rfact(n);
    fact[0] = rfact[0] = T(1);
    for(int i = 1; i < n; i++) fact[i] = fact[i - 1] * T(i);
    rfact[n - 1] = T(1) / fact[n - 1];
    for(int i = n - 1; i > 1; i--) rfact[i - 1] = rfact[i] * T(i);
    P p(*this);
    for(int i = 0; i < n; i++) p[i] *= fact[i];
    p = p.rev();
    P bs(n, T(1));
    for(int i = 1; i < n; i++) bs[i] = bs[i - 1] * c * rfact[i] * fact[i - 1];
    p = (p * bs).pre(n);
    p = p.rev();
    for(int i = 0; i < n; i++) p[i] *= rfact[i];
    return p;
  }
};


template< typename Mint >
using FPS = FormalPowerSeries< Mint >;


int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    vector< vector< int > > g(N);
    for(int i = 1; i < N; i++) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }
    if(K == 2) {
      cout << N * (N - 1) / 2 << "\n";
      continue;
    }
    modint ret = 0;
    for(int i = 0; i < N; i++) {
      vector< int > used(N, inf);
      used[i] = 0;
      vector< FPS< modint > > df;
      if(g[i].size() < K) {
        continue;
      }
      for(auto &root : g[i]) {
        queue< int > que;
        FPS< modint > dp;
        que.emplace(root);
        used[root] = 0;
        while(not que.empty()) {
          auto p = que.front();
          que.pop();
          if(used[p] >= dp.size()) {
            dp.resize(used[p] + 1);
          }
          dp[used[p]] += 1;
          for(auto &to : g[p]) {
            if(chmin(used[to], used[p] + 1)) {
              que.emplace(to);
            }
          }
        }
        df.emplace_back(dp);
      }
      sort(begin(df), end(df), [&](auto &p, auto &q) {
        return p.size() > q.size();
      });
      for(int j = 0; j < df[K - 1].size(); j++) {
        FPS< modint > arr{1};
        for(int k = 0; k < df.size(); k++) {
          if(j >= df[k].size()) {
            break;
          }
          arr *= {1, df[k][j]};
        }
        ret += arr[K];
      }
    }
    cout << ret << "\n";
  }
}