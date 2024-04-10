#include <algorithm>
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
    // if (__gcd(val, mod) != 1) assert(false);
    unsigned a = val, b = mod; int x = 1, y = 0;
    while (b) {
      unsigned tmp = a / b;
      a -= tmp * b; swap(a, b);
      x -= tmp * y; swap(x, y);
    }
    return ModInt(x);
  }
};
ModInt abs(const ModInt &rhs) { return rhs.val; }
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
  inline ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  inline ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    return fact[n] * fact_inv[n - k];
  }
  inline ModInt nHk(int n, int k) {
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

  T determinant() {
    int n = height();
    Matrix<T> mat = *this;
    T res = 1;
    REP(j, n) {
      int pivot = -1;
      T mx = EPS;
      FOR(i, j, n) {
        if (abs(mat[i][j]) > mx) {
          pivot = i;
          mx = abs(mat[i][j]);
        }
      }
      if (pivot == -1) return 0;
      if (pivot != j) {
        swap(mat[j], mat[pivot]);
        res *= -1;
      }
      res *= mat[j][j];
      FOR(k, j + 1, n) mat[j][k] /= mat[j][j];
      FOR(i, j + 1, n) FOR(k, j + 1, n) {
        mat[i][k] -= mat[i][j] * mat[j][k];
      }
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

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long n; int m; cin >> n >> m;
  if (n < m) {
    cout << 1 << '\n';
    return 0;
  }
  Matrix<ModInt> mat(m, m, 0);
  mat[0][0] = mat[0][m - 1] = 1;
  FOR(i, 1, m) mat[i][i - 1] = 1;
  mat = mat.pow(n - 1);
  ModInt ans = mat[m - 1][0];
  REP(j, m) ans += mat[m - 1][j];
  cout << ans << '\n';
  return 0;
}