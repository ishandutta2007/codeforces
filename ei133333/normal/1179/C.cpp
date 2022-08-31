#include<bits/stdc++.h>

using namespace std;using int64 = long long;
const int mod = 1e9 + 7;

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

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid, int) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz;
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
    while(sz < n) sz <<= 1;
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

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], lazy[k], len);
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

  int find(int a, int b, int x, int k, int l, int r) {
    propagate(k, r - l);
    if(data[k] > x || r <= a || b <= l) return (-1);
    if(k >= sz - 1) return (k - sz);
    int rv = find(a, b, x, 2 * k + 1, (l + r) >> 1, r);
    if(rv != -1) return (rv);
    return (find(a, b, x, 2 * k + 0, l, (l + r) >> 1));
  }

  int find(int a, int b, int x) {
    return (find(a, b, x, 1, 0, sz));
  }
};


int main() {
  int N, M, Q;
  cin >> N >> M;
  vector< int > A(N), B(M);
  cin >> A >> B;
  cin >> Q;

  auto f = [](int64 a, int64 b) { return min(a, b); };
  auto g = [](int64 a, int64 b, int64 p) { return a + b; };
  auto h = [](int64 a, int64 b) { return a + b; };

  LazySegmentTree< int64 > seg(1000001, f, g, h, infll, 0);
  for(int i = 0; i < 1000001; i++) {
    seg.set(i, 0);
  }
  seg.build();
  for(int i = 0; i < N; i++) {
    seg.update(0, A[i] + 1, -1);
  }
  for(int i = 0; i < M; i++) {
    seg.update(0, B[i] + 1, +1);
  }

  while(Q--) {
    int T, X, Y;
    cin >> T >> X >> Y;
    --X;
    if(T == 1) {
      seg.update(0, A[X] + 1, +1);
      A[X] = Y;
      seg.update(0, A[X] + 1, -1);
    } else {
      seg.update(0, B[X] + 1, -1);
      B[X] = Y;
      seg.update(0, B[X] + 1, +1);
    }
    cout << seg.find(0, 1000001, -1) << "\n";
  }
}