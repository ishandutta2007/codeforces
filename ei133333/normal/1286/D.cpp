#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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

inline unsigned mul(unsigned a, unsigned b) {
  unsigned long long x = (unsigned long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
  return m;
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
    x = mul(x, p.x);
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

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

template< typename T >
struct fraction {
  T num, dom;

  fraction() {}

  fraction(T n, T d) : num(n), dom(d) {
    assert(dom != 0);
    if(dom < 0) num *= -1, dom *= -1;
    T tmp = __gcd(abs(num), abs(dom));
    num /= tmp;
    dom /= tmp;
  }

  fraction operator+(const fraction a) const {
    return fraction(num * a.dom + a.num * dom, dom * a.dom);
  }

  fraction operator-(const fraction a) const {
    return fraction(num * a.dom - a.num * dom, dom * a.dom);
  }

  fraction operator*(const fraction a) const {
    return fraction(num * a.num, dom * a.dom);
  }

  fraction operator/(const fraction a) {
    return fraction(num * a.dom, dom * a.num);
  }

  fraction operator*(T k) const { return fraction(num * k, dom); }

  fraction operator/(T k) const { return fraction(num, dom * k); }

  bool operator<(const fraction a) const {
    return num * a.dom < a.num * dom;
  }

  bool operator>(const fraction a) const {
    return num * a.dom > a.num * dom;
  }

  bool operator==(const fraction a) const {
    return num * a.dom == a.num * dom;
  }

  bool operator!=(const fraction a) const {
    return num * a.dom != a.num * dom;
  }

  bool operator<=(const fraction a) const {
    return num * a.dom <= a.num * dom;
  }

  bool operator>=(const fraction a) const {
    return num * a.dom >= a.num * dom;
  }
};

template< typename Monoid, typename F >
struct SegmentTree {

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }


  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

template< class T >
struct Matrix {
  array< array< T, 4 >, 4 > A;

  Matrix() {}

  Matrix(size_t n) : A{} {};

  size_t height() const {
    return (A.size());
  }

  size_t width() const {
    return (A[0].size());
  }

  inline const array< T, 4 > &operator[](int k) const {
    return (A[k]);
  }

  inline array< T, 4 > &operator[](int k) {
    return (A[k]);
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
    array< array< T, 4 >, 4 > C{};
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        for(int k = 0; k < p; k++)
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
    swap(C, A);
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
  int N;
  cin >> N;
  vector< int > X(N), V(N);
  vector< modint > P(N), Q(N);
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> V[i] >> P[i];
    P[i] /= 100;
    Q[i] = modint(1) - P[i];
  }

  struct Node {
    int right, type;
  };
  using F = fraction< int64 >;
  map< F, vector< Node > > ev;
  for(int i = 1; i < N; i++) {
    // <--- <-----
    if(V[i - 1] < V[i]) {
      // X[i]-V[i]*t = X[i-1]-V[i-1]*t
      // V[i-1]*t-V[i]*t = X[i-1]-X[i]
      // t = (X[i - 1] - X[i]) / (V[i - 1] - V[i])
      ev[F(X[i - 1] - X[i], V[i - 1] - V[i])].emplace_back((Node) {i, 0});
    }

    // ---> <---
    // X[i]-V[i]*t = X[i-1]+V[i-1]*t
    //           t = (X[i] - X[i - 1]) / (V[i - 1] + V[i])
    ev[F(X[i] - X[i - 1], V[i - 1] + V[i])].emplace_back((Node) {i, 2});


    // ------> --->
    if(V[i - 1] > V[i]) {
      // X[i]+V[i]*t = X[i-1]+V[i-1]*t
      // V[i]*t-V[i-1]*t = X[i-1]-X[i]
      // t = (X[i - 1] - X[i]) / (V[i] - V[i - 1])
      ev[F(X[i - 1] - X[i], V[i] - V[i - 1])].emplace_back((Node) {i, 1});
    }
  }


  // mat[0..1][0..1] ->
  // mat[2..3][2..3] 
  // mat[0..1][2..3] used

  using Mat = Matrix< modint >;
  Mat e = Mat::I(4);
  auto f = [](const Mat &a, const Mat &b) { return a * b; };

  SegmentTree< Mat, decltype(f) > seg(N, f, e);
  for(int i = 0; i < N; i++) {
    Mat u{e};
    u[0][0] = Q[i];
    u[1][0] = Q[i];
    u[2][2] = Q[i];
    u[3][2] = Q[i];
    u[0][1] = P[i];
    u[1][1] = P[i];
    u[2][3] = P[i];
    u[3][3] = P[i];
    seg.set(i, u);
  }
  seg.build();


  modint ret = 0;


  for(auto &p : ev) {
    auto &vs = p.second;
    for(auto &tt : vs) {
      Mat now = seg[tt.right];
      if(tt.type == 0) { // <<
        now[0][0] = 0;
        now[0][2] = Q[tt.right];
      } else if(tt.type == 1) { // >>
        now[1][1] = 0;
        now[1][3] = P[tt.right];
      } else { // ><
        now[1][0] = 0;
        now[1][2] = Q[tt.right];
      }
      seg.update(tt.right, now);
    }
    auto uku = seg.seg[1];
    modint sum = uku[0][2] + uku[0][3];
    ret += modint(p.first.num) / p.first.dom * sum;
    for(auto &tt : vs) {
      Mat now = seg[tt.right];
      if(tt.type == 0) { // <<
        now[0][2] = 0;
        now[2][2] = 0;
      } else if(tt.type == 1) { // >>
        now[1][3] = 0;
        now[3][3] = 0;
      } else { // ><
        now[1][2] = 0;
        now[3][2] = 0;
      }
      seg.update(tt.right, now);
    }

  }
  cout << ret << endl;
}