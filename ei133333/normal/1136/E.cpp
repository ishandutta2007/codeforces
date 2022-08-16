#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using P = function< OperatorMonoid(OperatorMonoid, int) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const P p;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0) {
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
      data[k] = g(data[k], p(lazy[k], len));
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
};


int main() {
  int N, Q;

  cin >> N;
  vector< int > A(N);
  cin >> A;
  vector< int > K(N - 1);
  cin >> K;
  cin >> Q;

  using pi = pair< int64, bool >;
  auto f1 = [](int64 a, int64 b) { return a + b; };
  auto g1 = [](int64 a, pi b) { return b.first; };
  auto h1 = [](pi a, pi b) { return b; };
  auto p1 = [](pi a, int p) { return pi(a.first * p, a.second); };
  LazySegmentTree< int64, pi > seg1(N, f1, g1, h1, p1, 0, pi());

  auto f2 = [](int64 a, int64 b) { return max(a, b); };
  auto p2 = [](pi a, int p) { return a; };
  LazySegmentTree< int64, pi > seg2(N, f2, g1, h1, p2, -infll, pi());


  vector< int64 > sum(N + 1);
  for(int i = 0; i < N - 1; i++) {
    sum[i + 1] += K[i];
    sum[i + 1] += sum[i];
    A[i + 1] -= sum[i + 1];
  }
  vector< int64 > sum2(N + 1);
  for(int i = 0; i < N; i++) {
    sum2[i + 1] += sum[i];
    sum2[i + 1] += sum2[i];
  }


  for(int i = 0; i < N; i++) {
    seg1.set(i, A[i]);
    seg2.set(i, A[i]);
  }
  seg1.build();
  seg2.build();

  for(int i = 0; i < Q; i++) {
    char T;
    cin >> T;
    if(T == '+') {
      int k, x;
      cin >> k >> x;
      --k;
      int64 v = seg1[k];
      v += x;
      int ok = k + 1, ng = N + 1;
      while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(seg2.query(k, mid) < v) ok = mid;
        else ng = mid;
      }
      seg1.update(k, ok, pi(v, true));
      seg2.update(k, ok, pi(v, true));
      /*
      A[k] += x;
      for(int j = k + 1; j < N; j++) {
        if(A[k] > A[j]) A[j] = A[k];
      }
       */
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << seg1.query(l, r) + sum2[r] - sum2[l] << endl;
    }
  }
}