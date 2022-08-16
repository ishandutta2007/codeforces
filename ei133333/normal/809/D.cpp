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

template< class Monoid, class OperatorMonoid = Monoid >
struct RandomizedBinarySearchTree {
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using P = function< OperatorMonoid(OperatorMonoid, int) >;

  inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  struct Node {
    Node *l, *r;
    int cnt;
    Monoid key, sum;
    OperatorMonoid lazy;

    Node() = default;

    Node(const Monoid &k, const OperatorMonoid &p) : cnt(1), key(k), sum(k), lazy(p), l(nullptr), r(nullptr) {}
  };

  vector< Node > pool;
  int ptr;

  const Monoid M1;
  const OperatorMonoid OM0;
  const F f;
  const G g;
  const H h;
  const P p;

  RandomizedBinarySearchTree(int sz, const F &f, const Monoid &M1) :
      pool(sz), ptr(0), f(f), g(G()), h(H()), p(P()), M1(M1), OM0(OperatorMonoid()) {}

  RandomizedBinarySearchTree(int sz, const F &f, const G &g, const H &h, const P &p,
                             const Monoid &M1, const OperatorMonoid &OM0) :
      pool(sz), ptr(0), f(f), g(g), h(h), p(p), M1(M1), OM0(OM0) {}

  inline Node *alloc(const Monoid &key) { return &(pool[ptr++] = Node(key, OM0)); }

  virtual Node *clone(Node *t) { return t; }

  inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline Monoid sum(const Node *t) { return t ? t->sum : M1; }

  inline Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
    return t;
  }

  Node *propagate(Node *t) {
    t = clone(t);
    if(t->lazy != OM0) {
      t->key = g(t->key, p(t->lazy, 1));
      if(t->l) {
        t->l = clone(t->l);
        t->l->lazy = h(t->l->lazy, t->lazy);
        t->l->sum = g(t->l->sum, p(t->lazy, count(t->l)));
      }
      if(t->r) {
        t->r = clone(t->r);
        t->r->lazy = h(t->r->lazy, t->lazy);
        t->r->sum = g(t->r->sum, p(t->lazy, count(t->r)));
      }
      t->lazy = OM0;
    }
    return update(t);
  }

  Node *merge(Node *l, Node *r) {
    if(!l || !r) return l ? l : r;
    if(xor128() % (l->cnt + r->cnt) < l->cnt) {
      l = propagate(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      r = propagate(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {t, t};
    t = propagate(t);
    if(k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Node *build(int l, int r, const vector< Monoid > &v) {
    if(l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *build(const vector< Monoid > &v) {
    ptr = 0;
    return build(0, (int) v.size(), v);
  }

  void dump(Node *r, typename vector< Monoid >::iterator &it) {
    if(!r) return;
    r = propagate(r);
    dump(r->l, it);
    *it = r->key;
    dump(r->r, ++it);
  }

  vector< Monoid > dump(Node *r) {
    vector< Monoid > v((size_t) count(r));
    auto it = begin(v);
    dump(r, it);
    return v;
  }

  string to_string(Node *r) {
    auto s = dump(r);
    string ret;
    for(int i = 0; i < s.size(); i++) ret += ", ";
    return (ret);
  }

  void insert(Node *&t, int k, const Monoid &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }

  void erase(Node *&t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }

  Monoid query(Node *&t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, merge(y.first, y.second));
    return ret;
  }

  void set_propagate(Node *&t, int a, int b, const OperatorMonoid &p) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    y.first->lazy = h(y.first->lazy, p);
    t = merge(x.first, merge(propagate(y.first), y.second));
  }

  void set_element(Node *&t, int k, const Monoid &x) {
    t = propagate(t);
    if(k < count(t->l)) set_element(t->l, k, x);
    else if(k == count(t->l)) t->key = t->sum = x;
    else set_element(t->r, k - count(t->l) - 1, x);
    t = update(t);
  }


  int size(Node *t) {
    return count(t);
  }

  bool empty(Node *t) {
    return !t;
  }

  Node *makeset() {
    return nullptr;
  }

  int lower_bound(Node *t, const Monoid &x) {
    if(!t) return 0;
    t = propagate(t);
    if(x <= t->key) return lower_bound(t->l, x);
    return lower_bound(t->r, x) + count(t->l) + 1;
  }
};


int main() {
  int N;
  cin >> N;

  auto f = [](int a, int b) { return max(a, b); };
  auto g = [](int a, int b) { return a + b; };
  auto p = [](int a, int b) { return a; };
  RandomizedBinarySearchTree< int, int > rbst(N, f, g, g, p, 0, 0);
  RandomizedBinarySearchTree< int, int >::Node *root = nullptr;
  for(int i = 0; i < N; i++) {
    int L, R;
    cin >> L >> R;
    // L-1i<R  dp[a..b]
    // dp[a]=L
    // dp[j+1]=dp[j]+1 (ajb)
    auto latte = rbst.split(root, rbst.lower_bound(root, L));
    auto malta = rbst.split(latte.second, rbst.lower_bound(latte.second, R));
    if(malta.first) malta.first->lazy++;
    auto beet = rbst.split(malta.second, 1);
    root = rbst.merge(rbst.merge(rbst.merge(latte.first, rbst.alloc(L)), malta.first), beet.second);
  }
  cout << rbst.count(root) << "\n";
}