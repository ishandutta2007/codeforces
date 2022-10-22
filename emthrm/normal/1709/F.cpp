#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 998244353;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <int M>
struct MInt {
  unsigned int v;
  MInt() : v(0) {}
  MInt(const long long x) : v(x >= 0 ? x % M : x % M + M) {}
  static constexpr int get_mod() { return M; }
  static void set_mod(const int divisor) { assert(divisor == M); }
  static void init(const int x = 10000000) {
    inv(x, true);
    fact(x);
    fact_inv(x);
  }
  static MInt inv(const int n, const bool init = false) {
    // assert(0 <= n && n < M && std::__gcd(n, M) == 1);
    static std::vector<MInt> inverse{0, 1};
    const int prev = inverse.size();
    if (n < prev) {
      return inverse[n];
    } else if (init) {
      // "n!" and "M" must be disjoint.
      inverse.resize(n + 1);
      for (int i = prev; i <= n; ++i) {
        inverse[i] = -inverse[M % i] * (M / i);
      }
      return inverse[n];
    }
    int u = 1, v = 0;
    for (unsigned int a = n, b = M; b;) {
      const unsigned int q = a / b;
      std::swap(a -= q * b, b);
      std::swap(u -= q * v, v);
    }
    return u;
  }
  static MInt fact(const int n) {
    static std::vector<MInt> factorial{1};
    const int prev = factorial.size();
    if (n >= prev) {
      factorial.resize(n + 1);
      for (int i = prev; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i;
      }
    }
    return factorial[n];
  }
  static MInt fact_inv(const int n) {
    static std::vector<MInt> f_inv{1};
    const int prev = f_inv.size();
    if (n >= prev) {
      f_inv.resize(n + 1);
      f_inv[n] = inv(fact(n).v);
      for (int i = n; i > prev; --i) {
        f_inv[i - 1] = f_inv[i] * i;
      }
    }
    return f_inv[n];
  }
  static MInt nCk(const int n, const int k) {
    if (n < 0 || n < k || k < 0) return 0;
    return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :
                                  fact_inv(n - k) * fact_inv(k));
  }
  static MInt nPk(const int n, const int k) {
    return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);
  }
  static MInt nHk(const int n, const int k) {
    return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));
  }
  static MInt large_nCk(long long n, const int k) {
    if (n < 0 || n < k || k < 0) return 0;
    inv(k, true);
    MInt res = 1;
    for (int i = 1; i <= k; ++i) {
      res *= inv(i) * n--;
    }
    return res;
  }
  MInt pow(long long exponent) const {
    MInt res = 1, tmp = *this;
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }
  MInt& operator+=(const MInt& x) {
    if ((v += x.v) >= M) v -= M;
    return *this;
  }
  MInt& operator-=(const MInt& x) {
    if ((v += M - x.v) >= M) v -= M;
    return *this;
  }
  MInt& operator*=(const MInt& x) {
    v = static_cast<unsigned long long>(v) * x.v % M;
    return *this;
  }
  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }
  bool operator==(const MInt& x) const { return v == x.v; }
  bool operator!=(const MInt& x) const { return v != x.v; }
  bool operator<(const MInt& x) const { return v < x.v; }
  bool operator<=(const MInt& x) const { return v <= x.v; }
  bool operator>(const MInt& x) const { return v > x.v; }
  bool operator>=(const MInt& x) const { return v >= x.v; }
  MInt& operator++() {
    if (++v == M) v = 0;
    return *this;
  }
  MInt operator++(int) {
    const MInt res = *this;
    ++*this;
    return res;
  }
  MInt& operator--() {
    v = (v == 0 ? M - 1 : v - 1);
    return *this;
  }
  MInt operator--(int) {
    const MInt res = *this;
    --*this;
    return res;
  }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(v ? M - v : 0); }
  MInt operator+(const MInt& x) const { return MInt(*this) += x; }
  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }
  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {
    return os << x.v;
  }
  friend std::istream& operator>>(std::istream& is, MInt& x) {
    long long v;
    is >> v;
    x = MInt(v);
    return is;
  }
};
using ModInt = MInt<MOD>;

template <int T>
struct NumberTheoreticTransform {
  using ModInt = MInt<T>;

  NumberTheoreticTransform() {
    for (int i = 0; i < 23; ++i) {
      if (primes[i][0] == ModInt::get_mod()) {
        n_max = 1 << primes[i][2];
        root = ModInt(primes[i][1]).pow((primes[i][0] - 1) >> primes[i][2]);
        return;
      }
    }
    assert(false);
  }

  template <typename U>
  std::vector<ModInt> dft(const std::vector<U>& a) {
    const int n = a.size();
    int lg = 1;
    while ((1 << lg) < n) ++lg;
    std::vector<ModInt> b(1 << lg, 0);
    std::copy(a.begin(), a.end(), b.begin());
    calc(&b);
    return b;
  }

  void idft(std::vector<ModInt>* a) {
    const int n = a->size();
    assert(__builtin_popcount(n) == 1);
    calc(a);
    std::reverse(std::next(a->begin()), a->end());
    const ModInt inv_n = ModInt::inv(n);
    for (int i = 0; i < n; ++i) {
      (*a)[i] *= inv_n;
    }
  }

  template <typename U>
  std::vector<ModInt> convolution(const std::vector<U>& a,
                                  const std::vector<U>& b) {
    const int a_size = a.size(), b_size = b.size();
    const int c_size = a_size + b_size - 1;
    int lg = 1;
    while ((1 << lg) < c_size) ++lg;
    const int n = 1 << lg;
    std::vector<ModInt> c(n, 0), d(n, 0);
    std::copy(a.begin(), a.end(), c.begin());
    calc(&c);
    std::copy(b.begin(), b.end(), d.begin());
    calc(&d);
    for (int i = 0; i < n; ++i) {
      c[i] *= d[i];
    }
    idft(&c);
    c.resize(c_size);
    return c;
  }

 private:
  const int primes[23][3]{
    {16957441, 329, 14},
    {17006593, 26, 15},
    {19529729, 770, 17},
    {167772161, 3, 25},
    {469762049, 3, 26},
    {645922817, 3, 23},
    {897581057, 3, 23},
    {924844033, 5, 21},
    {935329793, 3, 22},
    {943718401, 7, 22},
    {950009857, 7, 21},
    {962592769, 7, 21},
    {975175681, 17, 21},
    {976224257, 3, 20},
    {985661441, 3, 22},
    {998244353, 3, 23},
    {1004535809, 3, 21},
    {1007681537, 3, 20},
    {1012924417, 5, 21},
    {1045430273, 3, 20},
    {1051721729, 6, 20},
    {1053818881, 7, 20},
    {1224736769, 3, 24}
  };

  int n_max;
  ModInt root;
  std::vector<int> butterfly{0};
  std::vector<std::vector<ModInt>> omega{{1}};

  void calc(std::vector<ModInt>* a) {
    const int n = a->size(), prev_n = butterfly.size();
    if (n > prev_n) {
      assert(n <= n_max);
      butterfly.resize(n);
      const int prev_lg = omega.size(), lg = __builtin_ctz(n);
      for (int i = 1; i < prev_n; ++i) {
        butterfly[i] <<= lg - prev_lg;
      }
      for (int i = prev_n; i < n; ++i) {
        butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
      }
      omega.resize(lg);
      for (int i = prev_lg; i < lg; ++i) {
        omega[i].resize(1 << i);
        const ModInt tmp = root.pow((ModInt::get_mod() - 1) >> (i + 1));
        for (int j = 0; j < (1 << (i - 1)); ++j) {
          omega[i][j << 1] = omega[i - 1][j];
          omega[i][(j << 1) + 1] = omega[i - 1][j] * tmp;
        }
      }
    }
    const int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
    for (int i = 0; i < n; ++i) {
      const int j = butterfly[i] >> shift;
      if (i < j) std::swap((*a)[i], (*a)[j]);
    }
    for (int block = 1, den = 0; block < n; block <<= 1, ++den) {
      for (int i = 0; i < n; i += (block << 1)) {
        for (int j = 0; j < block; ++j) {
          const ModInt tmp = (*a)[i + j + block] * omega[den][j];
          (*a)[i + j + block] = (*a)[i + j] - tmp;
          (*a)[i + j] += tmp;
        }
      }
    }
  }
};

int main() {
  NumberTheoreticTransform<MOD> ntt;
  int n, k, f; cin >> n >> k >> f;
  vector<ModInt> dp(f + 2, 0);
  REP(c_s, k + 1) ++dp[min(c_s, f + 1)];
  FOR(l, 2, n + 1) {
    vector<ModInt> c = ntt.convolution(dp, dp), nxt((f + 1) * 2 + 1, 0);
    REP(i, (f + 1) * 2 + 1) nxt[i] = c[i] * max(k - i, 0);
    for (int i = (f + 1) * 2; i > 0; --i) c[i - 1] += c[i];
    for (int c_s = 0; c_s <= k && c_s <= (f + 1) * 2; ++c_s) nxt[c_s] += c[c_s];
    nxt[f + 1] = accumulate(nxt.begin() + (f + 1), nxt.end(), ModInt(0));
    nxt.resize(f + 2);
    dp.swap(nxt);
  }
  ModInt ans = 0;
  REP(i, f + 1) ans += dp[i] * dp[f - i];
  cout << ans << '\n';
  return 0;
}