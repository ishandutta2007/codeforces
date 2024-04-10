#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T>
function<vector<T>(const vector<T>&, const vector<T>&)> mul = [](const vector<T> &a, const vector<T> &b) {
  int n = a.size(), m = b.size();
  vector<T> res(n + m - 1, 0);
  REP(i, n) REP(j, m) res[i + j] += a[i] * b[j];
  return res;
};

template <typename T>
function<bool(const T&, T&)> sqr = [](const T &a, T &res) {
  return false;
};

template <typename T>
struct FPS {
  vector<T> co;

  FPS(int deg = 0) : co(deg + 1, 0) {}
  FPS(const vector<T> &co) : co(co) {}
  FPS(initializer_list<T> init) : co(init.begin(), init.end()) {}
  template <typename InputIter> FPS(InputIter first, InputIter last) : co(first, last) {}

  inline const T &operator[](int term) const { return co[term]; }
  inline T &operator[](int term) { return co[term]; }

  void resize(int deg) { co.resize(deg + 1, 0); }

  void shrink() { while (co.size() > 1 && co.back() == 0) co.pop_back(); }

  int degree() const { return static_cast<int>(co.size()) - 1; }

  FPS &operator=(const vector<T> &new_co) {
    co.resize(new_co.size());
    copy(ALL(new_co), co.begin());
    return *this;
  }

  FPS &operator=(const FPS &x) {
    co.resize(x.co.size());
    copy(ALL(x.co), co.begin());
    return *this;
  }

  FPS &operator+=(const FPS &x) {
    int n = x.co.size();
    if (n > co.size()) resize(n - 1);
    REP(i, n) co[i] += x.co[i];
    return *this;
  }

  FPS &operator-=(const FPS &x) {
    int n = x.co.size();
    if (n > co.size()) resize(n - 1);
    REP(i, n) co[i] -= x.co[i];
    return *this;
  }

  FPS &operator*=(T x) {
    for (T &e : co) e *= x;
    return *this;
  }

  FPS &operator*=(const FPS &x) { return *this = mul<T>(co, x.co); }

  FPS &operator/=(T x) {
    assert(x != 0);
    T inv_x = T(1) / x;
    for (T &e : co) e *= inv_x;
    return *this;
  }

  FPS &operator/=(const FPS &x) {
    int sz = x.co.size();
    if (sz > co.size()) return *this = FPS();
    int n = co.size() - sz + 1;
    FPS a(co.rbegin(), co.rbegin() + n), b(x.co.rbegin(), x.co.rbegin() + min(sz, n));
    b = b.inv(n - 1);
    a *= b;
    return *this = FPS(a.co.rend() - n, a.co.rend());
  }

  FPS &operator%=(const FPS &x) {
    *this -= *this / x * x;
    co.resize(static_cast<int>(x.co.size()) - 1);
    if (co.empty()) co = {0};
    return *this;
  }

  FPS &operator<<=(int n) {
    co.insert(co.begin(), n, 0);
    return *this;
  }

  FPS &operator>>=(int n) {
    if (co.size() < n) return *this = FPS();
    co.erase(co.begin(), co.begin() + n);
    return *this;
  }

  bool operator==(const FPS &x) const {
    FPS a(*this), b(x);
    a.shrink(); b.shrink();
    int n = a.co.size();
    if (n != b.co.size()) return false;
    REP(i, n) if (a.co[i] != b.co[i]) return false;
    return true;
  }

  bool operator!=(const FPS &x) const { return !(*this == x); }

  FPS operator+() const { return *this; }

  FPS operator-() const {
    FPS res(*this);
    for (T &e : res.co) e = -e;
    return res;
  }

  FPS operator+(const FPS &x) const { return FPS(*this) += x; }

  FPS operator-(const FPS &x) const { return FPS(*this) -= x; }

  FPS operator*(T x) const { return FPS(*this) *= x; }

  FPS operator*(const FPS &x) const { return FPS(*this) *= x; }

  FPS operator/(T x) const { return FPS(*this) /= x; }

  FPS operator/(const FPS &x) const { return FPS(*this) /= x; }

  FPS operator%(const FPS &x) const { return FPS(*this) %= x; }

  FPS operator<<(int n) const { return FPS(*this) <<= n; }

  FPS operator>>(int n) const { return FPS(*this) >>= n; }

  T horner(T val) const {
    T res = 0;
    for (int i = static_cast<int>(co.size()) - 1; i >= 0; --i) (res *= val) += co[i];
    return res;
  }

  FPS differential() const {
    int n = co.size();
    assert(n >= 1);
    FPS res(n - 1);
    FOR(i, 1, n) res.co[i - 1] = co[i] * i;
    return res;
  }

  FPS integral() const {
    int n = co.size();
    FPS res(n + 1);
    REP(i, n) res[i + 1] = co[i] / (i + 1);
    return res;
  }

  FPS exp(int deg = -1) const {
    assert(co[0] == 0);
    int n = co.size();
    if (deg == -1) deg = n - 1;
    FPS one{1}, res = one;
    for (int i = 1; i <= deg; i <<= 1) {
      res *= FPS(co.begin(), co.begin() + min(n, i << 1)) - res.log((i << 1) - 1) + one;
      res.co.resize(i << 1);
    }
    res.co.resize(deg + 1);
    return res;
  }

  FPS inv(int deg = -1) const {
    assert(co[0] != 0);
    int n = co.size();
    if (deg == -1) deg = n - 1;
    FPS res{T(1) / co[0]};
    for (int i = 1; i <= deg; i <<= 1) {
      res = res + res - res * res * FPS(co.begin(), co.begin() + min(n, i << 1));
      res.co.resize(i << 1);
    }
    res.co.resize(deg + 1);
    return res;
  }

  FPS log(int deg = -1) const {
    assert(co[0] == 1);
    if (deg == -1) deg = static_cast<int>(co.size()) - 1;
    FPS integrand = differential() * inv(deg - 1);
    integrand.co.resize(deg);
    return integrand.integral();
  }

  FPS pow(ll exponent, int deg = -1) const {
    int n = co.size();
    if (deg == -1) deg = n - 1;
    REP(i, n) {
      if (co[i] != 0) {
        ll shift = exponent * i;
        if (shift > deg) break;
        T tmp = 1, base = co[i];
        ll e = exponent;
        while (e > 0) {
          if (e & 1) tmp *= base;
          base *= base;
          e >>= 1;
        }
        return ((((*this >> i) * (T(1) / co[i])).log(deg - shift) * T(exponent)).exp(deg - shift) * tmp) << shift;
      }
    }
    return FPS(deg);
  }

  FPS mod_pow(ll exponent, const FPS &md) const {
    FPS inv_rev_md = FPS(md.co.rbegin(), md.co.rend()).inv();
    int deg_of_md = md.co.size();
    function<void(FPS&, const FPS&)> mod_mul = [&](FPS &multiplicand, const FPS &multiplier) {
      multiplicand *= multiplier;
      if (deg_of_md <= multiplicand.co.size()) {
        int n = multiplicand.co.size() - deg_of_md + 1;
        FPS quotient = FPS(multiplicand.co.rbegin(), multiplicand.co.rbegin() + n) * FPS(inv_rev_md.co.begin(), inv_rev_md.co.begin() + min(static_cast<int>(inv_rev_md.co.size()), n));
        multiplicand -= FPS(quotient.co.rend() - n, quotient.co.rend()) * md;
      }
      multiplicand.co.resize(deg_of_md - 1);
      if (multiplicand.co.empty()) multiplicand.co = {0};
    };
    FPS res{1}, base = *this;
    mod_mul(base, res);
    while (exponent > 0) {
      if (exponent & 1) mod_mul(res, base);
      mod_mul(base, base);
      exponent >>= 1;
    }
    return res;
  }

  FPS sqrt(int deg = -1) const {
    int n = co.size();
    if (deg == -1) deg = n - 1;
    if (co[0] == 0) {
      FOR(i, 1, n) {
        if (co[i] == 0) continue;
        if (i & 1) return FPS(-1);
        int shift = i >> 1;
        if (deg < shift) break;
        FPS res = (*this >> i).sqrt(deg - shift);
        if (res.co.empty()) return FPS(-1);
        res <<= shift;
        res.resize(deg);
        return res;
      }
      return FPS(deg);
    }
    T s;
    if (!sqr<T>(co[0], s)) return FPS(-1);
    FPS res{s};
    T half = T(1) / 2;
    for (int i = 1; i <= deg; i <<= 1) {
      (res += FPS(co.begin(), co.begin() + min(n, i << 1)) * res.inv((i << 1) - 1)) *= half;
    }
    res.resize(deg);
    return res;
  }

  FPS translate(T c) const {
    int n = co.size();
    vector<T> fact(n, 1), inv_fact(n, 1);
    FOR(i, 1, n) fact[i] = fact[i - 1] * i;
    inv_fact[n - 1] = T(1) / fact[n - 1];
    for (int i = n - 1; i > 0; --i) inv_fact[i - 1] = inv_fact[i] * i;
    vector<T> g(n), ex(n);
    REP(i, n) g[n - 1 - i] = co[i] * fact[i];
    T pow_c = 1;
    REP(i, n) {
      ex[i] = pow_c * inv_fact[i];
      pow_c *= c;
    }
    vector<T> conv = mul<T>(g, ex);
    FPS res(n - 1);
    REP(i, n) res[i] = conv[n - 1 - i] * inv_fact[i];
    return res;
  }
};

namespace FFT {
  using Real = double;
  struct Complex {
    Real re, im;
    Complex(Real re = 0, Real im = 0) : re(re), im(im) {}
    inline Complex operator+(const Complex &x) const { return Complex(re + x.re, im + x.im); }
    inline Complex operator-(const Complex &x) const { return Complex(re - x.re, im - x.im); }
    inline Complex operator*(const Complex &x) const { return Complex(re * x.re - im * x.im, re * x.im + im * x.re); }
    inline Complex mul_real(Real r) const { return Complex(re * r, im * r); }
    inline Complex mul_pin(Real r) const { return Complex(-im * r, re * r); }
    inline Complex conj() const { return Complex(re, -im); }
  };

  vector<int> butterfly{0};
  vector<vector<Complex>> zeta{{{1, 0}}};

  void calc(int n) {
    int prev_n = butterfly.size();
    if (n <= prev_n) return;
    butterfly.resize(n);
    int prev_lg = zeta.size(), lg = __builtin_ctz(n);
    FOR(i, 1, prev_n) butterfly[i] <<= lg - prev_lg;
    FOR(i, prev_n, n) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    zeta.resize(lg);
    FOR(i, prev_lg, lg) {
      zeta[i].resize(1 << i);
      Real angle = -M_PI * 2 / (1 << (i + 1));
      REP(j, 1 << (i - 1)) {
        zeta[i][j << 1] = zeta[i - 1][j];
        Real theta = angle * ((j << 1) + 1);
        zeta[i][(j << 1) + 1] = {cos(theta), sin(theta)};
      }
    }
  }

  void sub_dft(vector<Complex> &a) {
    int n = a.size();
    assert(__builtin_popcount(n) == 1);
    calc(n);
    int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
    REP(i, n) {
      int j = butterfly[i] >> shift;
      if (i < j) swap(a[i], a[j]);
    }
    for (int block = 1; block < n; block <<= 1) {
      int den = __builtin_ctz(block);
      for (int i = 0; i < n; i += (block << 1)) REP(j, block) {
        Complex tmp = a[i + j + block] * zeta[den][j];
        a[i + j + block] = a[i + j] - tmp;
        a[i + j] = a[i + j] + tmp;
      }
    }
  }

  template <typename T>
  vector<Complex> dft(const vector<T> &a) {
    int sz = a.size(), lg = 1;
    while ((1 << lg) < sz) ++lg;
    vector<Complex> c(1 << lg);
    REP(i, sz) c[i].re = a[i];
    sub_dft(c);
    return c;
  }

  vector<Real> real_idft(vector<Complex> &a) {
    int n = a.size(), half = n >> 1, quarter = half >> 1;
    assert(__builtin_popcount(n) == 1);
    calc(n);
    a[0] = (a[0] + a[half] + (a[0] - a[half]).mul_pin(1)).mul_real(0.5);
    int den = __builtin_ctz(half);
    FOR(i, 1, quarter) {
      int j = half - i;
      Complex tmp1 = a[i] + a[j].conj(), tmp2 = ((a[i] - a[j].conj()) * zeta[den][j]).mul_pin(1);
      a[i] = (tmp1 - tmp2).mul_real(0.5);
      a[j] = (tmp1 + tmp2).mul_real(0.5).conj();
    }
    if (quarter > 0) a[quarter] = a[quarter].conj();
    a.resize(half);
    sub_dft(a);
    reverse(a.begin() + 1, a.end());
    Real r = 1.0 / half;
    vector<Real> res(n);
    REP(i, n) res[i] = (i & 1 ? a[i >> 1].im : a[i >> 1].re) * r;
    return res;
  }

  void idft(vector<Complex> &a) {
    int n = a.size();
    sub_dft(a);
    reverse(a.begin() + 1, a.end());
    Real r = 1.0 / n;
    REP(i, n) a[i] = a[i].mul_real(r);
  }

  template <typename T>
  vector<Real> convolution(const vector<T> &a, const vector<T> &b) {
    int a_sz = a.size(), b_sz = b.size(), sz = a_sz + b_sz - 1, lg = 1;
    while ((1 << lg) < sz) ++lg;
    int n = 1 << lg;
    vector<Complex> c(n);
    REP(i, a_sz) c[i].re = a[i];
    REP(i, b_sz) c[i].im = b[i];
    sub_dft(c);
    int half = n >> 1;
    c[0] = Complex(c[0].re * c[0].im, 0);
    FOR(i, 1, half) {
      Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];
      c[i] = (j_square.conj() - i_square).mul_pin(0.25);
      c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);
    }
    c[half] = Complex(c[half].re * c[half].im, 0);
    vector<Real> res = real_idft(c);
    res.resize(sz);
    return res;
  }
};

template <typename T>
vector<T> divisor(T val) {
  vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  sort(ALL(res));
  return res;
}

int main() {
  mul<int> = [&](const vector<int> &a, const vector<int> &b) {
    vector<FFT::Real> c = FFT::convolution(a, b);
    vector<int> res(c.size());
    REP(i, c.size()) res[i] = round(c[i]);
    return res;
  };
  const int B = 200000, L = 1000000;
  int n, x, y; cin >> n >> x >> y;
  FPS<int> a(B * 2), b(B * 2);
  REP(_, n + 1) {
    int ai; cin >> ai;
    a[B + ai] = b[B - ai] = 1;
  }
  a *= b;
  vector ans(B + 1, false);
  FOR(i, 1, B + 1) ans[i] = a[B * 2 + i] > 0;
  vector<int> memo(L + 1, -2);
  int q; cin >> q;
  while (q--) {
    int l; cin >> l;
    if (memo[l] == -2) {
      memo[l] = -1;
      vector<int> ds = divisor(l);
      reverse(ALL(ds));
      for (int lap : ds) {
        if ((lap & 1) || lap > (x + y) * 2) continue;
        if (lap <= y * 2) break;
        int len = (lap - y * 2) / 2;
        if (ans[len]) {
          memo[l] = lap;
          break;
        }
      }
    }
    cout << memo[l] << " \n"[q == 0];
  }
  return 0;
}