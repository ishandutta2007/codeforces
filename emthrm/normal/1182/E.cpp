#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define int long long

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(long long x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(long long exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &rhs) { if((val += rhs.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &rhs) { if((val += mod - rhs.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &rhs) { val = (unsigned long long)val * rhs.val % mod; return *this; }
  ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inv(); }
  bool operator==(const ModInt &rhs) const { return val == rhs.val; }
  bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
  bool operator<(const ModInt &rhs) const { return val < rhs.val; }
  bool operator<=(const ModInt &rhs) const { return val <= rhs.val; }
  bool operator>(const ModInt &rhs) const { return val > rhs.val; }
  bool operator>=(const ModInt &rhs) const { return val >= rhs.val; }
  ModInt operator-() const { return ModInt(-val); }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  friend ostream &operator<<(ostream &os, const ModInt &rhs) { return os << rhs.val; }
  friend istream &operator>>(istream &is, ModInt &rhs) { long long x; is >> x; rhs = ModInt(x); return is; }
private:
  ModInt inv() const {
    // if (__gcd((int)val, mod) != 1) assert(false);
    unsigned a = val, b = mod; int x = 1, y = 0;
    while (b) {
      unsigned tmp = a / b;
      a -= tmp * b; swap(a, b);
      x -= tmp * y; swap(x, y);
    }
    return ModInt(x);
  }
};
ModInt abs(const ModInt &x) { return x.val; }
struct Combinatorics {
  Combinatorics(int MAX = 5000000) {
    MAX <<= 1;
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = 1;
    FOR(i, 1, MAX + 1) fact[i] = fact[i - 1] * i;
    fact_inv[MAX] = ModInt(1) / fact[MAX];
    for (int i = MAX; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
private:
  vector<ModInt> fact, fact_inv;
};

template <typename T>
struct Matrix {
  Matrix(int m, int n, T val = 0) : dat(m, vector<T>(n, val)) {}

  int height() const { return dat.size(); }

  int width() const { return dat.front().size(); }

  Matrix pow(long long exponent) {
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

  Matrix &operator=(const Matrix &rhs) {
    int m = rhs.height(), n = rhs.width();
    dat.resize(m, vector<T>(n));
    REP(i, m) REP(j, n) dat[i][j] = rhs[i][j];
    return *this;
  }

  Matrix &operator+=(const Matrix &rhs) {
    int m = height(), n = width();
    REP(i, m) REP(j, n) dat[i][j] += rhs[i][j];
    return *this;
  }

  Matrix &operator-=(const Matrix &rhs) {
    int m = height(), n = width();
    REP(i, m) REP(j, n) dat[i][j] -= rhs[i][j];
    return *this;
  }

  Matrix &operator*=(const Matrix &rhs) {
    int m = height(), n = rhs.width(), l = width();
    vector<vector<T> > res(m, vector<T>(n, 0));
    REP(i, m) REP(j, n) {
      REP(k, l) res[i][j] += dat[i][k] * rhs[k][j];
    }
    swap(dat, res);
    return *this;
  }

  Matrix operator+(const Matrix &rhs) const { return Matrix(*this) += rhs; }

  Matrix operator-(const Matrix &rhs) const { return Matrix(*this) -= rhs; }

  Matrix operator*(const Matrix &rhs) const { return Matrix(*this) *= rhs; }

private:
  vector<vector<T> > dat;
};

long long mod_pow(long long base, long long exponent, long long mod = MOD) {
  base %= mod;
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    exponent >>= 1;
  }
  return res;
}

long long mod_inv(long long a, long long mod = MOD) {
  a %= mod;
  if (__gcd(a, mod) != 1) return -1;
  long long b = mod, x = 1, y = 0;
  while (b > 0) {
    long long tmp = a / b;
    a -= tmp * b;
    swap(a, b);
    x -= tmp * y;
    swap(x, y);
  }
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

vector<pair<long long, int> > prime_factorization(long long val) {
  vector<pair<long long, int> > res;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  --mod;
  long long n; cin >> n;
  vector<long long> f(3); REP(i, 3) cin >> f[i];
  long long ans = 1;
  int c; cin >> c;
  Matrix<ModInt> mat(3, 3, 0);
  mat[0][0] = mat[0][1] = mat[0][2] = mat[1][0] = mat[2][1] = 1;
  mat = mat.pow(n - 3);
  REP(i, 3) {
    Matrix<ModInt> vec(3, 1, 0);
    vec[2 - i][0] = 1;
    vec = mat * vec;
    (f[i] *= mod_pow(c, i + 1)) %= MOD;
    auto prime = prime_factorization(f[i]);
    for (auto p : prime) {
      ModInt ex = vec[0][0].val * p.second;
      // cout << p.first << ' ' << ex << '\n';
      (ans *= mod_pow(p.first, ex.val)) %= MOD;
    }
    // cout << '\n';
  }
  (ans *= mod_inv(mod_pow(c, n))) %= MOD;
  cout << ans << '\n';
  return 0;
}