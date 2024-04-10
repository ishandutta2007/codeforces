#include <cstdio>
#include <cstring>

#include <functional>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int P = 998244353, R = 3;

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  if (x < 0)
    x += P;
  return x;
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}

// currently
int msqrt(int x) {
  return 1;
}

struct Simple {
  int n;
  vector<int> fac, ifac, inv;

  void build(int n) {
    this->n = n;
    fac.resize(n + 1);
    ifac.resize(n + 1);
    inv.resize(n + 1);
    fac[0] = 1;
    for (int x = 1; x <= n; ++x)
      fac[x] = fac[x - 1] * (ll)x % P;
    inv[1] = 1;
    for (int x = 2; x <= n; ++x)
      inv[x] = -(P / x) * (ll)inv[P % x] % P + P;
    ifac[0] = 1;
    for (int x = 1; x <= n; ++x)
      ifac[x] = ifac[x - 1] * (ll)inv[x] % P;
  }

  Simple() {
    build(1);
  }

  void check(int k) {
    int nn = n;
    if (k > nn) {
      while (k > nn)
        nn <<= 1;
      build(nn);
    }
  }

  int gfac(int k) {
    check(k);
    return fac[k];
  }

  int gifac(int k) {
    check(k);
    return ifac[k];
  }

  int ginv(int k) {
    check(k);
    return inv[k];
  }

  int binom(int n, int m) {
    if (m < 0 || m > n)
      return 0;
    return gfac(n) * (ll)gifac(m) % P * gifac(n - m) % P;
  }
} simp;

const int L2 = 11;

struct NTT {
  int brev[1 << L2];

  NTT() {
    for (int i = 1; i < (1 << L2); ++i)
      brev[i] = brev[i >> 1] >> 1 | ((i & 1) << (L2 - 1));
  }

  void fft(int* a, int lgn, int d) {
    int n = 1 << lgn;
    for (int i = 0; i < n; ++i) {
      int rev = (brev[i >> L2] | (brev[i & ((1 << L2) - 1)] << L2)) >> ((L2 << 1) - lgn);
      if (i < rev)
        swap(a[i], a[rev]);
    }
    int rt = d == 1 ? R : inv(R);
    for (int i = 0; i < lgn; ++i) {
      int t = 1 << i;
      int omega = mpow(rt, (P - 1) >> (i + 1));
      for (int j = 0; j < n; j += t << 1) {
        int w = 1;
        for (int k = 0; k < t; ++k) {
          int a0 = a[j + k], a1 = a[j + k + t];
          a[j + k] = (a0 + w * (ll)a1) % P;
          a[j + k + t] = (a0 + (P - w) * (ll)a1) % P;
          w = w * (ll)omega % P;
        }
      }
    }
    if (d == -1) {
      int in = inv(n);
      for (int i = 0; i < n; ++i)
        a[i] = a[i] * (ll)in % P;
    }
  }

  // assume this is a large amount of trailing zero, better constant
  void fftLead(int* a, int lgn) {
    int n = 1 << lgn;
    int lst = (1 << lgn) - 1;
    while (lst && !a[lst])
      --lst;
    int l2 = 0;
    while ((1 << l2) <= lst)
      ++l2;
    for (int i = 0; i < n; ++i) {
      int rev = (brev[i >> L2] | (brev[i & ((1 << L2) - 1)] << L2)) >> ((L2 << 1) - lgn);
      if (i < rev)
        swap(a[i], a[rev]);
    }
    for (int i = 0; i < lgn - l2; ++i) {
      int t = 1 << i;
      int omega = mpow(R, (P - 1) >> (i + 1));
      for (int j = 0; j < n; j += 1 << (lgn - l2)) {
        int w = 1;
        for (int k = 0; k < t; ++k) {
          int a0 = a[j + k], a1 = a[j + k + t];
          a[j + k] = (a0 + w * (ll)a1) % P;
          a[j + k + t] = (a0 + (P - w) * (ll)a1) % P;
          w = w * (ll)omega % P;
        }
      }
    }
    for (int i = lgn - l2; i < lgn; ++i) {
      int t = 1 << i;
      int omega = mpow(R, (P - 1) >> (i + 1));
      for (int j = 0; j < n; j += t << 1) {
        int w = 1;
        for (int k = 0; k < t; ++k) {
          int a0 = a[j + k], a1 = a[j + k + t];
          a[j + k] = (a0 + w * (ll)a1) % P;
          a[j + k + t] = (a0 + (P - w) * (ll)a1) % P;
          w = w * (ll)omega % P;
        }
      }
    }
  }
} ntt;

template <class Func, class... Args>
vector<int> tr(vector<int> v, Func f, Args... args) {
  f(v.begin().base(), args...);
  return v;
}

struct Poly {
  vector<int> a;

  Poly(int v = 0) : a(1) {
    if ((v %= P) < 0)
      v += P;
    a[0] = v;
  }

  Poly(const vector<int>& a) : a(a) {}

  Poly(initializer_list<int> init) : a(init) {}

  // Helps
  int operator[](int k) const { return k < a.size() ? a[k] : 0; }

  int& operator[](int k) {
    if (k >= a.size())
      a.resize(k + 1);
    return a[k];
  }

  int deg() const { return a.size() - 1; }

  void redeg(int d) { a.resize(d + 1); }

  Poly monic() const;
  Poly sunic() const;

  Poly slice(int d) const {
    if (d < a.size())
      return vector<int>(a.begin(), a.begin() + d + 1);
    vector<int> res(a);
    res.resize(d + 1);
    return res;
  }

  int* base() { return a.begin().base(); }
  const int* base() const { return a.begin().base(); }

  Poly println(FILE* fp) const {
    fprintf(fp, "%d", a[0]);
    for (int i = 1; i < a.size(); ++i)
      fprintf(fp, " %d", a[i]);
    fputc('\n', fp);
    return *this;
  }

  // Calculations
  Poly operator+(const Poly& rhs) const {
    vector<int> res(max(a.size(), rhs.a.size()));
    for (int i = 0; i < res.size(); ++i)
      if ((res[i] = operator[](i) + rhs[i]) >= P)
        res[i] -= P;
    return res;
  }

  Poly operator-() const {
    Poly ret(a);
    for (int i = 0; i < a.size(); ++i)
      if (ret[i])
        ret[i] = P - ret[i];
    return ret;
  }

  Poly operator-(const Poly& rhs) const { return operator+(-rhs); }

  Poly operator*(const Poly& rhs) const;

  Poly operator/(const Poly& rhs) const;

  Poly operator%(const Poly& rhs) const;

  Poly der() const; // default: remove trailing
  Poly integ() const;

  Poly inv() const;
  Poly sqrt() const;
  Poly ln() const;
  Poly exp() const;
  pair<Poly, Poly> sqrti() const;

  Poly quo(const Poly& rhs) const;
  pair<Poly, Poly> iquo(const Poly& rhs) const;

  Poly shift(int k) const;
  Poly pow(int k) const;
  Poly exp(int k) const;
};

Poly zeroes(int deg) { return vector<int>(deg + 1); }

struct Newton {
  void inv(const Poly& f, const Poly& nttf, Poly& g, const Poly& nttg, int t) {
    int n = 1 << t;
    Poly prod = nttf;
    for (int i = 0; i < (n << 1); ++i)
      prod[i] = prod[i] * (ll)nttg[i] % P;
    ntt.fft(prod.base(), t + 1, -1);
    for (int i = 0; i < n; ++i)
      prod[i] = 0;
    ntt.fft(prod.base(), t + 1, 1);
    for (int i = 0; i < (n << 1); ++i)
      prod[i] = prod[i] * (ll)nttg[i] % P;
    ntt.fft(prod.base(), t + 1, -1);
    for (int i = 0; i < n; ++i)
      prod[i] = 0;
    g = g - prod;
  }

  void inv(const Poly& f, const Poly& nttf, Poly& g, int t) {
    Poly nttg = g;
    nttg.redeg((2 << t) - 1);
    ntt.fftLead(nttg.base(), t + 1);
    inv(f, nttf, g, nttg, t);
  }

  void inv(const Poly& f, Poly& g, int t) {
    Poly nttg = g;
    nttg.redeg((2 << t) - 1);
    ntt.fftLead(nttg.base(), t + 1);
    Poly nttf = f;
    nttf.redeg((2 << t) - 1);
    ntt.fft(nttf.base(), t + 1, 1);
    inv(f, nttf, g, nttg, t);
  }

  void sqrt(const Poly& f, Poly& g, Poly& nttg, Poly& h, int t) {
    for (int i = 0; i < (1 << t); ++i)
      nttg[i] = mpow(nttg[i], 2);
    ntt.fft(nttg.base(), t, -1);
    nttg = nttg - f;
    for (int i = 0; i < (1 << t); ++i)
      if ((nttg[i + (1 << t)] += nttg[i]) >= P)
        nttg[i + (1 << t)] -= P;
    memset(nttg.base(), 0, sizeof(int) << t);
    ntt.fft(nttg.base(), t + 1, 1);
    Poly tmp = h;
    tmp.redeg((2 << t) - 1);
    ntt.fftLead(tmp.base(), t + 1);
    for (int i = 0; i < (2 << t); ++i)
      tmp[i] = tmp[i] * (ll)nttg[i] % P;
    ntt.fft(tmp.base(), t + 1, -1);
    memset(tmp.base(), 0, sizeof(int) << t);
    g = g - tmp * ::inv(2);
  }

  void exp(const Poly& f, Poly& g, Poly& nttg, Poly& h, int t) {
    Poly ntth(h);
    ntt.fft(ntth.base(), t, 1);
    Poly dg = g.der().slice((1 << t) - 1);
    ntt.fft(dg.base(), t, 1);
    Poly tmp = zeroes((1 << t) - 1);
    for (int i = 0; i < (1 << t); ++i) {
      tmp[i] = nttg[i << 1] * (ll)ntth[i] % P;
      dg[i] = dg[i] * (ll)ntth[i] % P;
    }
    ntt.fft(tmp.base(), t, -1);
    ntt.fft(dg.base(), t, -1);
    if (--tmp[0] < 0)
      tmp[0] = P - 1;
    dg.redeg((2 << t) - 1);
    Poly df0 = f.der().slice((1 << t) - 1);
    df0[(1 << t) - 1] = 0;
    for (int i = 0; i < (1 << t); ++i) {
      if ((dg[i | 1 << t] = dg[i] - df0[i]) < 0)
        dg[i | 1 << t] += P;
    }
    memcpy(dg.base(), df0.base(), sizeof(int) * ((1 << t) - 1));
    tmp.redeg((2 << t) - 1);
    ntt.fftLead(tmp.base(), t + 1);
    df0.redeg((2 << t) - 1);
    ntt.fftLead(df0.base(), t + 1);
    for (int i = 0; i < (2 << t); ++i)
      df0[i] = df0[i] * (ll)tmp[i] % P;
    ntt.fft(df0.base(), t + 1, -1);
    memcpy(df0.base() + (1 << t), df0.base(), sizeof(int) << t);
    memset(df0.base(), 0, sizeof(int) << t);
    dg = (dg - df0).integ().slice((2 << t) - 1) - f;
    ntt.fft(dg.base(), t + 1, 1);
    for (int i = 0; i < (2 << t); ++i)
      tmp[i] = dg[i] * (ll)nttg[i] % P;
    ntt.fft(tmp.base(), t + 1, -1);
    g.redeg((2 << t) - 1);
    for (int i = 1 << t; i < (2 << t); ++i)
      if (tmp[i])
        g[i] = P - tmp[i];
  }
} nit;

Poly operator "" _z(unsigned long long a) { return {0, (int)a}; }

Poly operator+(int v, const Poly& rhs) { return Poly(v) + rhs; }

Poly Poly::operator*(const Poly& rhs) const {
  int n = deg(), m = rhs.deg();
  if (n <= 10 || m <= 10) {
    Poly ret = zeroes(n + m);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        ret[i + j] = (ret[i + j] + a[i] * (ll)rhs[j]) % P;
    return ret;
  }
  n += m;
  int l = 0;
  while ((1 << l) <= n)
    ++l;
  vector<int> res(1 << l), tmp(1 << l);
  memcpy(res.begin().base(), base(), a.size() * sizeof(int));
  ntt.fft(res.begin().base(), l, 1);
  memcpy(tmp.begin().base(), rhs.base(), rhs.a.size() * sizeof(int));
  ntt.fft(tmp.begin().base(), l, 1);
  for (int i = 0; i < (1 << l); ++i)
    res[i] = res[i] * (ll)tmp[i] % P;
  ntt.fft(res.begin().base(), l, -1);
  res.resize(n + 1);
  return res;
}

Poly Poly::inv() const {
  Poly g = ::inv(a[0]);
  for (int t = 0; (1 << t) <= deg(); ++t)
    nit.inv(slice((2 << t) - 1), g, t);
  g.redeg(deg());
  return g;
}

Poly Poly::shift(int k) const {
  int n = deg();
  Poly t = zeroes(n);
  simp.check(n);
  for (int i = 0; i <= n; ++i)
    t[n - i] = a[i] * (ll)simp.fac[i] % P;
  int pw = 1;
  Poly help = vector<int>(simp.ifac.begin(), simp.ifac.begin() + n + 1);
  for (int i = 0; i <= n; ++i) {
    help[i] = help[i] * (ll)pw % P;
    pw = pw * (ll)k % P;
  }
  t = t * help;
  for (int i = 0; i <= n; ++i)
    help[i] = t[n - i] * (ll)simp.ifac[i] % P;
  return help;
}

Poly Poly::pow(int k) const {
  if (k == 0)
    return 1;
  if (k == 1)
    return *this;
  int n = deg() * k;
  int lgn = 0;
  while ((1 << lgn) <= n)
    ++lgn;
  vector<int> val = a;
  val.resize(1 << lgn);
  ntt.fftLead(val.begin().base(), lgn);
  for (int i = 0; i < (1 << lgn); ++i)
    val[i] = mpow(val[i], k);
  ntt.fft(val.begin().base(), lgn, -1);
  return val;
}

Poly Poly::der() const {
  if (deg() == 0)
    return 0;
  vector<int> res(deg());
  for (int i = 0; i < deg(); ++i)
    res[i] = a[i + 1] * (ll)(i + 1) % P;
  return res;
}

Poly Poly::integ() const {
  vector<int> res(deg() + 2);
  simp.check(deg() + 1);
  for (int i = 0; i <= deg(); ++i)
    res[i + 1] = a[i] * (ll)simp.inv[i + 1] % P;
  return res;
}

Poly Poly::quo(const Poly &rhs) const {
  if (rhs.deg() == 0)
    return a[0] * (ll) ::inv(rhs[0]) % P;
  Poly g = ::inv(rhs[0]);
  int t = 0, n;
  for (n = 1; (n << 1) <= rhs.deg(); ++t, n <<= 1)
    nit.inv(rhs.slice((n << 1) - 1), g, t);
  Poly nttg = g;
  nttg.redeg((n << 1) - 1);
  ntt.fftLead(nttg.base(), t + 1);
  Poly eps1 = rhs.slice((n << 1) - 1);
  ntt.fft(eps1.base(), t + 1, 1);
  for (int i = 0; i < (n << 1); ++i)
    eps1[i] = eps1[i] * (ll) nttg[i] % P;
  ntt.fft(eps1.base(), t + 1, -1);
  memcpy(eps1.base(), eps1.base() + n, sizeof(int) << t);
  memset(eps1.base() + n, 0, sizeof(int) << t);
  ntt.fftLead(eps1.base(), t + 1);
  Poly h0 = slice(n - 1);
  h0.redeg((n << 1) - 1);
  ntt.fftLead(h0.base(), t + 1);
  Poly h0g0 = zeroes((n << 1) - 1);
  for (int i = 0; i < (n << 1); ++i)
    h0g0[i] = h0[i] * (ll)nttg[i] % P;
  ntt.fft(h0g0.base(), t + 1, -1);
  Poly h0eps1 = zeroes((n << 1) - 1);
  for (int i = 0; i < (n << 1); ++i)
    h0eps1[i] = h0[i] * (ll)eps1[i] % P;
  ntt.fft(h0eps1.base(), t + 1, -1);
  for (int i = 0; i < n; ++i) {
    h0eps1[i] = operator[](i + n) - h0eps1[i];
    if (h0eps1[i] < 0)
      h0eps1[i] += P;
  }
  memset(h0eps1.base() + n, 0, sizeof(int) << t);
  ntt.fftLead(h0eps1.base(), t + 1);
  for (int i = 0; i < (n << 1); ++i)
    h0eps1[i] = h0eps1[i] * (ll)nttg[i] % P;
  ntt.fft(h0eps1.base(), t + 1, -1);
  memcpy(h0eps1.base() + n, h0eps1.base(), sizeof(int) << t);
  memset(h0eps1.base(), 0, sizeof(int) << t);
  return (h0g0 + h0eps1).slice(rhs.deg());
}

Poly Poly::ln() const {
  if (deg() == 0)
    return 0;
  return der().quo(slice(deg() - 1)).integ();
}

pair<Poly, Poly> Poly::sqrti() const {
  Poly g = 1, h = 1, nttg = 1;
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.sqrt(slice((2 << t) - 1), g, nttg, h, t);
    nttg = g;
    ntt.fft(nttg.base(), t + 1, 1);
    nit.inv(g, nttg, h, t);
  }
  return make_pair(g.slice(deg()), h.slice(deg()));
}

Poly Poly::sqrt() const {
  Poly g = 1, h = 1, nttg = 1;
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.sqrt(slice((2 << t) - 1), g, nttg, h, t);
    if ((2 << t) <= deg()) {
      nttg = g;
      ntt.fft(nttg.base(), t + 1, 1);
      nit.inv(g, nttg, h, t);
    }
  }
  return g.slice(deg());
}

Poly Poly::exp() const {
  Poly g = 1, h = 1, nttg = {1, 1};
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.exp(slice((2 << t) - 1), g, nttg, h, t);
    if ((2 << t) <= deg()) {
      nttg = g;
      nttg.redeg((4 << t) - 1);
      ntt.fftLead(nttg.base(), t + 2);
      Poly f2n = zeroes((2 << t) - 1);
      for (int i = 0; i < (2 << t); ++i)
        f2n[i] = nttg[i << 1];
      nit.inv(g, f2n, h, t);
    } else {
      nttg = g;
      ntt.fft(nttg.base(), t + 1, 1);
    }
  }
  return g.slice(deg());
}

Poly Poly::exp(int k) const {
  int lead, lz = 0;
  while (lz < deg() && !a[lz])
    ++lz;
  if (lz == deg() && !a[lz])
    return *this;
  lead = a[lz];
  if (lz * (ll)k > deg())
    return zeroes(deg());
  Poly part = Poly(vector<int>(a.begin() + lz, a.begin() + deg() - lz * (k - 1) + 1)) * ::inv(lead);
  part = (part.ln() * k).exp() * mpow(lead, k);
  vector<int> ret(deg() + 1);
  memcpy(ret.begin().base() + lz * k, part.base(), sizeof(int) * (deg() - lz * k + 1));
  return ret;
}

#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
#ifdef CAI_WEI_HAN
  int cl = clock();
	freopen("test.in", "r", stdin);
#endif

  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    Poly sq, isq;
    tie(sq, isq) = Poly{1, 6, 1}.slice(k).sqrti();
    Poly q1 = (Poly{1, 1} - sq) * inv(2), q2 = q1 + sq;
    Poly res = (isq * Poly{1, 1}).slice(k), a = (-res + 1) * inv(2), b = (res + 1) * inv(2);
    Poly ans = q1.exp(n) * a + q2.exp(n) * b;
    for (int i = 1; i <= k; ++i)
      printf("%d ", ans[i]);
    putchar('\n');
  }

#ifdef CAI_WEI_HAN
  LOG("user time: %dms\n", (clock() - cl) * 1000 / CLOCKS_PER_SEC);
#endif
  return 0;
}