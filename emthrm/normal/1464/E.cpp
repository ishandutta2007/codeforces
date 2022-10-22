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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <int MOD>
struct MInt {
  unsigned val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}
  static int get_mod() { return MOD; }
  static void set_mod(int divisor) { assert(divisor == MOD); }
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator-=(const MInt &x) { if((val += MOD - x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }
  MInt &operator/=(const MInt &x) {
    // assert(std::__gcd(static_cast<int>(x.val), MOD) == 1);
    unsigned a = x.val, b = MOD; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      std::swap(a -= tmp * b, b);
      std::swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == MOD) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? MOD : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? MOD - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x) { return x; } }
template <int MOD>
struct Combinatorics {
  using ModInt = MInt<MOD>;
  int val;  // "val!" and "mod" must be disjoint.
  std::vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : nCk(n + k - 1, k);
  }
};
using ModInt = MInt<MOD>;

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}

template <typename T>
struct Matrix {
  Matrix(int m, int n, T val = 0) : dat(m, std::vector<T>(n, val)) {}

  int height() const { return dat.size(); }

  int width() const { return dat.front().size(); }

  Matrix pow(long long exponent) const {
    int n = height();
    Matrix<T> tmp = *this, res(n, n, 0);
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }

  inline const std::vector<T> &operator[](const int idx) const { return dat[idx]; }
  inline std::vector<T> &operator[](const int idx) { return dat[idx]; }

  Matrix &operator=(const Matrix &x) {
    int m = x.height(), n = x.width();
    dat.resize(m, std::vector<T>(n));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] = x[i][j];
    return *this;
  }

  Matrix &operator+=(const Matrix &x) {
    int m = height(), n = width();
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] += x[i][j];
    return *this;
  }

  Matrix &operator-=(const Matrix &x) {
    int m = height(), n = width();
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] -= x[i][j];
    return *this;
  }

  Matrix &operator*=(const Matrix &x) {
    int m = height(), n = x.width(), l = width();
    std::vector<std::vector<T>> res(m, std::vector<T>(n, 0));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
      for (int k = 0; k < l; ++k) res[i][j] += dat[i][k] * x[k][j];
    }
    std::swap(dat, res);
    return *this;
  }

  Matrix operator+(const Matrix &x) const { return Matrix(*this) += x; }

  Matrix operator-(const Matrix &x) const { return Matrix(*this) -= x; }

  Matrix operator*(const Matrix &x) const { return Matrix(*this) *= x; }

private:
  std::vector<std::vector<T>> dat;
};

template <typename T>
int gauss_jordan(Matrix<T> &mat, const T EPS = 1e-8, bool is_extended = false) {
  int m = mat.height(), n = mat.width(), rank = 0;
  for (int col = 0; col < n; ++col) {
    if (is_extended && col == n - 1) break;
    int pivot = -1;
    T mx = EPS;
    for (int row = rank; row < m; ++row) {
      if (std::abs(mat[row][col]) > mx) {
        pivot = row;
        mx = std::abs(mat[row][col]);
      }
    }
    if (pivot == -1) continue;
    std::swap(mat[rank], mat[pivot]);
    T tmp = mat[rank][col];
    for (int col2 = 0; col2 < n; ++col2) mat[rank][col2] /= tmp;
    for (int row = 0; row < m; ++row) {
      if (row != rank && std::abs(mat[row][col]) > EPS) {
        tmp = mat[row][col];
        for (int col2 = 0; col2 < n; ++col2) mat[row][col2] -= mat[rank][col2] * tmp;
      }
    }
    ++rank;
  }
  return rank;
}

template <typename T, typename U = double>
std::vector<U> linear_equation(const Matrix<T> &a, const std::vector<T> &b, const U EPS = 1e-8) {
  int m = a.height(), n = a.width();
  Matrix<U> matrix(m, n + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) matrix[i][j] = a[i][j];
    matrix[i][n] = b[i];
  }
  int rank = gauss_jordan(matrix, EPS, true);
  std::vector<U> res;
  for (int row = rank; row < m; ++row) {
    if (std::abs(matrix[row][n]) > EPS) return res;
  }
  res.assign(n, 0);
  for (int i = 0; i < rank; ++i) res[i] = matrix[i][n];
  return res;
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
  }
  vector<int> ts = topological_sort(graph);
  vector<int> gru(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    int v = ts[i];
    set<int> st;
    for (int e : graph[v]) st.emplace(gru[e]);
    while (st.count(gru[v]) == 1) ++gru[v];
  }
  int x = *max_element(ALL(gru));
  if (x == 0) {
    cout << 0 << '\n';
    return 0;
  }
  if (__builtin_popcount(x) == 1) ++x;
  while (__builtin_popcount(x) > 1) ++x;
  vector<int> p(x, 0);
  REP(i, n) ++p[gru[i]];
  Matrix<ModInt> a(x, x);
  REP(i, x) {
    REP(j, x) a[i][j] = ModInt(p[i ^ j]) / (n + 1);
    a[i][i] -= 1;
  }
  vector<ModInt> y(x, 0);
  y[0] = ModInt(-1) / (n + 1);
  cout << ModInt(1) - linear_equation<ModInt, ModInt>(a, y, 0)[0] << '\n';
  return 0;
}