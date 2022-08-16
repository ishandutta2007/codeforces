#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
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

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;


template< typename SUM, typename KEY >
struct LinkCutTreeSubtree {

  struct Node {
    Node *l, *r, *p;

    KEY key;
    SUM sum;

    bool rev;
    int sz;

    bool is_root() const {
      return !p || (p->l != this && p->r != this);
    }

    Node(const KEY &key, const SUM &sum) :
        key(key), sum(sum), rev(false), sz(1),
        l(nullptr), r(nullptr), p(nullptr) {}
  };

  const SUM ident;

  LinkCutTreeSubtree(const SUM &ident) : ident(ident) {}

  Node *make_node(const KEY &key) {
    auto ret = new Node(key, ident);
    update(ret);
    return ret;
  }

  Node *set_key(Node *t, const KEY &key) {
    expose(t);
    t->key = key;
    update(t);
    return t;
  }

  void toggle(Node *t) {
    swap(t->l, t->r);
    t->sum.toggle();
    t->rev ^= true;
  }

  void push(Node *t) {
    if(t->rev) {
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev = false;
    }
  }


  void update(Node *t) {
    t->sz = 1;
    if(t->l) t->sz += t->l->sz;
    if(t->r) t->sz += t->r->sz;
    t->sum.merge(t->key, t->l ? t->l->sum : ident, t->r ? t->r->sum : ident);
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


  Node *expose(Node *t) {
    Node *rp = nullptr;
    for(auto *cur = t; cur; cur = cur->p) {
      splay(cur);
      if(cur->r) cur->sum.add(cur->r->sum);
      cur->r = rp;
      if(cur->r) cur->sum.erase(cur->r->sum);
      update(cur);
      rp = cur;
    }
    splay(t);
    return rp;
  }

  void link(Node *child, Node *parent) {
    expose(child);
    expose(parent);
    child->p = parent;
    parent->r = child;
    update(parent);
  }

  void cut(Node *child) {
    expose(child);
    auto *parent = child->l;
    child->l = nullptr;
    parent->p = nullptr;
    update(child);
  }

  void evert(Node *t) {
    expose(t);
    toggle(t);
    push(t);
  }

  Node *lca(Node *u, Node *v) {
    if(get_root(u) != get_root(v)) return nullptr;
    expose(u);
    return expose(v);
  }


  Node *get_kth(Node *x, int k) {
    expose(x);
    while(x) {
      push(x);
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
      push(x);
      x = x->l;
    }
    return x;
  }

  SUM &query(Node *t) {
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


  using pi = pair< bool, modint >;
  // first: true : 
  // first: false : 


  struct Sum {
    modint all, pdist, cdist, mdist;

    modint sz, msz;

    Sum() : all(0), pdist(0), cdist(0), mdist(0), sz(0), msz(0) {}

    void toggle() {
      swap(pdist, cdist);
    }

    void merge(pi key, const Sum &parent, const Sum &child) {


      if(key.first) {
        all = parent.all + key.second + child.all;
        pdist = parent.pdist + (child.all + key.second) * (parent.sz + msz) + child.pdist + mdist;
        cdist = child.cdist + (parent.all + key.second) * (child.sz + msz) + parent.cdist + mdist;
        sz = parent.sz + child.sz + msz;
      } else {
        all = parent.all + child.all;
        pdist = parent.pdist + child.all * (parent.sz + msz + key.second) + child.pdist + mdist;
        cdist = child.cdist + parent.all * (child.sz + msz + key.second) + parent.cdist + mdist;
        sz = parent.sz + key.second + child.sz + msz;
      }
    }

    void add(const Sum &chsum) {
      mdist += chsum.cdist;
      msz += chsum.sz;
    }

    void erase(const Sum &chsum) {
      mdist -= chsum.cdist;
      msz -= chsum.sz;
    }
  } e;


  int N;
  cin >> N;
  vector< pair< int, int > > add[100000], del[100000];
  modint uku = 1;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    int len = b - a + 1;
    uku *= len;
    add[a].emplace_back(i, len);
    del[b].emplace_back(i, len);
  }
  UnWeightedGraph g(N);
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }

  using LCT = LinkCutTreeSubtree< Sum, pi >;
  LCT lct(e);
  vector< LCT::Node * > vv(N), ee(N);
  MFP([&](auto dfs, int idx, int par) -> void {
    vv[idx] = lct.make_node(pi(false, 0));
    for(auto &to : g[idx]) {
      if(to == par) continue;
      dfs(to, idx);
      ee[to] = lct.make_node(pi(true, 1));
      lct.link(vv[to], ee[to]);
      lct.link(ee[to], vv[idx]);
    }
  })(0, -1);


  vector< modint > rev(101010);
  for(int i = 0; i < 101010; i++) rev[i] = modint(1) / i;

  modint now = 0, ret = 0;
  for(int i = 0; i < 100000; i++) {
    for(auto &p : add[i]) {
      lct.evert(vv[p.first]);
      now += vv[p.first]->sum.cdist * rev[p.second];
      lct.set_key(vv[p.first], pi(false, rev[p.second]));
    }
    ret += now;
    for(auto &p : del[i]) {
      lct.evert(vv[p.first]);
      now -= vv[p.first]->sum.cdist * rev[p.second];
      lct.set_key(vv[p.first], pi(false, 0));
    }
  }
  cout << ret * uku << endl;
}