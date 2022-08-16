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

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  struct Node {
    int type; // type=0: {}, type=1, <<<<<, type=2 >>>>>, type=3: ><  ><, type=4: ><  >, type=5: <  ><, type=6: <  >, type7: >><<
    int latte, malta;
    int ans;

    Node() : type(0), latte(0), malta(0), ans(0) {}

    Node(int t, int l, int r, int a) : type(t), latte(l), malta(r), ans(max({a, l, r})) {}
  };

  using pi = pair< Node, Node >;
  auto ff = [](const Node &a, const Node &b) -> Node {
    if(a.type == 0) return b;
    if(b.type == 0) return a;
    int U = max(a.ans, b.ans);
    if(a.type == 1) {
      if(b.type == 1) return Node(1, a.latte + b.latte, a.latte + b.latte, U);
      if(b.type == 2) return Node(6, a.latte, b.latte, U);
      if(b.type == 3) return Node(5, a.latte, b.malta, U);
      if(b.type == 4) return Node(6, a.latte, b.malta, U);
      if(b.type == 5) return Node(5, a.latte + b.latte, b.malta, U);
      if(b.type == 6) return Node(6, a.latte + b.latte, b.malta, U);
      if(b.type == 7) return Node(5, a.latte, b.malta, U);
    }
    if(a.type == 2) {  // >>>>
      if(b.type == 1) return Node(7, a.latte + b.latte, a.latte + b.latte, U);
      if(b.type == 2) return Node(2, a.latte + b.latte, a.latte + b.latte, U);
      if(b.type == 3) return Node(3, a.latte + b.latte, b.malta, U);
      if(b.type == 4) return Node(4, a.latte + b.latte, b.malta, U);
      if(b.type == 5) return Node(3, a.latte + b.latte, b.malta, U);
      if(b.type == 6) return Node(4, a.latte + b.latte, b.malta, U);
      if(b.type == 7) return Node(7, a.latte + b.latte, a.latte + b.latte, U);
    }
    if(a.type == 3) { // ><><
      if(b.type == 1) return Node(3, a.latte, a.malta + b.malta, U);
      if(b.type == 2) return Node(4, a.latte, b.malta, U);
      if(b.type == 3) return Node(3, a.latte, b.malta, U);
      if(b.type == 4) return Node(4, a.latte, b.malta, U);
      if(b.type == 5) return Node(3, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 6) return Node(4, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 7) return Node(3, a.latte, b.malta, U);
    }
    if(a.type == 4) { // >< >
      if(b.type == 1) return Node(3, a.latte, a.malta + b.malta, U);
      if(b.type == 2) return Node(4, a.latte, a.malta + b.malta, U);
      if(b.type == 3) return Node(3, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 4) return Node(4, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 5) return Node(3, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 6) return Node(4, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 7) return Node(3, a.latte, a.malta + b.latte, U);
    }
    if(a.type == 5) { // < ><
      if(b.type == 1) return Node(5, a.latte, a.malta + b.malta, U);
      if(b.type == 2) return Node(6, a.latte, b.malta, U);
      if(b.type == 3) return Node(5, a.latte, b.malta, U);
      if(b.type == 4) return Node(6, a.latte, b.malta, U);
      if(b.type == 5) return Node(5, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 6) return Node(6, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 7) return Node(5, a.latte, b.malta, U);
    }
    if(a.type == 6) { // <  >
      if(b.type == 1) return Node(5, a.latte, a.malta + b.malta, U);
      if(b.type == 2) return Node(6, a.latte, a.malta + b.malta, U);
      if(b.type == 3) return Node(5, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 4) return Node(6, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 5) return Node(5, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 6) return Node(6, a.latte, b.malta, max(U, a.malta + b.latte));
      if(b.type == 7) return Node(5, a.latte, a.malta + b.latte, U);
    }
    if(a.type == 7) { // >><<
      if(b.type == 1) return Node(7, a.latte + b.latte, a.latte + b.latte, U);
      if(b.type == 2) return Node(4, a.latte, b.latte, U);
      if(b.type == 3) return Node(3, a.latte, b.malta, U);
      if(b.type == 4) return Node(4, a.latte, b.malta, U);
      if(b.type == 5) return Node(3, a.latte + b.latte, b.malta, U);
      if(b.type == 6) return Node(4, a.latte + b.latte, b.malta, U);
      if(b.type == 7) return Node(3, a.latte, b.malta, U);
    }
  };
  auto f = [&](const pi &x, const pi &y) {
    return pi(ff(x.first, y.first), ff(x.second, y.second));
  };
  auto g = [](pi x, bool y) {
    swap(x.first, x.second);
    return x;
  };
  auto h = [](bool x, bool y) -> bool {
    return x ^ y;
  };
  LazySegmentTree< pi, bool > seg(N, f, g, h, pi(Node(), Node()), false);
  for(int i = 0; i < N; i++) {
    if(S[i] == '<') seg.set(i, pi(Node(1, 1, 1, 1), Node(2, 1, 1, 1)));
    else seg.set(i, pi(Node(2, 1, 1, 1), Node(1, 1, 1, 1)));
  }
  seg.build();
  while(Q--) {
    int L, R;
    cin >> L >> R;
    --L;
    seg.update(L, R, true);
    cout << seg.query(L, R).first.ans << "\n";
  }
}