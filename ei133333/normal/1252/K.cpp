#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);

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
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

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
  explicit FixPoint(F &&f) : F(forward< F >(f)) {}

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
    if((x += p.x) >= mod)
      x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod)
      x -= mod;
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
      if(n & 1)
        ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }

  ModInt sqrt() const {
    if(x <= 1)
      return x;
    auto v = (mod - 1) / 2;
    if(pow(v) != 1)
      return -1;
    int q = mod - 1, m = 0;
    while(~q & 1) q >>= 1, m++;
    mt19937 mt;
    ModInt z = mt();
    while(z.pow(v) != mod - 1) z = mt();
    ModInt c = z.pow(q);
    ModInt t = pow(q);
    ModInt r = pow((q + 1) / 2);
    for(; m > 1; --m) {
      ModInt tmp = t.pow(1 << (m - 2));
      if(tmp != 1)
        r = r * c, t = t * c * c;
      c = c * c;
    }
    return min(r.x, mod - r.x);
  }
};

using modint = ModInt< mod >;

template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;

  using MULT = function< P(P, P) >;
  using FFT = function< void(P &) >;

  static MULT &get_mult() {
    static MULT mult = nullptr;
    return mult;
  }

  static void set_mult(MULT f) { get_mult() = f; }

  static FFT &get_fft() {
    static FFT fft = nullptr;
    return fft;
  }

  static FFT &get_ifft() {
    static FFT ifft = nullptr;
    return ifft;
  }

  static void set_fft(FFT f, FFT g) {
    get_fft() = f;
    get_ifft() = g;
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

  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    shrink();
    return *this;
  }

  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    shrink();
    return *this;
  }

  P &operator*=(const T &v) {
    const int n = (int) this->size();
    for(int k = 0; k < n; k++) (*this)[k] *= v;
    return *this;
  }

  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    assert(get_mult() != nullptr);
    return *this = get_mult()(*this, r);
  }

  P &operator%=(const P &r) { return *this -= *this / r * r; }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }

  P pre(int sz) const { return P(begin(*this), begin(*this) + min((int) this->size(), sz)); }

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

  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
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

  // F(0) must not be 0
  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if(get_fft() != nullptr) {
      P ret(*this);
      ret.resize(deg, T(0));
      return ret.inv_fast();
    }
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }

  // F(0) must be 1
  P log(int deg = -1) const {
    assert((*this)[0] == 1);
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  P sqrt(int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if((*this)[0] == T(0)) {
      for(int i = 1; i < n; i++) {
        if((*this)[i] != T(0)) {
          if(i & 1) return {};
          if(deg - i / 2 <= 0) break;
          auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
          if(ret.size() < deg) ret.resize(deg, T(0));
          return ret;
        }
      }
      return P(deg, 0);
    }

    P ret({T(1)});
    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
    }
    return ret.pre(deg);
  }

  // F(0) must be 0
  P exp(int deg = -1) const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    if(get_fft() != nullptr) {
      P ret(*this);
      ret.resize(deg, T(0));
      return ret.exp_rec();
    }
    P ret({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }


  P online_convolution_exp(const P &conv_coeff) const {
    const int n = (int) conv_coeff.size();
    assert((n & (n - 1)) == 0);
    vector< P > conv_ntt_coeff;
    for(int i = n; i >= 1; i >>= 1) {
      P g(conv_coeff.pre(i));
      get_fft()(g);
      conv_ntt_coeff.emplace_back(g);
    }
    P conv_arg(n), conv_ret(n);
    auto rec = [&](auto rec, int l, int r, int d) -> void {
      if(r - l <= 16) {
        for(int i = l; i < r; i++) {
          T sum = 0;
          for(int j = l; j < i; j++) sum += conv_arg[j] * conv_coeff[i - j];
          conv_ret[i] += sum;
          conv_arg[i] = i == 0 ? T(1) : conv_ret[i] / i;
        }
      } else {
        int m = (l + r) / 2;
        rec(rec, l, m, d + 1);
        P pre(r - l);
        for(int i = 0; i < m - l; i++) pre[i] = conv_arg[l + i];
        get_fft()(pre);
        for(int i = 0; i < r - l; i++) pre[i] *= conv_ntt_coeff[d][i];
        get_ifft()(pre);
        for(int i = 0; i < r - m; i++) conv_ret[m + i] += pre[m + i - l];
        rec(rec, m, r, d + 1);
      }
    };
    rec(rec, 0, n, 0);
    return conv_arg;
  }

  P exp_rec() const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    int m = 1;
    while(m < n) m *= 2;
    P conv_coeff(m);
    for(int i = 1; i < n; i++) conv_coeff[i] = (*this)[i] * i;
    return online_convolution_exp(conv_coeff).pre(n);
  }


  P inv_fast() const {
    assert(((*this)[0]) != T(0));

    const int n = (int) this->size();
    P res{T(1) / (*this)[0]};

    for(int d = 1; d < n; d <<= 1) {
      P f(2 * d), g(2 * d);
      for(int j = 0; j < min(n, 2 * d); j++) f[j] = (*this)[j];
      for(int j = 0; j < d; j++) g[j] = res[j];
      get_fft()(f);
      get_fft()(g);
      for(int j = 0; j < 2 * d; j++) f[j] *= g[j];
      get_ifft()(f);
      for(int j = 0; j < d; j++) {
        f[j] = 0;
        f[j + d] = -f[j + d];
      }
      get_fft()(f);
      for(int j = 0; j < 2 * d; j++) f[j] *= g[j];
      get_ifft()(f);
      for(int j = 0; j < d; j++) f[j] = res[j];
      res = f;
    }
    return res.pre(n);
  }

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

  T eval(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }
};

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

template< typename T >
struct ArbitraryModConvolution {
  using real = FastFourierTransform::real;
  using C = FastFourierTransform::C;

  ArbitraryModConvolution() = default;

  vector< T > multiply(const vector< T > &a, const vector< T > &b, int need = -1) {
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


template< typename T >
FormalPowerSeries< T > bernoulli(int N) {
  FormalPowerSeries< T > poly(N + 1);
  poly[0] = T(1);
  for(int i = 1; i <= N; i++) {
    poly[i] = poly[i - 1] / T(i + 1);
  }
  poly = poly.inv();
  T tmp(1);
  for(int i = 1; i <= N; i++) {
    tmp *= T(i);
    poly[i] *= tmp;
  }
  return poly;
}

template< typename T >
FormalPowerSeries< T > partition(int N) {
  FormalPowerSeries< T > poly(N + 1);
  poly[0] = 1;
  for(int k = 1; k <= N; k++) {
    if(1LL * k * (3 * k + 1) / 2 <= N) poly[k * (3 * k + 1) / 2] += (k % 2 ? -1 : 1);
    if(1LL * k * (3 * k - 1) / 2 <= N) poly[k * (3 * k - 1) / 2] += (k % 2 ? -1 : 1);
  }
  return poly.inv();
}


template< typename T >
FormalPowerSeries< T > bell(int N) {
  FormalPowerSeries< T > poly(N + 1), ret(N + 1);
  poly[1] = 1;
  poly = poly.exp();
  poly[0] -= 1;
  poly = poly.exp();
  T mul = 1;
  for(int i = 0; i <= N; i++) {
    ret[i] = poly[i] * mul;
    mul *= i + 1;
  }
  return ret;
}

int main() {

  ArbitraryModConvolution< modint > fft;
  using FPS = FormalPowerSeries< modint >;
  auto mult = [&](const FPS::P &a, const FPS::P &b) {
    auto ret = fft.multiply(a, b);
    return FPS::P(ret.begin(), ret.end());
  };
  FPS::set_mult(mult);
  //FPS::set_fft([&](FPS::P &a) { ntt.ntt(a); }, [&](FPS::P &a) { ntt.intt(a); });

  int N, M;
  cin >> N >> M;
  vector< int64 > A(N);
  for(int i = 0; i < M; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < N; j++) {
      if(s[j] == '1') A[j] |= 1LL << i;
    }
  }
  map< int, int > cnt;
  for(int i = 0; i < N; i++) cnt[A[i]]++;

  auto b = bell< modint >(N + 1);
  modint ans = 1;
  for(auto &p : cnt) ans *= b[p.second];
  cout << ans << endl;
}