#include<bits/stdc++.h>

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

template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;


/**
 * @brief Reversible-Splay-Tree(Splay)
 */
template< typename Monoid = int, typename OperatorMonoid = void >
struct ReversibleSplayTree {
public:
  using S = function< Monoid(Monoid) >;

  struct Node {
    Node *l, *r, *p;
    Monoid key, sum;
    bool rev;

    bool is_root() const {
      return !p || (p->l != this && p->r != this);
    }

    Node(const Monoid &key) :
        key(key), sum(key), rev(false),
        l(nullptr), r(nullptr), p(nullptr) {}
  };


  inline size_t count(const Node *t) { return t ? t->sz : 0; }

  inline const Monoid &sum(const Node *t) { return t ? t->sum : 0; }

  Node *alloc(const Monoid &v = Monoid()) {
    return new Node(v);
  }

  void splay(Node *t) {
    push(t);
    while(!t->is_root()) {
      auto *q = t->p;
      if(q->is_root()) {
        push(q), push(t);
        if(q->l == t) rotr(t);
        else rotl(t);
      } else {
        auto *r = q->p;
        push(r), push(q), push(t);
        if(r->l == q) {
          if(q->l == t) rotr(q), rotr(t);
          else rotl(t), rotr(t);
        } else {
          if(q->r == t) rotl(q), rotl(t);
          else rotr(t), rotl(t);
        }
      }
    }
  }

  Node *push_front(Node *t, const Monoid &v = Monoid()) {
    if(!t) {
      t = alloc(v);
      return t;
    } else {
      splay(t);
      Node *cur = get_left(t), *z = alloc(v);
      splay(cur);
      z->p = cur;
      cur->l = z;
      splay(z);
      return z;
    }
  }

  Node *push_back(Node *t, const Monoid &v = Monoid()) {
    if(!t) {
      t = alloc(v);
      return t;
    } else {
      splay(t);
      Node *cur = get_right(t), *z = alloc(v);
      splay(cur);
      z->p = cur;
      cur->r = z;
      splay(z);
      return z;
    }
  }

  Node *erase(Node *t) {
    splay(t);
    Node *x = t->l, *y = t->r;
    delete t;
    if(!x) {
      t = y;
      if(t) t->p = nullptr;
    } else if(!y) {
      t = x;
      t->p = nullptr;
    } else {
      x->p = nullptr;
      t = get_right(x);
      splay(t);
      t->r = y;
      y->p = t;
    }
    return t;
  }

  Node *get_left(Node *t) const {
    while(t->l) t = t->l;
    return t;
  }

  Node *get_right(Node *t) const {
    while(t->r) t = t->r;
    return t;
  }

  pair< Node *, Node * > split(Node *t, int k) {
    if(!t) return {nullptr, nullptr};
    push(t);
    if(k <= count(t->l)) {
      auto x = split(t->l, k);
      t->l = x.second;
      t->p = nullptr;
      if(x.second) x.second->p = t;
      return {x.first, update(t)};
    } else {
      auto x = split(t->r, k - count(t->l) - 1);
      t->r = x.first;
      t->p = nullptr;
      if(x.first) x.first->p = t;
      return {update(t), x.second};
    }
  }

  template< typename ... Args >
  Node *merge(Node *l, Args ...rest) {
    Node *r = merge(rest...);
    if(!l && !r) return nullptr;
    if(!l) return splay(r), r;
    if(!r) return splay(l), l;
    splay(l), splay(r);
    l = get_right(l);
    splay(l);
    l->r = r;
    r->p = l;
    update(l);
    return l;
  }

  void insert(Node *&t, int k, const Monoid &v) {
    splay(t);
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }

  Monoid erase(Node *&t, int k) {
    splay(t);
    auto x = split(t, k);
    auto y = split(x.second, 1);
    auto v = y.first->c;
    delete y.first;
    t = merge(x.first, y.second);
    return v;
  }

  Monoid query(Node *&t, int a, int b) {
    splay(t);
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    auto ret = sum(y.first);
    t = merge(x.first, y.first, y.second);
    return ret;
  }

  Node *build(const vector< Monoid > &v) {
    return build(0, (int) v.size(), v);
  }

  void toggle(Node *t) {
    swap(t->l, t->r);
    t->rev ^= true;
  }

  Node *update(Node *t) {
    t->sum = t->key;
    if(t->l) t->sum += t->l->sum;
    if(t->r) t->sum += t->r->sum;
    return t;
  }

  tuple< Node *, Node *, Node * > split3(Node *t, int a, int b) {
    splay(t);
    auto x = split(t, a);
    auto y = split(x.second, b - a);
    return make_tuple(x.first, y.first, y.second);
  }

  void push(Node *t) {
    if(t->rev) {
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev = false;
    }
  }

  void set_element(Node *&t, int k, const Monoid &x) {
    splay(t);
    sub_set_element(t, k, x);
  }

private:

  Node *build(int l, int r, const vector< Monoid > &v) {
    if(l + 1 >= r) return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }

  Node *sub_set_element(Node *&t, int k, const Monoid &x) {
    push(t);
    if(k < count(t->l)) {
      return sub_set_element(t->l, k, x);
    } else if(k == count(t->l)) {
      t->key = x;
      splay(t);
      return t;
    } else {
      return sub_set_element(t->r, k - count(t->l) - 1, x);
    }
  }


  void rotr(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->l = t->r)) t->r->p = x;
    t->r = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  void rotl(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->r = t->l)) t->l->p = x;
    t->l = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  Node *merge(Node *l) {
    return l;
  }
};


/**
 * @brief Link-Cut-Tree
 */
template< template< typename, typename > typename ST, typename Monoid = int, typename OperatorMonoid = Monoid >
struct LinkCutTree : ST< Monoid, OperatorMonoid > {
  using LST = ST< Monoid, OperatorMonoid >;
  using ST< Monoid, OperatorMonoid >::ST;
  using Node = typename LST::Node;

  Node *expose(Node *t) {
    Node *rp = nullptr;
    for(Node *cur = t; cur; cur = cur->p) {
      this->splay(cur);
      cur->r = rp;
      this->update(cur);
      rp = cur;
    }
    this->splay(t);
    return rp;
  }

  void link(Node *child, Node *parent) {
    expose(child);
    expose(parent);
    child->p = parent;
    parent->r = child;
    this->update(parent);
  }

  void cut(Node *child) {
    expose(child);
    auto *parent = child->l;
    child->l = nullptr;
    parent->p = nullptr;
    this->update(child);
  }

  void evert(Node *t) {
    expose(t);
    this->toggle(t);
    this->push(t);
  }

  Node *lca(Node *u, Node *v) {
    if(get_root(u) != get_root(v)) return nullptr;
    expose(u);
    return expose(v);
  }

  void set_propagate(Node *t, const OperatorMonoid &x) {
    expose(t);
    LST::set_propagate(t, x);
  }

  Node *get_kth(Node *x, int k) {
    expose(x);
    while(x) {
      this->push(x);
      if(x->r && x->r->sz > k) {
        x = x->r;
      } else {
        if(x->r) k -= x->r->sz;
        if(k == 0) return x;
        k -= 1;
        x = x->l;
      }
    }
    return nullptr;
  }

  Node *get_root(Node *x) {
    expose(x);
    while(x->l) {
      this->push(x);
      x = x->l;
    }
    return x;
  }

  const Monoid &query(Node *t) {
    expose(t);
    return t->sum;
  }
};


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

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;

int main() {
  int N, Q;
  cin >> N;


  using LCT = LinkCutTree< ReversibleSplayTree, int64 >;
  auto add = [](int64 a, int64 b) { return a + b; };
  auto s = [](int64 a) { return a; };
  LCT lct;
  vector< LCT::Node * > vs(N);
  for(int i = 0; i < N; i++) {
    vs[i] = lct.alloc(0);
  }
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    lct.evert(vs[a]);
    lct.link(vs[a], vs[b]);
  }

  vector< int > A(N);
  cin >> A;
  cin >> Q;


  vector< int > sieve(10000001, -1);
  for(int i = 2; i < (int) sieve.size(); i++) {
    if(sieve[i] == -1) {
      for(int j = i; j < (int) sieve.size(); j += i) {
        sieve[j] = i;
      }
    }
  }

  vector< vector< pair< int, int > > > as(10000001);
  {
    vector< pair< int, int > > upd;
    for(int i = 0; i < N; i++) {
      int x = A[i];
      while(~sieve[x]) {
        if(upd.empty() || upd.back().first != sieve[x]) {
          upd.emplace_back(sieve[x], 0);
        }
        upd.back().second++;
        x /= sieve[x];
      }
      for(auto &p : upd) {
        as[p.first].emplace_back(p.second, i);
      }
      upd.clear();
    }
  }

  vector< vector< pair< int, int > > > qs(10000001);
  vector< int > X(Q), Y(Q);
  {
    vector< pair< int, int > > upd;
    for(int i = 0; i < Q; i++) {
      int x;
      cin >> X[i] >> Y[i] >> x;
      --X[i], --Y[i];
      while(~sieve[x]) {
        if(upd.empty() || upd.back().first != sieve[x]) {
          upd.emplace_back(sieve[x], 0);
        }
        upd.back().second++;
        x /= sieve[x];
      }
      for(auto &p : upd) {
        qs[p.first].emplace_back(p.second, i);
      }
      upd.clear();
    }
  }


  vector< modint > ans(Q, modint(1));


  vector< int64 > sum(Q, 0);

  // sum min(qs[i], as[i])
  for(int i = 2; i < sieve.size(); i++) {
    if(qs[i].empty() || as[i].empty()) continue;
    sort(begin(qs[i]), end(qs[i]));
    sort(begin(as[i]), end(as[i]));
    for(auto &p : qs[i]) sum[p.second] = 0;


    {
      for(auto &p : as[i]) {
        lct.expose(vs[p.second]);
        vs[p.second]->key = 1;
        lct.update(vs[p.second]);
      }
      // qs[i] count
      int j = 0;
      for(auto &p : qs[i]) {
        while(j < as[i].size() && as[i][j].first <= p.first) {
          lct.expose(vs[as[i][j].second]);
          vs[as[i][j].second]->key = 0;
          lct.update(vs[as[i][j].second]);
          ++j;
        }
        lct.evert(vs[X[p.second]]);
        lct.expose(vs[Y[p.second]]);
        sum[p.second] += 1LL * vs[Y[p.second]]->sum * p.first;
      }
      while(j < as[i].size()) {
        lct.expose(vs[as[i][j].second]);
        vs[as[i][j].second]->key = 0;
        lct.update(vs[as[i][j].second]);
        ++j;
      }
    }

    {
      // qs[i] count
      int j = 0;
      for(auto &p : qs[i]) {
        while(j < as[i].size() && as[i][j].first <= p.first) {
          lct.expose(vs[as[i][j].second]);
          vs[as[i][j].second]->key = as[i][j].first;
          lct.update(vs[as[i][j].second]);
          ++j;
        }
        lct.evert(vs[X[p.second]]);
        lct.expose(vs[Y[p.second]]);
        sum[p.second] += 1LL * vs[Y[p.second]]->sum;
      }
      for(auto &p : as[i]) {
        lct.expose(vs[p.second]);
        vs[p.second]->key = 0;
        lct.update(vs[p.second]);
      }
    }

    for(auto &p : qs[i]) {
      ans[p.second] *= modint(i).pow(sum[p.second]);
    }
  }

  for(auto &p : ans) cout << p << "\n";
}