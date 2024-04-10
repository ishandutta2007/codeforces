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
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
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
using ModInt = MInt<3>;

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
  const int m = a.height(), n = a.width();
  Matrix<U> matrix(m, n + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[i][j] = a[i][j];
    }
    matrix[i][n] = b[i];
  }
  const int rank = gauss_jordan(matrix, EPS, true);
  for (int row = rank; row < m; ++row) {
    if (std::abs(matrix[row][n]) > EPS) return std::vector<U>();
  }
  std::vector<U> res(n, 0);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (std::abs(matrix[i][j]) <= EPS) {
      ++j;
    }
    res[j++] = matrix[i][n];
  }
  return res;
}

void solve() {
  int n, m; cin >> n >> m;
  vector graph(n, vector(n, -1));
  vector<int> c(m), known;
  REP(i, m) {
    int a, b; cin >> a >> b >> c[i]; --a; --b; --c[i];
    if (a > b) swap(a, b);
    graph[a][b] = i;
    if (c[i] != -2) known.emplace_back(i);
  }
  vector<tuple<int, int, int>> clique;
  REP(i, n) FOR(j, i + 1, n) FOR(k, j + 1, n) {
    if (graph[i][j] != -1 && graph[j][k] != -1 && graph[i][k] != -1) {
      clique.emplace_back(graph[i][j], graph[j][k], graph[i][k]);
    }
  }
  if (clique.empty()) {
    REP(i, m) {
      if (c[i] == -2) c[i] = 0;
      cout << c[i] + 1 << " \n"[i + 1 == m];
    }
    return;
  }
  Matrix<ModInt> a(clique.size() + known.size(), m);
  vector<ModInt> b(clique.size() + known.size(), 0);
  REP(i, clique.size()) {
    const auto [x, y, z] = clique[i];
    a[i][x] = a[i][y] = a[i][z] = 1;
  }
  REP(i, known.size()) {
    a[clique.size() + i][known[i]] = 1;
    b[clique.size() + i] = c[known[i]];
  }
  const vector<ModInt> ans = linear_equation(a, b, ModInt(0));
  if (ans.empty()) {
    cout << "-1\n";
  } else {
    REP(i, m) cout << ans[i].val + 1 << " \n"[i + 1 == m];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}