#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);
//const int mod = 998244353;

const int64 infll = (1LL << 60) - 1;
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

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      propagate(a);
      Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
      return -1;
    }
    thrust(a + sz);
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, reflect(a));
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
      if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
      return -1;
    }
    thrust(b + sz - 1);
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(reflect(--b), R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

/**
 * @brief Square-Matrix()
 */
template< class T, size_t N >
struct SquareMatrix {
  array< array< T, N >, N > A;

  SquareMatrix() = default;

  size_t size() { return N; }

  inline const array< T, N > &operator[](int k) const {
    return (A.at(k));
  }

  inline array< T, N > &operator[](int k) {
    return (A.at(k));
  }

  static SquareMatrix add_identity() {
    return SquareMatrix();
  }

  static SquareMatrix mul_identity() {
    SquareMatrix mat;
    for(size_t i = 0; i < N; i++) mat[i][i] = 1;
    return mat;
  }

  SquareMatrix &operator+=(const SquareMatrix &B) {
    for(size_t i = 0; i < N; i++) {
      for(size_t j = 0; j < N; j++) {
        (*this)[i][j] += B[i][j];
      }
    }
    return *this;
  }

  SquareMatrix &operator-=(const SquareMatrix &B) {
    for(size_t i = 0; i < N; i++) {
      for(size_t j = 0; j < N; j++) {
        (*this)[i][j] -= B[i][j];
      }
    }
    return *this;
  }

  SquareMatrix &operator*=(const SquareMatrix &B) {
    array< array< T, N >, N > C;
    for(size_t i = 0; i < N; i++) {
      for(size_t j = 0; j < N; j++) {
        for(size_t k = 0; k < N; k++) {
          C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
        }
      }
    }
    A.swap(C);
    return (*this);
  }

  SquareMatrix &operator^=(uint64_t k) {
    SquareMatrix B = SquareMatrix::mul_identity();
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return *this;
  }

  SquareMatrix operator+(const SquareMatrix &B) const {
    return SquareMatrix(*this) += B;
  }

  SquareMatrix operator-(const SquareMatrix &B) const {
    return SquareMatrix(*this) -= B;
  }

  SquareMatrix operator*(const SquareMatrix &B) const {
    return SquareMatrix(*this) *= B;
  }

  SquareMatrix operator^(uint64_t k) const {
    return SquareMatrix(*this) ^= k;
  }

  friend ostream &operator<<(ostream &os, SquareMatrix &p) {
    for(int i = 0; i < N; i++) {
      os << "[";
      for(int j = 0; j < N; j++) {
        os << p[i][j] << (j + 1 == N ? "]\n" : ",");
      }
    }
    return os;
  }
};


int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  string L, R, U, D;
  cin >> L >> R >> U >> D;
  for(auto &c : L) c = (c == 'B');
  for(auto &c : R) c = (c == 'B');
  for(auto &c : U) c = (c == 'B');
  for(auto &c : D) c = (c == 'B');
  vector< char > T(Q);
  vector< int > X(Q), Y(Q);
  for(int i = 0; i < Q; i++) {
    cin >> T[i] >> X[i] >> Y[i];
  }

  using Mat = SquareMatrix< int, 2 >;

  auto beet = [&](int x, int y) {
    Mat mat;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        mat[i][j] = 0;
        if(i != j) mat[i][j] += M;
        if(i != x) mat[i][j] += 1;
        if(i != y) mat[i][j] += 1;
      }
    }
    return mat;
  };


  auto solve = [&]() {
    using Node = array< array< Mat, 2 >, 2 >;
    auto f = [](const Node &a, const Node &b) {
      Node ret;
      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
          for(int k = 0; k < 2; k++) {
            for(int l = 0; l < 2; l++) {
              ret[i][j][k][l] = inf;
            }
          }
        }
      }
      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
          for(int k = 0; k < 2; k++) {
            for(int l = 0; l < 2; l++) {
              for(int m = 0; m < 2; m++) {
                chmin(ret[i][j][k][m], a[i][j][k][l] + b[i][j][l][m]);
              }
            }
          }
        }
      }
      return ret;
    };
    auto g = [](Node a, const pair< bool, bool > &x) {
      if(x.first) {
        swap(a[0][0], a[1][0]);
        swap(a[0][1], a[1][1]);
      }
      if(x.second) {
        swap(a[1][0], a[1][1]);
        swap(a[0][0], a[0][1]);
      }
      return a;
    };
    auto h = [](pair< bool, bool > x, const pair< bool, bool > &y) {
      x.first ^= y.first;
      x.second ^= y.second;
      return x;
    };
    Node base;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          for(int l = 0; l < 2; l++) {
            base[i][j][k][l] = k == l ? 0 : inf;
          }
        }
      }
    }
    LazySegmentTree< Node, pair< bool, bool > > seg(N, f, g, h, base, make_pair(false, false));
    for(int i = 0; i < N; i++) {
      Node dp;
      for(int x = 0; x < 2; x++) {
        for(int y = 0; y < 2; y++) {
          dp[x][y] = beet(L[i] ^ x, R[i] ^ y);
        }
      }
      seg.set(i, dp);
    }
    seg.build();

    using pi = pair< int, int >;
    auto f2 = [](const pi &a, const pi &b) { return pi(a.first + b.first, a.second + b.second); };
    auto g2 = [](const pi &a, bool b) { return pi(a.second, a.first); };
    auto h2 = [](bool a, bool b) { return a ^ b; };
    LazySegmentTree< pi, bool > seg2(M, f2, g2, h2, pi(), false), seg3(M, f2, g2, h2, pi(), false);
    for(int i = 0; i < M; i++) {
      seg2.set(i, pi(U[i] ^ 1, U[i]));
      seg3.set(i, pi(D[i] ^ 1, D[i]));
    }
    seg2.build();
    seg3.build();

    auto tapris = [&]() {
      int ret = inf;
      for(int x = 0; x < 2; x++) {
        int aa = x ? seg2.query(0, M).first : seg2.query(0, M).second;
        for(int y = 0; y < 2; y++) {
          int bb = y ? seg3.query(0, M).first : seg3.query(0, M).second;
          chmin(ret, aa + bb + seg.query(0, N)[0][0][x][y]);
        }
      }
      return ret;
    };

    vector< int > ans(Q + 1);
    ans[0] = tapris();
    for(int i = 0; i < Q; i++) {
      if(T[i] == 'U') seg2.update(X[i] - 1, Y[i], true);
      else if(T[i] == 'D') seg3.update(X[i] - 1, Y[i], true);
      else if(T[i] == 'L') seg.update(X[i] - 1, Y[i], make_pair(true, false));
      else if(T[i] == 'R') seg.update(X[i] - 1, Y[i], make_pair(false, true));
      ans[i + 1] = tapris();
    }
    return ans;
  };
  auto ret1 = solve();
  swap(N, M);
  swap(U, L);
  swap(D, R);
  for(int i = 0; i < Q; i++) {
    if(T[i] == 'U') T[i] = 'L';
    else if(T[i] == 'L') T[i] = 'U';
    else if(T[i] == 'R') T[i] = 'D';
    else T[i] = 'R';
  }
  auto ret2 = solve();
  for(int i = 0; i <= Q; i++) {
    cout << min(ret1[i], ret2[i]) << "\n";
  }
}