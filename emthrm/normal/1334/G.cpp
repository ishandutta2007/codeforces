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
vector<int> z_algorithm(const T &s) {
  int n = s.size();
  vector<int> res(n);
  res[0] = n;
  int j = 0;
  for (int i = 1; i < n;) {
    while (i + j < n && s[j] == s[i + j]) ++j;
    res[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + res[k] < j) {
      res[i + k] = res[k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return res;
}

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
    // assert(__builtin_popcount(n) == 1);
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
    // assert(__builtin_popcount(n) == 1);
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

int main() {
  const int X = 26;
  vector<int> p(X); REP(i, X) cin >> p[i], --p[i];
  vector<bool> visited(X, false);
  vector<vector<int>> cycle;
  REP(i, X) {
    if (visited[i]) continue;
    cycle.emplace_back();
    for (int pos = i; !visited[pos]; pos = p[pos]) {
      cycle.back().emplace_back(pos);
      visited[pos] = true;
    }
  }
  vector<char> rough(26);
  vector<FFT::Complex> for_s(26), for_t(26);
  REP(i, cycle.size()) {
    for (int e : cycle[i]) rough[e] = 'a' + i;
    int k = cycle[i].size();
    REP(j, k) {
      double a = 2 * M_PI * j / k, b = (1 - 2 * j) * M_PI / k;
      for_s[cycle[i][j]] = FFT::Complex(cos(a), sin(a));
      for_t[cycle[i][j]] = FFT::Complex(cos(b), sin(b));
    }
  }
  string s, t; cin >> s >> t;
  int n = s.length(), m = t.length();
  vector<bool> ans(m - n + 1, true);
  string tmp = "";
  for (char c : s) tmp += rough[c - 'a'];
  tmp += '$';
  for (char c : t) tmp += rough[c - 'a'];
  vector<int> z = z_algorithm(tmp);
  REP(i, m - n + 1) {
    if (z[n + 1 + i] < n) ans[i] = false;
  }
  double ideal = 0;
  REP(i, n) ideal += (for_s[s[i] - 'a'] * for_t[s[i] - 'a']).re;
  reverse(ALL(s));

  int lg = 1;
  while ((1 << lg) < n + m - 1) ++lg;
  int x = 1 << lg;
  vector<FFT::Complex> comp_s(x), comp_t(x);
  REP(i, n) comp_s[i] = for_s[s[i] - 'a'];
  REP(i, m) comp_t[i] = for_t[t[i] - 'a'];
  FFT::sub_dft(comp_s);
  FFT::sub_dft(comp_t);
  REP(i, x) comp_s[i] = comp_s[i] * comp_t[i];
  FFT::idft(comp_s);
  REP(i, m - n + 1) {
    if (abs(comp_s[n - 1 + i].re - ideal) > 0.01) ans[i] = false;
  }
  REP(i, m - n + 1) cout << ans[i];
  cout << '\n';
  return 0;
}