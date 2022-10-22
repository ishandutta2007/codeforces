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
const int MOD = 998244353;
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

int main() {
  NTT ntt(MOD);
  int n, k; cin >> n >> k;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  int Q; cin >> Q;
  while (Q--) {
    int type, l, r; ll q, d; cin >> type >> q;
    if (type == 1) {
      int i; cin >> i >> d; --i;
      l = r = i;
      d -= a[i];
    } else {
      cin >> l >> r >> d; --l; --r;
    }
    vector<ll> b(n);
    REP(i, n) b[i] = q - a[i];
    FOR(i, l, r + 1) b[i] -= d;
    REP(i, n) {
      b[i] %= MOD;
      if (b[i] < 0) b[i] += MOD;
    }
    vector<vector<ModInt> > node(n << 1);
    REP(i, n) node[n + i] = {1, b[i]};
    for (int i = n - 1; i > 0; --i) {
      node[i] = ntt.convolution(node[i << 1], node[(i << 1) + 1]);
      if (node[i].size() > k + 1) node[i].resize(k + 1);
    }
    cout << node[1][k] << '\n';
  }
  return 0;
}