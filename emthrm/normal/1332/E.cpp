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
const int MOD = 998244353;
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
struct Matrix {
  vector<vector<T>> dat;

  Matrix(int m, int n, T val = 0) : dat(m, vector<T>(n, val)) {}

  int height() const { return dat.size(); }

  int width() const { return dat.front().size(); }

  Matrix pow(ll exponent) {
    int n = height();
    Matrix<T> tmp = *this, res(n, n, 0);
    REP(i, n) res[i][i] = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }

  inline const vector<T> &operator[](const int idx) const { return dat[idx]; }
  inline vector<T> &operator[](const int idx) { return dat[idx]; }

  Matrix &operator=(const Matrix &x) {
    int m = x.height(), n = x.width();
    dat.resize(m, vector<T>(n));
    REP(i, m) REP(j, n) dat[i][j] = x[i][j];
    return *this;
  }

  Matrix &operator+=(const Matrix &x) {
    int m = height(), n = width();
    REP(i, m) REP(j, n) dat[i][j] += x[i][j];
    return *this;
  }

  Matrix &operator-=(const Matrix &x) {
    int m = height(), n = width();
    REP(i, m) REP(j, n) dat[i][j] -= x[i][j];
    return *this;
  }

  Matrix &operator*=(const Matrix &x) {
    int m = height(), n = x.width(), l = width();
    vector<vector<T>> res(m, vector<T>(n, 0));
    REP(i, m) REP(j, n) {
      REP(k, l) res[i][j] += dat[i][k] * x[k][j];
    }
    swap(dat, res);
    return *this;
  }

  Matrix operator+(const Matrix &x) const { return Matrix(*this) += x; }

  Matrix operator-(const Matrix &x) const { return Matrix(*this) -= x; }

  Matrix operator*(const Matrix &x) const { return Matrix(*this) *= x; }
};

int main() {
  int n, m, l, r; cin >> n >> m >> l >> r;
  ll grid = 1LL * n * m;
  if (grid & 1) {
    cout << ModInt(r - l + 1).pow(grid) << '\n';
  } else {
    int even = r / 2 - (l - 1) / 2, odd = (r - l + 1) - even;
    // cout << even << ' ' << odd << '\n';
    Matrix<ModInt> m(2, 2), dp(2, 1);
    m[0][0] = even; m[0][1] = odd;
    m[1][0] = odd;  m[1][1] = even;
    dp[0][0] = 1; dp[1][0] = 0;
    cout << (m.pow(grid) * dp)[0][0] << '\n';
  }
  return 0;
}