#include <bits/stdc++.h>
 
using namespace std;
 
using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;
 
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
 
static constexpr uint32_t mul_inv(uint32_t n, int e = 5, uint32_t x = 1) {
  return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));
}
 
template< uint32_t mod, bool fast = false >
struct ModInt2 {
  using u32 = uint32_t;
  using u64 = uint64_t;
 
  static constexpr u32 inv = mul_inv(mod);
  static constexpr u32 r2 = -uint64_t(mod) % mod;
 
  uint32_t x;
 
  ModInt2() : x(0) {}
 
  ModInt2(const int64_t &y)
      : x(reduce(u64(fast ? y : (y >= 0 ? y % mod : (mod - (-y) % mod) % mod)) * r2)) {}
 
  u32 reduce(const u64 &w) const {
    return u32(w >> 32) + mod - u32((u64(u32(w) * inv) * mod) >> 32);
  }
 
  ModInt2 &operator+=(const ModInt2 &p) {
    if(int(x += p.x - 2 * mod) < 0) x += 2 * mod;
    return *this;
  }
 
  ModInt2 &operator-=(const ModInt2 &p) {
    if(int(x -= p.x) < 0) x += 2 * mod;
    return *this;
  }
 
  ModInt2 &operator*=(const ModInt2 &p) {
    x = reduce(uint64_t(x) * p.x);
    return *this;
  }
 
  ModInt2 &operator/=(const ModInt2 &p) {
    *this *= p.inverse();
    return *this;
  }
 
  ModInt2 operator-() const { return ModInt2() - *this; }
 
  ModInt2 operator+(const ModInt2 &p) const { return ModInt2(*this) += p; }
 
  ModInt2 operator-(const ModInt2 &p) const { return ModInt2(*this) -= p; }
 
  ModInt2 operator*(const ModInt2 &p) const { return ModInt2(*this) *= p; }
 
  ModInt2 operator/(const ModInt2 &p) const { return ModInt2(*this) /= p; }
 
  bool operator==(const ModInt2 &p) const { return get() == p.get(); }
 
  bool operator!=(const ModInt2 &p) const { return get() != p.get(); }
 
  int get() const { return reduce(x) % mod; }
 
  ModInt2 pow(int64_t n) const {
    ModInt2 ret(1), mul(*this);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
 
  ModInt2 inverse() const {
    return pow(mod - 2);
  }
 
  friend ostream &operator<<(ostream &os, const ModInt2 &p) {
    return os << p.get();
  }
 
  friend istream &operator>>(istream &is, ModInt2 &a) {
    int64_t t;
    is >> t;
    a = ModInt2< mod, fast >(t);
    return (is);
  }
 
  static int get_mod() { return mod; }
};
 
using modint = ModInt2< mod, true >;
 
template< typename R, size_t N >
struct SquareMatrix {
  typedef array< R, N > arr;
  typedef array< arr, N > mat;
  mat dat;
 
  SquareMatrix() {
    for(size_t i = 0; i < N; i++)
      for(size_t j = 0; j < N; j++)
        dat[i][j] = 0;//R::add_identity();
  }
 
  bool operator==(const SquareMatrix &a) const {
    return dat == a.dat;
  }
 
  size_t size() const { return N; }
 
  arr &operator[](size_t k) { return dat[k]; }
 
  const arr &operator[](size_t k) const { return dat[k]; }
 
  static SquareMatrix add_identity() { return SquareMatrix(); }
 
  static SquareMatrix mul_identity() {
    SquareMatrix res;
    for(size_t i = 0; i < N; i++) res[i][i] = R::mul_identity();
    return res;
  }
 
  SquareMatrix operator*(const SquareMatrix &B) const {
    SquareMatrix res;
    for(size_t i = 0; i < N; i++)
      for(size_t j = 0; j < N; j++)
        for(size_t k = 0; k < N; k++)
          res[i][j] = res[i][j] + (dat[i][k] * B[k][j]);
    return res;
  }
 
  SquareMatrix operator+(const SquareMatrix &B) const {
    SquareMatrix res;
    for(size_t i = 0; i < N; i++)
      for(size_t j = 0; j < N; j++)
        res[i][j] = dat[i][j] + B[i][j];
    return res;
  }
 
  SquareMatrix pow(long long n) const {
    SquareMatrix a = *this, res = mul_identity();
    while(n) {
      if(n & 1) res = res * a;
      a = a * a;
      n >>= 1;
    }
    return res;
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
 
 
int main() {
  int N;
  cin >> N;
  vector< int > P(N), pre(N);
  cin >> P;
  vector< pair< int, int > > mx;
  int Q;
  cin >> Q;
  mx.reserve(N + Q);
  for(int i = 0; i < N; i++) mx.emplace_back(P[i], i);
  vector< int > A(Q), B(Q);
  for(int i = 0; i < Q; i++) {
    cin >> A[i] >> B[i];
    --A[i];
    mx.emplace_back(B[i], A[i]);
  }
  sort(begin(mx), end(mx));
  mx.erase(unique(begin(mx), end(mx)), end(mx));
  modint coef = modint(1) / modint(2).pow(N);
  using Mat = SquareMatrix< modint, 3 >;
  Mat e;
  e[0][0] = e[1][1] = e[2][2] = 1;
  auto f = [](const Mat &a, const Mat &b) { return a * b; };
  SegmentTree< Mat, decltype(f) > seg(mx.size(), f, e);
  Mat mat;
  mat[0][0] = mat[2][2] = 2;
  mat[1][1] = 1;
  for(int i = 0; i < N; i++) {
    pre[i] = lower_bound(begin(mx), end(mx), make_pair(P[i], i)) - begin(mx);
    mat[0][1] = P[i];
    mat[1][2] = P[i];
    seg.set(pre[i], mat);
  }
  seg.build();
  cout << (seg.seg[1][0][2] * coef).get() << "\n";
  for(int i = 0; i < Q; i++) {
    seg.update(pre[A[i]], e);
    pre[A[i]] = lower_bound(begin(mx), end(mx), make_pair(B[i], A[i])) - begin(mx);
    mat[0][1] = B[i];
    mat[1][2] = B[i];
    seg.update(pre[A[i]], mat);
    cout << (seg.seg[1][0][2] * coef).get() << "\n";
  }
}