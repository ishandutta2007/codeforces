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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <int M>
struct MInt {
  unsigned int val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % M : x % M + M) {}
  static constexpr int get_mod() { return M; }
  static void set_mod(int divisor) { assert(divisor == M); }
  static void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x); }
  static MInt inv(int x, bool init = false) {
    // assert(0 <= x && x < M && std::__gcd(x, M) == 1);
    static std::vector<MInt> inverse{0, 1};
    int prev = inverse.size();
    if (init && x >= prev) {
      // "x!" and "M" must be disjoint.
      inverse.resize(x + 1);
      for (int i = prev; i <= x; ++i) inverse[i] = -inverse[M % i] * (M / i);
    }
    if (x < inverse.size()) return inverse[x];
    unsigned int a = x, b = M; int u = 1, v = 0;
    while (b) {
      unsigned int q = a / b;
      std::swap(a -= q * b, b);
      std::swap(u -= q * v, v);
    }
    return u;
  }
  static MInt fact(int x) {
    static std::vector<MInt> f{1};
    int prev = f.size();
    if (x >= prev) {
      f.resize(x + 1);
      for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;
    }
    return f[x];
  }
  static MInt fact_inv(int x) {
    static std::vector<MInt> finv{1};
    int prev = finv.size();
    if (x >= prev) {
      finv.resize(x + 1);
      finv[x] = inv(fact(x).val);
      for (int i = x; i > prev; --i) finv[i - 1] = finv[i] * i;
    }
    return finv[x];
  }
  static MInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    if (n - k > k) k = n - k;
    return fact(n) * fact_inv(k) * fact_inv(n - k);
  }
  static MInt nPk(int n, int k) { return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k); }
  static MInt nHk(int n, int k) { return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }
  static MInt large_nCk(long long n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    inv(k, true);
    MInt res = 1;
    for (int i = 1; i <= k; ++i) res *= inv(i) * n--;
    return res;
  }
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= M) val -= M; return *this; }
  MInt &operator-=(const MInt &x) { if((val += M - x.val) >= M) val -= M; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % M; return *this; }
  MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == M) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? M : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? M - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int M> MInt<M> abs(const MInt<M> &x) { return x; } }
using ModInt = MInt<MOD>;

template <int T>
struct NumberTheoreticTransform {
  using ModInt = MInt<T>;

  NumberTheoreticTransform() {
    for (int i = 0; i < 23; ++i) {
      if (primes[i][0] == ModInt::get_mod()) {
        n_max = 1 << primes[i][2];
        root = ModInt(primes[i][1]).pow((ModInt::get_mod() - 1) >> primes[i][2]);
        return;
      }
    }
    assert(false);
  }

  template <typename U>
  std::vector<ModInt> dft(const std::vector<U> &a) {
    const int n = a.size();
    int lg = 1;
    while ((1 << lg) < n) ++lg;
    std::vector<ModInt> A(1 << lg, 0);
    for (int i = 0; i < n; ++i) A[i] = a[i];
    calc(A);
    return A;
  }

  void idft(std::vector<ModInt> &a) {
    const int n = a.size();
    assert(__builtin_popcount(n) == 1);
    calc(a);
    std::reverse(a.begin() + 1, a.end());
    ModInt inv_n = ModInt::inv(n);
    for (int i = 0; i < n; ++i) a[i] *= inv_n;
  }

  template <typename U>
  std::vector<ModInt> convolution(const std::vector<U> &a, const std::vector<U> &b) {
    const int a_size = a.size(), b_size = b.size(), c_size = a_size + b_size - 1;
    int lg = 1;
    while ((1 << lg) < c_size) ++lg;
    const int n = 1 << lg;
    std::vector<ModInt> A(n, 0), B(n, 0);
    for (int i = 0; i < a_size; ++i) A[i] = a[i];
    for (int i = 0; i < b_size; ++i) B[i] = b[i];
    calc(A);
    calc(B);
    for (int i = 0; i < n; ++i) A[i] *= B[i];
    idft(A);
    A.resize(c_size);
    return A;
  }

private:
  int primes[23][3]{
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

  void calc(std::vector<ModInt> &a) {
    const int n = a.size(), prev_n = butterfly.size();
    if (n > prev_n) {
      assert(n <= n_max);
      butterfly.resize(n);
      const int prev = omega.size(), lg = __builtin_ctz(n);
      for (int i = 1; i < prev_n; ++i) butterfly[i] <<= lg - prev;
      for (int i = prev_n; i < n; ++i) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
      omega.resize(lg);
      for (int i = prev; i < lg; ++i) {
        omega[i].resize(1 << i);
        ModInt tmp = root.pow((ModInt::get_mod() - 1) / (1 << (i + 1)));
        for (int j = 0; j < (1 << (i - 1)); ++j) {
          omega[i][j << 1] = omega[i - 1][j];
          omega[i][(j << 1) + 1] = omega[i - 1][j] * tmp;
        }
      }
    }
    const int shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);
    for (int i = 0; i < n; ++i) {
      const int j = butterfly[i] >> shift;
      if (i < j) std::swap(a[i], a[j]);
    }
    for (int block = 1, den = 0; block < n; block <<= 1, ++den) {
      for (int i = 0; i < n; i += (block << 1)) for (int j = 0; j < block; ++j) {
        ModInt tmp = a[i + j + block] * omega[den][j];
        a[i + j + block] = a[i + j] - tmp;
        a[i + j] += tmp;
      }
    }
  }
};

template <typename T>
struct FormalPowerSeries {
  std::vector<T> coef;

  explicit FormalPowerSeries(const int deg = 0) : coef(deg + 1, 0) {}
  explicit FormalPowerSeries(const std::vector<T>& coef) : coef(coef) {}
  FormalPowerSeries(std::initializer_list<T> init) : coef(init.begin(), init.end()) {}
  template <typename InputIter>
  explicit FormalPowerSeries(InputIter first, InputIter last) : coef(first, last) {}

  inline const T &operator[](const int term) const { return coef[term]; }
  inline T &operator[](const int term) { return coef[term]; }

  using MUL = std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>;
  using SQR = std::function<bool(const T&, T&)>;
  static void set_mul(const MUL mul) { get_mul() = mul; }
  static void set_sqr(const SQR sqr) { get_sqr() = sqr; }

  void resize(const int deg) { coef.resize(deg + 1, 0); }
  void shrink() {
    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();
  }
  int degree() const { return static_cast<int>(coef.size()) - 1; }

  FormalPowerSeries& operator=(const std::vector<T>& coef_) {
    coef = coef_;
    return *this;
  }
  FormalPowerSeries& operator=(const FormalPowerSeries& x) = default;

  FormalPowerSeries& operator+=(const FormalPowerSeries& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) resize(deg_x);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] += x[i];
    }
    return *this;
  }
  FormalPowerSeries& operator-=(const FormalPowerSeries& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) resize(deg_x);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] -= x[i];
    }
    return *this;
  }
  FormalPowerSeries& operator*=(const T x) {
    for (T& e : coef) e *= x;
    return *this;
  }
  FormalPowerSeries& operator*=(const FormalPowerSeries& x) {
    return *this = get_mul()(coef, x.coef);
  }
  FormalPowerSeries& operator/=(const T x) {
    assert(x != 0);
    const T inv_x = static_cast<T>(1) / x;
    for (T& e : coef) e *= inv_x;
    return *this;
  }
  FormalPowerSeries& operator/=(const FormalPowerSeries& x) {
    const int x_size = x.coef.size();
    if (x_size > coef.size()) return *this = FormalPowerSeries();
    const int n = coef.size() - x_size + 1;
    FormalPowerSeries tmp = FormalPowerSeries(x.coef.rbegin(), x.coef.rbegin() + std::min(x_size, n)).inv(n - 1);
    tmp = FormalPowerSeries(coef.rbegin(), coef.rbegin() + n) * tmp;
    return *this = FormalPowerSeries(tmp.coef.rend() - n, tmp.coef.rend());
  }
  FormalPowerSeries& operator%=(const FormalPowerSeries& x) {
    if (x.degree() == 0) return *this = FormalPowerSeries{0};
    *this -= *this / x * x;
    resize(x.degree() - 1);
    return *this;
  }
  FormalPowerSeries& operator<<=(const int n) {
    coef.insert(coef.begin(), n, 0);
    return *this;
  }
  FormalPowerSeries& operator>>=(const int n) {
    if (degree() < n) return *this = FormalPowerSeries();
    coef.erase(coef.begin(), coef.begin() + n);
    return *this;
  }

  bool operator==(const FormalPowerSeries& x) const {
    FormalPowerSeries a(*this), b(x);
    a.shrink();
    b.shrink();
    const int deg = a.degree();
    if (deg != b.degree()) return false;
    for (int i = 0; i <= deg; ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
  bool operator!=(const FormalPowerSeries& x) const { return !(*this == x); }

  FormalPowerSeries operator+() const { return *this; }
  FormalPowerSeries operator-() const {
    FormalPowerSeries res(*this);
    for (T& e : res.coef) e = -e;
    return res;
  }

  FormalPowerSeries operator+(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) += x; }
  FormalPowerSeries operator-(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) -= x; }
  FormalPowerSeries operator*(const T x) const { return FormalPowerSeries(*this) *= x; }
  FormalPowerSeries operator*(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) *= x; }
  FormalPowerSeries operator/(const T x) const { return FormalPowerSeries(*this) /= x; }
  FormalPowerSeries operator/(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) /= x; }
  FormalPowerSeries operator%(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) %= x; }
  FormalPowerSeries operator<<(const int n) const { return FormalPowerSeries(*this) <<= n; }
  FormalPowerSeries operator>>(const int n) const { return FormalPowerSeries(*this) >>= n; }

  T horner(const T x) const {
    T res = 0;
    for (int i = degree(); i >= 0; --i) {
      res = res * x + coef[i];
    }
    return res;
  }

  FormalPowerSeries differential() const {
    const int deg = degree();
    assert(deg >= 0);
    FormalPowerSeries res(std::max(deg - 1, 0));
    for (int i = 1; i <= deg; ++i) {
      res[i - 1] = coef[i] * i;
    }
    return res;
  }

  FormalPowerSeries exp(int deg = -1) const {
    assert(coef[0] == 0);
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    const FormalPowerSeries one{1};
    FormalPowerSeries res(one);
    for (int i = 1; i <= deg; i <<= 1) {
      res *= FormalPowerSeries(coef.begin(), coef.begin() + std::min(n, i << 1)) - res.log((i << 1) - 1) + one;
      res.coef.resize(i << 1);
    }
    res.resize(deg);
    return res;
  }

  FormalPowerSeries inv(int deg = -1) const {
    assert(coef[0] != 0);
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    FormalPowerSeries res{static_cast<T>(1) / coef[0]};
    for (int i = 1; i <= deg; i <<= 1) {
      res = res + res - res * res * FormalPowerSeries(coef.begin(), coef.begin() + std::min(n, i << 1));
      res.coef.resize(i << 1);
    }
    res.resize(deg);
    return res;
  }

  FormalPowerSeries log(int deg = -1) const {
    assert(coef[0] == 1);
    if (deg == -1) deg = degree();
    FormalPowerSeries integrand = differential() * inv(deg - 1);
    integrand.resize(deg);
    for (int i = deg; i > 0; --i) {
      integrand[i] = integrand[i - 1] / i;
    }
    integrand[0] = 0;
    return integrand;
  }

  FormalPowerSeries pow(long long exponent, int deg = -1) const {
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    for (int i = 0; i < n; ++i) {
      if (coef[i] == 0) continue;
      const long long shift = exponent * i;
      if (shift > deg) break;
      T tmp = 1, base = coef[i];
      for (long long e = exponent; e > 0; e >>= 1) {
        if (e & 1) tmp *= base;
        base *= base;
      }
      const FormalPowerSeries res = ((*this >> i) * (static_cast<T>(1) / coef[i])).log(deg - shift);
      return ((res * static_cast<T>(exponent)).exp(deg - shift) * tmp) << shift;
    }
    return FormalPowerSeries(deg);
  }

  FormalPowerSeries mod_pow(long long exponent, const FormalPowerSeries& md) const {
    const FormalPowerSeries inv_rev_md = FormalPowerSeries(md.coef.rbegin(), md.coef.rend()).inv();
    const int inv_rev_md_size = inv_rev_md.coef.size(), md_size = md.coef.size();
    auto mod_mul = [&md, &inv_rev_md, inv_rev_md_size, md_size](
        FormalPowerSeries& multiplicand,
        const FormalPowerSeries& multiplier) -> void {
      multiplicand *= multiplier;
      if (md_size <= multiplicand.coef.size()) {
        const int n = multiplicand.coef.size() - md_size + 1;
        const FormalPowerSeries quotient =
            FormalPowerSeries(multiplicand.coef.rbegin(), multiplicand.coef.rbegin() + n) *
            FormalPowerSeries(inv_rev_md.coef.begin(), inv_rev_md.coef.begin() + std::min(inv_rev_md_size, n));
        multiplicand -= FormalPowerSeries(quotient.coef.rend() - n, quotient.coef.rend()) * md;
      }
      multiplicand.coef.resize(md_size - 1);
      if (multiplicand.coef.empty()) multiplicand.coef = {0};
    };
    FormalPowerSeries res{1}, base = *this;
    mod_mul(base, res);
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) mod_mul(res, base);
      mod_mul(base, base);
    }
    return res;
  }

  FormalPowerSeries sqrt(int deg = -1) const {
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    if (coef[0] == 0) {
      for (int i = 1; i < n; ++i) {
        if (coef[i] == 0) continue;
        if (i & 1) return FormalPowerSeries(-1);
        const int shift = i >> 1;
        if (deg < shift) break;
        FormalPowerSeries res = (*this >> i).sqrt(deg - shift);
        if (res.coef.empty()) return FormalPowerSeries(-1);
        res <<= shift;
        res.resize(deg);
        return res;
      }
      return FormalPowerSeries(deg);
    }
    T s;
    if (!get_sqr()(coef[0], s)) return FormalPowerSeries(-1);
    FormalPowerSeries res{s};
    const T half = static_cast<T>(1) / 2;
    for (int i = 1; i <= deg; i <<= 1) {
      res += FormalPowerSeries(coef.begin(), coef.begin() + std::min(n, i << 1)) * res.inv((i << 1) - 1);
      res *= half;
    }
    res.resize(deg);
    return res;
  }

  FormalPowerSeries translate(T c) const {
    const int n = coef.size();
    std::vector<T> fact(n, 1), inv_fact(n, 1);
    for (int i = 1; i < n; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];
    for (int i = n - 1; i > 0; --i) {
      inv_fact[i - 1] = inv_fact[i] * i;
    }
    std::vector<T> g(n), ex(n);
    for (int i = 0; i < n; ++i) {
      g[n - 1 - i] = coef[i] * fact[i];
    }
    T pow_c = 1;
    for (int i = 0; i < n; ++i) {
      ex[i] = pow_c * inv_fact[i];
      pow_c *= c;
    }
    const std::vector<T> conv = get_mul()(g, ex);
    FormalPowerSeries res(n - 1);
    for (int i = 0; i < n; ++i) {
      res[i] = conv[n - 1 - i] * inv_fact[i];
    }
    return res;
  }

private:
  static MUL& get_mul() {
    static MUL mul = [](const std::vector<T>& a, const std::vector<T>& b) -> std::vector<T> {
      const int n = a.size(), m = b.size();
      std::vector<T> res(n + m - 1, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    };
    return mul;
  }
  static SQR& get_sqr() {
    static SQR sqr = [](const T& a, T& res) -> bool { return false; };
    return sqr;
  }
};

template <template <typename> class C, typename T>
struct MultipointEvaluation {
  std::vector<C<T>> node;
  std::vector<T> val;

  MultipointEvaluation(const std::vector<T> &xs) : n(xs.size()), val(xs.size()) {
    node.resize(n << 1);
    for (int i = 0; i < n; ++i) node[n + i] = C<T>{-xs[i], 1};
    for (int i = n - 1; i > 0; --i) node[i] = node[i << 1] * node[(i << 1) + 1];
  }

  void calc(const C<T> &f) { dfs(f, 1); }

private:
  int n;

  void dfs(C<T> poly, int pos) {
    poly %= node[pos];
    if (pos < n) {
      dfs(poly, pos << 1);
      dfs(poly, (pos << 1) + 1);
    } else {
      val[pos - n] = poly[0];
    }
  }
};

int main() {
  FormalPowerSeries<ModInt>::set_mul([](const vector<ModInt>& a, const vector<ModInt>& b) -> vector<ModInt> {
    static NumberTheoreticTransform<MOD> ntt;
    return ntt.convolution(a, b);
  });
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }

  // const auto f = [&](auto&& f, int par, int ver) -> vector<ModInt> {
  //   vector<vector<ModInt>> dp;
  //   for (int e : graph[ver]) {
  //     if (e != par) dp.emplace_back(f(f, ver, e));
  //   }
  //   const int child = dp.size();
  //   if (child == 0) return vector<ModInt>{0, 1};
  //   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  //   REP(i, child) que.emplace(dp[i].size(), i);
  //   while (que.size() > 1) {
  //     const int i = que.top().second; que.pop();
  //     const int j = que.top().second; que.pop();
  //     dp[i] = ntt.convolution(dp[i], dp[j]);
  //     dp[j].clear();
  //     que.emplace(dp[i].size(), i);
  //   }
  //   const int i = que.top().second;
  //   dp[i].emplace_back(0);
  //   for (int j = dp[i].size() - 1; j >= 0; --j) {
  //     dp[i][j] = dp[i][j] * child + (j > 0 ? dp[i][j - 1] : 0);
  //   }
  //   return dp[i];
  // };
  // const vector<ModInt> dp = f(f, -1, 0);

  vector<ModInt> a(n);
  a[0] = graph[0].size();
  FOR(i, 1, n) a[i] = graph[i].size() - 1;
  REP(i, n) a[i] = -a[i];
  const auto dp = MultipointEvaluation<FormalPowerSeries, ModInt>(a).node[1];
  ModInt ans = 0;
  FOR(i, 1, n + 1) ans += dp[i] * ModInt::fact(i) * ((n - i) & 1 ? -1 : 1);
  cout << ans << '\n';
  return 0;
}