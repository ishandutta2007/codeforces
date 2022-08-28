#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

template <class T>
void chkMin(T& x, const T& y) {
  (y < x) ? void(x = y) : void();
}

struct Cd {
  double re, im;

  Cd(double re = 0, double im = 0) : re(re), im(im) {}

  inline double real() const { return re; }
  inline double imag() const { return im; }

  inline void real(double re) { this->re = re; }
  inline void imag(double im) { this->im = im; }

  inline Cd operator+(const Cd& rhs) const { return Cd(re + rhs.re, im + rhs.im); }
  inline Cd operator-(const Cd& rhs) const { return Cd(re - rhs.re, im - rhs.im); }
  inline Cd operator-() const { return Cd(-re, -im); }
  inline Cd operator*(const Cd& rhs) const { return Cd(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re); }

  inline void operator+=(const Cd& rhs) { re += rhs.re; im += rhs.im; }
  inline void operator/=(double x) { re /= x; im /= x; }

  inline friend Cd conj(const Cd& z) { return Cd(z.re, -z.im); }
};

const int N = 52, M = 110, L = 15, T = 1 << L;
const double PI = acos(-1.), INF = 1e9;

int n, m, t;
int u[M], v[M], w[M];
double p[M][T], suf[M][T];
double ex[M][T];
double dp[N][T];

namespace FFT {

  int brev[T];
  Cd w[T];

  void prepare() {
    for (int i = 1; i < T; ++i)
      brev[i] = (brev[i >> 1] >> 1) | ((i & 1) << (L - 1));
    for (int i = 0; i < T; ++i)
      w[i] = Cd(cos(2 * PI * i / T), sin(2 * PI * i / T));
  }

  void fft(Cd *a, int lgn, int sgn) {
    int n = 1 << lgn;
    int k = L;
    for (int i = 0; i < n; ++i) {
      int rv = brev[i] >> (L - lgn);
      if (rv < i)
        swap(a[i], a[rv]);
    }
    for (int t = 1; t < n; t <<= 1) {
      --k;
      for (int i = 0; i < n; i += t << 1) {
        Cd *p = a + i, *q = a + i + t;
        for (int j = 0; j < t; ++j) {
          Cd x = w[j << k] * q[j];
          q[j] = p[j] - x;
          p[j] += x;
        }
      }
    }
    if (sgn == -1) {
      reverse(a + 1, a + n);
      for (int i = 0; i < n; ++i)
        a[i] /= n;
    }
  }

  void dft(Cd *a, Cd *b, int lgn, int d) {
    int n = 1 << lgn;
    for (int i = 0; i < n; ++i)
      a[i].imag(b[i].real());
    fft(a, lgn, d);
    b[0] = conj(a[0]);
    for (int i = 1; i < n; ++i)
      b[i] = conj(a[n - i]);

    for (int i = 0; i < n; ++i) {
      Cd x = a[i], y = b[i];
      a[i] = (x + y) * 0.5;
      b[i] = (x - y) * Cd(0, -0.5);
    }
  }

  void mult(double* a, double* b, double* c, int n, int m) {
    static Cd ta[T], tb[T];
    int lgn = 0;
    while ((1 << lgn) <= n + m) ++lgn;
    memset(ta, 0, sizeof(Cd) << lgn);
    memset(tb, 0, sizeof(Cd) << lgn);
    copy(a, a + n + 1, ta);
    copy(b, b + m + 1, tb);
    //dft(ta, tb, lgn, 1);
    fft(ta, lgn, 1);
    fft(tb, lgn, 1);
    for (int i = 0; i < (1 << lgn); ++i)
      ta[i] = ta[i] * tb[i];
    fft(ta, lgn, -1);
    for (int i = 0; i <= n + m; ++i)
      c[i] = ta[i].re;
  }
}

void divideConquer(int l, int r) {
  if (l == r) {
    for (int i = 1; i <= m; ++i) {
      if (dp[u[i]][t + 1] == INF || dp[v[i]][t + 1] == INF) continue;
      chkMin(dp[u[i]][l], w[i] + ex[i][l] + suf[i][t + 1 - l] * dp[v[i]][t + 1]);
    }
    return;
  }
  int mid = (l + r) >> 1;
  divideConquer(mid + 1, r);


  int n = r - (mid + 1), m = r - l;
  static double tmp[T];
  for (int i = 1; i <= ::m; ++i) {
    for (int j = 0; j <= n; ++j) tmp[j] = dp[v[i]][r - j];
    FFT::mult(tmp, p[i], tmp, n, m);
    for (int j = n + 1; j <= m; ++j) ex[i][r - j] += tmp[j];
  }

  divideConquer(l, mid);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  FFT::prepare();

  int cost;
  scanf("%d%d%d%d", &n, &m, &t, &cost);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    for (int j = 1; j <= t; ++j) {
      int x;
      scanf("%d", &x);
      p[i][j] = x * 1e-5;
    }
    for (int j = t; j; --j)
      suf[i][j] = suf[i][j + 1] + p[i][j];
  }
  for (int i = 1; i < n; ++i)
    fill(dp[i], dp[i] + t + 2, INF);
  dp[n][t + 1] = cost;
  for (int rep = 1; rep < n; ++rep)
    for (int i = 1; i <= m; ++i)
      chkMin(dp[u[i]][t + 1], dp[v[i]][t + 1] + w[i]);

  divideConquer(0, t);
  printf("%.10f\n", dp[1][0]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}