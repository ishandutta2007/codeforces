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

template< class T >
struct VectorPool {
  vector< T > pool;
  vector< T * > stock;
  int ptr;

  VectorPool() = default;

  VectorPool(int sz) : pool(sz), stock(sz) {}

  inline T *alloc() { return stock[--ptr]; }

  inline void free(T *t) { stock[ptr++] = t; }

  void clear() {
    ptr = (int) pool.size();
    for(int i = 0; i < pool.size(); i++) stock[i] = &pool[i];
  }
};


/**
 * @brief Weight-Balanced-Tree()
 */
template< typename Monoid, typename F >
struct WeightBalancedTree {
public:
  struct Node {
    Node *l, *r;
    int cnt;
    Monoid key, sum;

    Node() {}

    Node(const Monoid &k) : key(k), sum(k), l(nullptr), r(nullptr), cnt(1) {}

    Node(Node *l, Node *r, const Monoid &k) : key(k), l(l), r(r) {}

    bool is_leaf() { return !l || !r; }
  };

private:
  Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + t->is_leaf();
    t->sum = f(f(sum(t->l), t->key), sum(t->r));
    return t;
  }

  inline Node *alloc(Node *l, Node *r) {
    auto t = &(*pool.alloc() = Node(l, r, M1));
    return update(t);
  }

  Node *submerge(Node *l, Node *r) {
    if(count(l) * 2 > count(r) * 7) {
      l = clone(l);
      auto nl = clone(l->l);
      auto nr = submerge(l->r, r);
      if(count(nl) * 7 >= count(nr) * 2) {
        l->r = nr;
        return update(l);
      }
      if(count(nr->l) * 2 <= count(nr->r) * 5) {
        l->r = nr->l;
        nr->l = l;
        update(l);
        return update(nr);
      }
      Node *t = clone(nr->l);
      l->r = nr->l->l;
      update(l);
      nr->l = nr->l->r;
      update(nr);
      t->l = l;
      t->r = nr;
      return update(t);
    }
    if(count(l) * 7 < count(r) * 2) {
      r = clone(r);
      auto nl = submerge(l, r->l);
      auto nr = clone(r->r);
      if(count(nl) * 2 <= count(nr) * 7) {
        r->l = nl;
        return update(r);
      }
      if(count(nl->l) * 5 >= count(nl->r) * 2) {
        r->l = nl->r;
        nl->r = r;
        update(r);
        return update(nl);
      }
      Node *t = clone(nl->r);
      r->l = nl->r->r;
      update(r);
      nl->r = nl->r->l;
      update(nl);
      t->r = r;
      t->l = nl;
      return update(t);
    }
    return alloc(l, r);
  }

  Node *build(int l, int r, const vector< Monoid > &v) {
    if(l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  void dump(Node *r, typename vector< Monoid >::iterator &it) {
    if(r->is_leaf()) {
      *it++ = r->key;
      return;
    }
    dump(r->l, it);
    dump(r->r, it);
  }

  virtual Node *clone(Node *t) {
    return t;
  }

  Node *merge(Node *l) {
    return l;
  }

  Monoid query(Node *t, int a, int b, int l, int r) {
    if(r <= a || b <= l) return M1;
    if(a <= l && r <= b) return t->sum;
    return f(query(t->l, a, b, l, l + count(t->l)), query(t->r, a, b, r - count(t->r), r));
  }

public:
  VectorPool< Node > pool;
  const F f;
  const Monoid M1;

  WeightBalancedTree(int sz, const F &f, const Monoid &M1) : pool(sz), M1(M1), f(f) {
    pool.clear();
  }

  inline Node *alloc(const Monoid &key) {
    return &(*pool.alloc() = Node(key));
  }

  static inline int count(const Node *t) { return t ? t->cnt : 0; }

  inline const Monoid &sum(const Node *t) { return t ? t->sum : M1; }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {nullptr, nullptr};
    if(k == 0) return {nullptr, t};
    if(k >= count(t)) return {t, nullptr};
    t = clone(t);
    Node *l = t->l, *r = t->r;
    pool.free(t);
    if(k < count(l)) {
      auto pp = split(l, k);
      return {pp.first, merge(pp.second, r)};
    }
    if(k > count(l)) {
      auto pp = split(r, k - count(l));
      return {merge(l, pp.first), pp.second};
    }
    return {l, r};
  }

  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    return make_tuple(x.first, y.first, y.second);
  }

  template< typename ... Args >
  Node *merge(Node *l, Args ...rest) {
    Node *r = merge(rest...);
    if(!l || !r) return l ? l : r;
    return submerge(l, r);
  }

  Node *build(const vector< Monoid > &v) {
    return build(0, (int) v.size(), v);
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
    for(int i = 0; i < s.size(); i++) {
      ret += std::to_string(s[i]);
      ret += ", ";
    }
    return ret;
  }

  void insert(Node *&t, int k, const Monoid &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }

  Monoid erase(Node *&t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    auto v = y.first->c;
    pool.free(y.first);
    t = merge(x.first, y.second);
    return v;
  }

  Monoid query(Node *t, int a, int b) {
    return query(t, a, b, 0, count(t));
  }

  void set_element(Node *&t, int k, const Monoid &x) {
    t = clone(t);
    if(t->is_leaf()) {
      t->key = t->sum = x;
      return;
    }
    if(k < count(t->l)) set_element(t->l, k, x);
    else set_element(t->r, k - count(t->l), x);
    t = update(t);
  }

  void push_front(Node *&t, const Monoid &v) {
    t = merge(alloc(v), t);
  }

  void push_back(Node *&t, const Monoid &v) {
    t = merge(t, alloc(v));
  }

  Monoid pop_front(Node *&t) {
    auto ret = split(t, 1);
    t = ret.second;
    return ret.first->key;
  }

  Monoid pop_back(Node *&t) {
    auto ret = split(t, count(t) - 1);
    t = ret.first;
    return ret.second->key;
  }
};

/**
 * @brief Persistent-Weight-Balanced-Tree()
 */
template< typename Monoid, typename F, size_t FULL = 1000 >
struct PersistentWeightBalancedTree : WeightBalancedTree< Monoid, F > {
  using WBT = WeightBalancedTree< Monoid, F >;
  using WBT::WeightBalancedTree;
  using Node = typename WBT::Node;

private:
  Node *clone(Node *t) override {
    return &(*WBT::pool.alloc() = *t);
  }

public:
  Node *rebuild(Node *r) {
    auto ret = WBT::dump(r);
    WBT::pool.clear();
    return WBT::build(ret);
  }

  bool almost_full() const {
    return this->pool.ptr < FULL;
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

/**
 * @brief Rolling-Hash()
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 * @docs docs/rolling-hash.md
 */
struct RollingHash {
  static const uint64_t mod = (1ull << 61ull) - 1;
  using uint128_t = __uint128_t;
  vector< uint64_t > hashed, power;
  const uint64_t base;

  static inline uint64_t add(uint64_t a, uint64_t b) {
    if((a += b) >= mod) a -= mod;
    return a;
  }

  static inline uint64_t mul(uint64_t a, uint64_t b) {
    uint128_t c = (uint128_t) a * b;
    return add(c >> 61, c & mod);
  }

  static inline uint64_t generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution< uint64_t > rand(1, RollingHash::mod - 1);
    return rand(mt);
  }

  RollingHash() = default;

  RollingHash(const string &s, uint64_t base) : base(base) {
    size_t sz = s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
  }

  template< typename T >
  RollingHash(const vector< T > &s, uint64_t base) : base(base) {
    size_t sz = s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for(int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
  }

  uint64_t query(int l, int r) const {
    return add(hashed[r], mod - mul(hashed[l], power[r - l]));
  }

  uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) const {
    return add(mul(h1, power[h2len]), h2);
  }

  int lcp(const RollingHash &b, int l1, int r1, int l2, int r2) const {
    assert(base == b.base);
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(query(l1, l1 + mid) == b.query(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return low;
  }
};


int main() {
  int N, K, Q;
  cin >> N >> K;
  vector< int > S(N);
  cin >> S;
  cin >> Q;

  auto base = RollingHash::generate_base();
  vector< int64 > power(N + 1);
  power[0] = 1;
  for(int i = 0; i < N; i++) {
    power[i + 1] = RollingHash::mul(power[i], base);
  }

  using pi = pair< int64, int >;
  auto combine = [&](const pi &a, const pi &b) {
    return pi(RollingHash::add(RollingHash::mul(a.first, power[b.second]), b.first), a.second + b.second);
  };
  using LRBT = PersistentWeightBalancedTree< pi, decltype(combine), 10000 >;
  LRBT lrbst(3030303, combine, pi());

  struct Node {
    bool cbs;
    LRBT::Node *close, *open;
  };

  auto f = [&](const Node &a, const Node &b) {
    if(!a.cbs || !b.cbs) return (Node) {false};
    int close1 = LRBT::count(a.close);
    int open1 = LRBT::count(a.open);
    int close2 = LRBT::count(b.close);
    int open2 = LRBT::count(b.open);
    if(close1 == 0 && open1 == 0) return b;
    if(close2 == 0 && open2 == 0) return a;
    if(open1 == close2) {
      auto x = lrbst.sum(a.open).first;
      auto y = lrbst.sum(b.close).first;
      if(x != y) return (Node) {false};
      return (Node) {true, a.close, b.open};
    } else if(open1 > close2) {
      // )))) ((((, )) ((((
      auto x = lrbst.query(a.open, 0, close2).first;
      auto y = lrbst.sum(b.close).first;
      if(x != y) return (Node) {false};
      return (Node) {true, a.close, lrbst.merge(b.open, lrbst.split(a.open, close2).second)};
    } else {
      // )))) ((, ))))) ((
      auto x = lrbst.sum(a.open).first;
      auto y = lrbst.query(b.close, 0, open1).first;
      if(x != y) return (Node) {false};
      return (Node) {true, lrbst.merge(a.close, lrbst.split(b.close, open1).second), b.open};
    }
  };

  auto seg = SegmentTree< Node, decltype(f) >(N, f, (Node) {true, nullptr, nullptr});
  for(int i = 0; i < N; i++) {
    if(S[i] < 0) {
      auto v = lrbst.alloc(pi(-S[i], 1));
      seg.set(i, (Node) {true, v, nullptr});
    } else {
      auto v = lrbst.alloc(pi(S[i], 1));
      seg.set(i, (Node) {true, nullptr, v});
    }
  }
  seg.build();
  while(Q--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a;
    if(t == 1) {
      S[a] = b;
      if(b < 0) {
        auto v = lrbst.alloc(pi(-b, 1));
        seg.update(a, (Node) {true, v, nullptr});
      } else {
        auto v = lrbst.alloc(pi(b, 1));
        seg.update(a, (Node) {true, nullptr, v});
      }
    } else {
      auto ret = seg.query(a, b);
      if(ret.cbs && LRBT::count(ret.close) == 0 && LRBT::count(ret.open) == 0) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
      if(lrbst.almost_full()) {
        lrbst.pool.clear();
        for(int i = 0; i < N; i++) {
          if(S[i] < 0) {
            auto v = lrbst.alloc(pi(-S[i], 1));
            seg.set(i, (Node) {true, v, nullptr});
          } else {
            auto v = lrbst.alloc(pi(S[i], 1));
            seg.set(i, (Node) {true, nullptr, v});
          }
        }
        seg.build();
      }
    }
  }
}