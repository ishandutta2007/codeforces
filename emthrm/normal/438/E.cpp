#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(ll x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(ll exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &x) { if((val += x.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &x) { if((val += mod - x.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &x) { val = static_cast<unsigned long long>(val) * x.val % mod; return *this; }
  ModInt &operator/=(const ModInt &x) {
    // assert(__gcd(static_cast<int>(x.val), mod) == 1);
    unsigned a = x.val, b = mod; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      swap(a -= tmp * b, b);
      swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator<=(const ModInt &x) const { return val <= x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return val >= x.val; }
  ModInt &operator++() { if (++val == mod) val = 0; return *this; }
  ModInt operator++(int) { ModInt res = *this; ++*this; return res; }
  ModInt &operator--() { val = (val == 0 ? mod : val) - 1; return *this; }
  ModInt operator--(int) { ModInt res = *this; --*this; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(val ? mod - val : 0); }
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) { return os << x.val; }
  friend istream &operator>>(istream &is, ModInt &x) { ll val; is >> val; x = ModInt(val); return is; }
};
ModInt abs(const ModInt &x) { return x; }
struct Combinatorics {
  int val; // "val!" and "mod" must be disjoint.
  vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    FOR(i, 1, val + 1) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
};

template <typename T>
function<vector<T>(const vector<T>&, const vector<T>&)> mul = [](const vector<T> &a, const vector<T> &b) {
  int n = a.size(), m = b.size();
  vector<T> res(n + m - 1, T(0));
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

  FPS(int deg = 0) : co(deg + 1, T(0)) {}
  FPS(const vector<T> &co) : co(co) {}
  FPS(initializer_list<T> init) : co(init.begin(), init.end()) {}
  template <typename InputIter> FPS(InputIter first, InputIter last) : co(first, last) {}

  inline const T &operator[](int term) const { return co[term]; }
  inline T &operator[](int term) { return co[term]; }

  void resize(int deg) {
    int prev = co.size();
    co.resize(deg + 1);
    if (prev < deg + 1) fill(co.begin() + prev, co.end(), T(0));
  }

  void shrink() { while (co.size() > 1 && co.back() == T(0)) co.pop_back(); }

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
    assert(x != T(0));
    T inv_x = T(1) / x;
    for (T &e : co) e *= inv_x;
    return *this;
  }

  FPS &operator/=(const FPS &x) {
    if (x.co.size() > co.size()) return *this = FPS();
    int n = co.size() - x.co.size() + 1;
    FPS a(co.rbegin(), co.rbegin() + n), b(x.co.rbegin(), x.co.rbegin() + min(static_cast<int>(x.co.size()), n));
    b = b.inv(n - 1);
    a *= b;
    return *this = FPS(a.co.rend() - n, a.co.rend());
  }

  FPS &operator%=(const FPS &x) {
    *this -= *this / x * x;
    co.resize(static_cast<int>(x.co.size()) - 1);
    if (co.empty()) co = {T(0)};
    return *this;
  }

  FPS &operator<<=(int n) {
    co.insert(co.begin(), n, T(0));
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
    for (T &e : res.co) e = T(-e);
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
    T res = T(0);
    for (int i = static_cast<int>(co.size()) - 1; i >= 0; --i) (res *= val) += co[i];
    return res;
  }

  FPS differential() const {
    int n = co.size();
    assert(n >= 1);
    FPS res(n - 1);
    FOR(i, 1, n) res.co[i - 1] = co[i] * T(i);
    return res;
  }

  FPS integral() const {
    int n = co.size();
    FPS res(n + 1);
    REP(i, n) res[i + 1] = co[i] / T(i + 1);
    return res;
  }

  FPS exp(int deg = -1) const {
    assert(co[0] == T(0));
    if (deg == -1) deg = static_cast<int>(co.size()) - 1;
    FPS one({T(1)}), res = one;
    for (int i = 1; i <= deg; i <<= 1) {
      res *= FPS(co.begin(), co.begin() + min(static_cast<int>(co.size()), i << 1)) - res.log((i << 1) - 1) + one;
      res.co.resize(i << 1);
    }
    res.co.resize(deg + 1);
    return res;
  }

  FPS inv(int deg = -1) const {
    assert(co[0] != T(0));
    if (deg == -1) deg = static_cast<int>(co.size()) - 1;
    FPS res({T(1) / co[0]});
    for (int i = 1; i <= deg; i <<= 1) {
      res = res + res - res * res * FPS(co.begin(), co.begin() + min(static_cast<int>(co.size()), i << 1));
      res.co.resize(i << 1);
    }
    res.co.resize(deg + 1);
    return res;
  }

  FPS log(int deg = -1) const {
    assert(co[0] == T(1));
    if (deg == -1) deg = static_cast<int>(co.size()) - 1;
    FPS integrand = differential() * inv(deg - 1);
    integrand.co.resize(deg);
    return integrand.integral();
  }

  FPS pow(ll exponent, int deg = -1) const {
    int n = co.size();
    if (deg == -1) deg = n - 1;
    REP(i, n) {
      if (co[i] != T(0)) {
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
      if (multiplicand.co.empty()) multiplicand.co = {T(0)};
    };
    FPS res({T(1)}), base = *this;
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
    if (co[0] == T(0)) {
      FOR(i, 1, n) {
        if (co[i] == T(0)) continue;
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
    FPS res({s});
    T half = T(1) / T(2);
    for (int i = 1; i <= deg; i <<= 1) {
      (res += FPS(co.begin(), co.begin() + min(static_cast<int>(co.size()), i << 1)) * res.inv((i << 1) - 1)) *= half;
    }
    res.resize(deg);
    return res;
  }

  FPS translate(T c) const {
    int n = co.size();
    vector<T> fact(n, T(1)), inv_fact(n, T(1));
    FOR(i, 1, n) fact[i] = fact[i - 1] * T(i);
    inv_fact[n - 1] = T(1) / fact[n - 1];
    for (int i = n - 1; i > 0; --i) inv_fact[i - 1] = inv_fact[i] * T(i);
    vector<T> g(n), ex(n);
    REP(i, n) g[n - 1 - i] = co[i] * fact[i];
    T pow_c = T(1);
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

struct NTT {
  NTT(int mod_) {
    for (int i = 0; ; ++i) {
      assert(i < 23);
      if (primes[i][0] == mod_) {
        mod = mod_;
        n_max = 1 << primes[i][2];
        root = ModInt(primes[i][1]).pow((mod - 1) >> primes[i][2]);
        break;
      }
    }
  }

  void sub_dft(vector<ModInt> &a) {
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
        ModInt tmp = a[i + j + block] * omega[den][j];
        a[i + j + block] = a[i + j] - tmp;
        a[i + j] += tmp;
      }
    }
  }

  template <typename T>
  vector<ModInt> dft(const vector<T> &a) {
    int n = a.size(), lg = 1;
    while ((1 << lg) < n) ++lg;
    vector<ModInt> A(1 << lg, 0);
    REP(i, n) A[i] = a[i];
    sub_dft(A);
    return A;
  }

  void idft(vector<ModInt> &a) {
    int n = a.size();
    // assert(__builtin_popcount(n) == 1);
    sub_dft(a);
    reverse(a.begin() + 1, a.end());
    ModInt inv_n = ModInt(1) / n;
    REP(i, n) a[i] *= inv_n;
  }

  template <typename T>
  vector<ModInt> convolution(const vector<T> &a, const vector<T> &b) {
    int a_sz = a.size(), b_sz = b.size(), sz = a_sz + b_sz - 1, lg = 1;
    while ((1 << lg) < sz) ++lg;
    int n = 1 << lg;
    vector<ModInt> A(n, 0), B(n, 0);
    REP(i, a_sz) A[i] = a[i];
    REP(i, b_sz) B[i] = b[i];
    sub_dft(A);
    sub_dft(B);
    REP(i, n) A[i] *= B[i];
    idft(A);
    A.resize(sz);
    return A;
  }

private:
  const int primes[23][3] = {
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
  vector<int> butterfly{0};
  vector<vector<ModInt> > omega{{1}};

  void calc(int n) {
    int prev_n = butterfly.size();
    if (n <= prev_n) return;
    // assert(n <= n_max);
    butterfly.resize(n);
    int prev_lg = omega.size(), lg = __builtin_ctz(n);
    FOR(i, 1, prev_n) butterfly[i] <<= lg - prev_lg;
    FOR(i, prev_n, n) butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    omega.resize(lg);
    FOR(i, prev_lg, lg) {
      omega[i].resize(1 << i);
      ModInt tmp = root.pow((mod - 1) / (1 << (i + 1)));
      REP(j, 1 << (i - 1)) {
        omega[i][j << 1] = omega[i - 1][j];
        omega[i][(j << 1) + 1] = omega[i - 1][j] * tmp;
      }
    }
  }
};

ll mod_pow(ll base, ll exponent, int md = MOD) {
  base %= md;
  ll res = 1;
  while (exponent > 0) {
    if (exponent & 1) (res *= base) %= md;
    (base *= base) %= md;
    exponent >>= 1;
  }
  return res;
}

struct Xor128 {
  int rand() {
    unsigned t = x ^ (x << 11);
    x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return static_cast<int>(w);
  }
  int rand(int ub) {
    int res = rand() % ub;
    return (res < 0 ? res + ub : res);
  }
  int rand(int lb, int ub) { return lb + rand(ub - lb); }
  ll randll() {
    unsigned long long res = static_cast<unsigned long long>(rand()) << 32;
    return static_cast<ll>(res | rand());
  }
  ll randll(ll ub) {
    ll res = randll() % ub;
    return (res < 0 ? res + ub : res);
  }
  ll randll(ll lb, ll ub) { return lb + rand(ub - lb); }
private:
  unsigned x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned>(time(nullptr));
} xor128;

ll mod_sqrt(ll a, int p) {
  if ((a %= p) < 0) a += p;
  if (a == 0) return 0;
  if (p == 2) return 1;
  int half_p = (p - 1) >> 1;
  if (mod_pow(a, half_p, p) == p - 1) return -1;
  if (p % 4 == 3) return mod_pow(a, (p + 1) >> 2, p);
  int s = 1, q = half_p;
  for (; !(q & 1); q >>= 1, ++s);
  ll z;
  do {
    z = xor128.rand(2, p);
  } while (mod_pow(z, half_p, p) == 1);
  int m = s;
  ll c = mod_pow(z, q, p), r = mod_pow(a, (q - 1) >> 1, p), t = a * r % p * r % p;
  (r *= a) %= p;
  while (t != 1) {
    ll t2 = t * t % p;
    FOR(i, 1, m) {
      if (t2 == 1) {
        ll b = mod_pow(c, 1 << (m - i - 1), p);
        m = i;
        (r *= b) %= p;
        c = b * b % p;
        (t *= c) %= p;
        break;
      }
      (t2 *= t2) %= p;
    }
  }
  return r;
}

int main() {
  NTT ntt(998244353);
  mul<ModInt> = [&](const vector<ModInt> &a, const vector<ModInt> &b) {
    return ntt.convolution(a, b);
  };
  sqr<ModInt> = [&](const ModInt &a, ModInt &res) {
    ll ans = mod_sqrt(a.val, mod);
    if (ans == -1) {
      return false;
    } else {
      res = ans;
      return true;
    }
  };
  const int X = 100000;
  int n, m; cin >> n >> m;
  FPS<ModInt> c(X);
  REP(i, n) {
    int ci; cin >> ci;
    c[ci] = 1;
  }
  c *= ModInt(-4);
  c[0] += 1;
  c = c.sqrt(X);
  c[0] += 1;
  (c = c.inv(X)) *= ModInt(2);
  FOR(i, 1, m + 1) cout << c[i] << '\n';
  return 0;
}