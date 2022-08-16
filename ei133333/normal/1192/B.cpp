#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int64 infll2 = infll / 10;
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
};

struct PQ {
  priority_queue< int64 > in, out;

  inline int64 top() {
    if(!in.empty()) return in.top();
    return -infll;
  }

  inline void insert(int64 k) {
    in.emplace(k);
  }

  inline void erase(int64 k) {
    out.emplace(k);
    while(out.size() && in.top() == out.top()) {
      in.pop();
      out.pop();
    }
  }

  inline int64 top2() {
    if(in.empty()) return -infll;
    int64 top = in.top();
    erase(top);
    int64 top2 = this->top();
    in.push(top);
    return top2;
  }
};

template< typename T >
struct edge {
  int src, to;
  T cost;
  int idx;

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

int main() {

  using Key = int64;

  struct Sum {
    int64 all;
    int64 p_len, c_len;
    int64 diameter;

    PQ md1, md2;

    Sum() : all(0), p_len(-infll), c_len(-infll), diameter(-infll) {}


    void toggle() {
      swap(p_len, c_len);
    }

    void merge(Key key, const Sum &parent, const Sum &child) {
      bool sw = false;
      if(key == infll) {
        sw = true;
        key = 0;
      }

      all = parent.all + key + child.all;
      int64 top = md1.top();
      p_len = max(child.p_len, max(top, parent.p_len) + key + child.all);
      c_len = max(parent.c_len, max(top, child.c_len) + key + parent.all);
      diameter = max({parent.diameter, child.diameter, top + key + md1.top2(), md2.top()});
      diameter = max({diameter, parent.p_len + key + max(child.c_len, top), child.c_len + key + top});
      if(sw) {
        p_len = max(p_len, key + child.all);
        c_len = max(c_len, key + parent.all);
        diameter = max(diameter, max({parent.p_len, child.c_len, top, 0LL}) + key);
      }

      if(p_len < -infll2) p_len = -infll;
      if(c_len < -infll2) c_len = -infll;
      if(diameter < -infll2) diameter = -infll;
    }

    void add(const Sum &ch) {
      md1.insert(ch.c_len);
      md2.insert(ch.diameter);
    }

    void erase(const Sum &ch) {
      md1.erase(ch.c_len);
      md2.erase(ch.diameter);
    }
  } e;

  int64 N, Q, W;
  cin >> N >> Q >> W;
  using LCT = LinkCutTreeSubtree< Sum, int64 >;
  LCT lct(e);
  vector< LCT::Node * > vv(N), ee(N);
  for(int i = 0; i < N; i++) {
    vv[i] = lct.make_node(infll);
  }
  WeightedGraph< int64 > g(N);
  for(int i = 1; i < N; i++) {
    int64 a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
    g[a].back().idx = i - 1;
    g[b].back().idx = i - 1;
  }

  vector< LCT::Node * > ptr(N);
  auto rec = MFP([&](auto rec, int idx, int par) -> void {
    for(auto &to : g[idx]) {
      if(to != par) {
        ee[to] = lct.make_node(to.cost);
        ptr[to.idx] = ee[to];
        lct.link(vv[to], ee[to]);
        lct.link(ee[to], vv[idx]);
        rec(to, idx);
      }
    }
  });
  rec(0, -1);
  int64 last = 0;

  while(Q--) {
    int64 D, E;
    cin >> D >> E;
    D = (D + last) % (N - 1);
    E = (E + last) % W;
    lct.set_key(ptr[D], E);
    auto ret = ptr[D]->sum.diameter;
    last = ret;
    cout << ret << endl;
  }
}