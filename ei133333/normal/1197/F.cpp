#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
};

using modint = ModInt< mod >;


template< class T >
struct Matrix {
  vector< vector< T > > A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}

  Matrix(size_t n) : A(n, vector< T >(n, 0)) {};

  size_t height() const {
    return (A.size());
  }

  size_t width() const {
    return (A[0].size());
  }

  inline const vector< T > &operator[](int k) const {
    return (A.at(k));
  }

  inline vector< T > &operator[](int k) {
    return (A.at(k));
  }

  static Matrix I(size_t n) {
    Matrix mat(n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector< vector< T > > C(n, vector< T >(m, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        for(int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(height());
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const {
    return (Matrix(*this) += B);
  }

  Matrix operator-(const Matrix &B) const {
    return (Matrix(*this) -= B);
  }

  Matrix operator*(const Matrix &B) const {
    return (Matrix(*this) *= B);
  }

  Matrix operator^(const long long k) const {
    return (Matrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    size_t n = p.height(), m = p.width();
    for(int i = 0; i < n; i++) {
      os << "[";
      for(int j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }


  T determinant() {
    Matrix B(*this);
    assert(width() == height());
    T ret = 1;
    for(int i = 0; i < width(); i++) {
      int idx = -1;
      for(int j = i; j < width(); j++) {
        if(B[j][i] != 0) idx = j;
      }
      if(idx == -1) return (0);
      if(i != idx) {
        ret *= -1;
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T vv = B[i][i];
      for(int j = 0; j < width(); j++) {
        B[i][j] /= vv;
      }
      for(int j = i + 1; j < width(); j++) {
        T a = B[j][i];
        for(int k = 0; k < width(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return (ret);
  }
};

int main() {
  int N, M;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  cin >> M;
  vector< pair< int, int > > be[1000];
  for(int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    --x, --y, --c;
    be[x].emplace_back(y, c);
  }
  for(int i = 0; i < N; i++) {
    sort(be[i].begin(), be[i].end());
  }

  auto f = make_v< int >(3, 3);
  cin >> f;


  vector< modint > latte(4);
  latte[0] = 1;


  Matrix< modint > mat(64, 64);

  auto calc = [](int bit, int m) {
    if(m == 0) return bit & 3;
    if(m == 1) return (bit >> 2) & 3;
    if(m == 2) return (bit >> 4) & 3;
  };
  auto calc2 = [](int a, int b, int c) {
    return a | (b << 2) | (c << 4);
  };


  vector< int > tap(1 << 4);
  for(int i = 0; i < (1 << 4); i++) {
    for(int j = 0; j < 10; j++) {
      if((i >> j) & 1) continue;
      tap[i] = j;
      break;
    }
  }

  for(int k = 0; k < 3; k++) {
    for(int l = 0; l < 64; l++) {
      int p = 0;
      for(int m = 0; m < 3; m++) {
        if(f[k][m]) p |= 1 << calc(l, m);
      }
      mat[l][calc2(tap[p], calc(l, 0), calc(l, 1))] += 1;
    }
  }

  vector< Matrix< modint > > d2;
  for(int i = 0; i < 30; i++) {
    d2.emplace_back(mat);
    mat *= mat;
  }

  for(int i = 0; i < N; i++) {
    auto dp = make_v< modint >(64);
    dp[calc2(0, 3, 3)] = (be[i].size() && be[i][0].first == 0) ? 1 : 3;
    if(be[i].empty() || be[i].back().first + 1 != A[i]) {
      be[i].emplace_back(A[i] - 1, -1);
    }
    int cur = 0;
    for(auto &p : be[i]) {
      if(p.first == 0) continue;
      if((p.first - 1) - cur > 0) {
        int k = (p.first - 1) - cur;
        for(int pp = 29; pp >= 0; pp--) {
          if((k >> pp) & 1) {
            auto dp2 = make_v< modint >(64);
            for(int l = 0; l < dp.size(); l++) {
              if(dp[l].x) {
                for(int m = 0; m < dp.size(); m++) {
                  dp2[m] += dp[l] * d2[pp][l][m];
                }
              }
            }
            dp.swap(dp2);
          }
        }
      }
      cur = p.first;
      auto dp2 = make_v< modint >(64);
      for(int k = 0; k < 3; k++) {
        if(p.second == -1 || p.second == k) {
          for(int l = 0; l < dp.size(); l++) {
            int p = 0;
            for(int m = 0; m < 3; m++) {
              if(f[k][m]) p |= 1 << calc(l, m);
            }
            dp2[calc2(tap[p], calc(l, 0), calc(l, 1))] += dp[l];
          }
        }
      }
      dp.swap(dp2);
    }

    vector< modint > malta(4);
    for(int j = 0; j < dp.size(); j++) {
      for(int k = 0; k < 4; k++) {
        malta[(calc(j, 0)) ^ k] += latte[k] * dp[j];
      }
    }

    latte.swap(malta);

  }

  cout << latte[0] << endl;
}