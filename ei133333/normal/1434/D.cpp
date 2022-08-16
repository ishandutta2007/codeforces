#include <bits/stdc++.h>
 
using namespace std;
 
using int64 = long long;
const int mod = 998244353;
 
const int64 infll = (1LL << 60) - 1;
const int inf = (1 << 28) - 1;
 
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
 
template< class T, size_t V >
struct ArrayPool {
  array< T, V > pool;
  array< T *, V > stock;
  int ptr;
 
  ArrayPool() { clear(); }
 
  inline T *alloc() {
    return stock[--ptr];
  }
 
  inline void free(T *t) {
    stock[ptr++] = t;
  }
 
  void clear() {
    ptr = (int) pool.size();
    for(int i = 0; i < pool.size(); i++) stock[i] = &pool[i];
  }
};
 
template< typename key_t, size_t V >
struct SplayTree {
 
  const key_t e;
 
  SplayTree(const key_t &e) : pool(), e(e) {}
 
  struct Node {
    Node *l, *r, *p;
    key_t key, sum;
 
    Node() = default;
 
    Node(const key_t &k) : key(k), sum(k), l(nullptr), r(nullptr), p(nullptr) {}
  };
 
  ArrayPool< Node, V > pool;
 
 
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
 
  inline key_t sum(const Node *t) const {
    return t ? t->sum : e;
  }
 
  void update(Node *t) {
    t->sum = sum(t->l) * t->key * sum(t->r);
  }
 
  Node *get_left(Node *t) const {
    while(t->l) t = t->l;
    return t;
  }
 
  Node *get_right(Node *t) const {
    while(t->r) t = t->r;
    return t;
  }
 
  inline Node *alloc(const key_t &v) {
    return &(*pool.alloc() = Node(v));
  }
 
  void splay(Node *t) {
    while(t->p) {
      auto *q = t->p;
      if(!q->p) {
        if(q->l == t) rotr(t);
        else rotl(t);
      } else {
        auto *r = q->p;
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
 
  Node *push_back(Node *t, const key_t &v) {
    if(!t) {
      t = alloc(v);
      return t;
    } else {
      Node *cur = get_right(t), *z = alloc(v);
      z->p = cur;
      cur->r = z;
      update(cur);
      splay(z);
      return z;
    }
  }
 
  Node *erase(Node *t) {
    splay(t);
    Node *x = t->l, *y = t->r;
    pool.free(t);
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
      update(t);
    }
    return t;
  }
};
 
struct U {
  int x0, y0; // top2 
  int x1, y1;
  int z;    // sub_tree_ans
 
  U operator*(U p) const {
    if(x0 > p.x0) {
      p.y0 = p.x0;
      p.x0 = x0;
      if(y0 > p.y0) {
        p.y0 = y0;
      }
    } else if(x0 > p.y0) {
      p.y0 = x0;
    }
 
    if(x1 > p.x1) {
      p.y1 = p.x1;
      p.x1 = x1;
      if(y1 > p.y1) {
        p.y1 = y1;
      }
    } else if(x1 > p.y1) {
      p.y1 = x1;
    }
 
    if(z > p.z) {
      p.z = z;
    }
    return p;
  }
 
  U() : x0(-inf), y0(-inf), x1(-inf), y1(-inf), z(-inf) {}
 
  U(int x0, int y0, int x1, int y1, int z) : x0(x0), y0(y0), x1(x1), y1(y1), z(z) {}
};
 
template< typename SUM, typename KEY, size_t V >
struct LinkCutTreeSubtree {
 
 
  struct Node {
    Node *l, *r, *p;
 
    typename SplayTree< U, V >::Node *light, *belong;
    KEY key;
    SUM sum;
    int sz;
 
    Node() = default;
 
    bool is_root() const {
      return !p || (p->l != this && p->r != this);
    }
 
    Node(const KEY &key, const SUM &sum) :
        key(key), sum(sum), sz(1), belong(nullptr),
        l(nullptr), r(nullptr), p(nullptr), light(nullptr) {}
  };
 
  using ST = SplayTree< U, V >;
 
  ST st;
  const SUM ident;
  ArrayPool< Node, V > pool;
 
  LinkCutTreeSubtree(const SUM &ident) : ident(ident), st(U()), pool() {}
 
  Node *alloc(const KEY &key) {
    auto ret = &(*pool.alloc() = Node(key, ident));
    update(ret);
    return ret;
  }
 
  Node *set_key(Node *t, const KEY &key) {
    expose(t);
    t->key = key;
    update(t);
    return t;
  }
 
  void update(Node *t) {
    t->sz = 1;
    if(t->l) t->sz += t->l->sz;
    if(t->r) t->sz += t->r->sz;
    t->sum.merge(t->key, t->l ? t->l->sum : ident, t->r ? t->r->sum : ident, st.sum(t->light));
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
 
    Node *rot = t;
    while(!rot->is_root()) rot = rot->p;
    t->belong = rot->belong;
    if(t != rot) rot->belong = nullptr;
 
    while(!t->is_root()) {
      auto *q = t->p;
      if(q->is_root()) {
        if(q->l == t) rotr(t);
        else rotl(t);
      } else {
        auto *r = q->p;
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
      if(cur->r) {
        cur->light = st.push_back(cur->light, U(cur->r->sum.c_len0, -inf, cur->r->sum.c_len1, -inf, cur->r->sum.diameter));
        cur->r->belong = cur->light;
      }
      cur->r = rp;
      if(cur->r) {
        cur->light = st.erase(cur->r->belong);
      }
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
 
 
int main() {
 
 
  using Key = int;
 
  struct Sum {
    int all;
    bool all_type;
    int p_len0, c_len0;
    int p_len1, c_len1;
    int diameter;
 
    Sum() : all(0), all_type(false), p_len0(-inf), c_len0(-inf), p_len1(-inf), c_len1(-inf), diameter(-inf) {}
 
    void merge(Key key, const Sum &parent, const Sum &child, const U &t) {
      bool sw = false;
 
      if(key == inf) {
        sw = true;
        key = 0;
      }
 
      all = parent.all + (!sw) + child.all;
      all_type = child.all_type ^ key ^ parent.all_type;
 
      if(child.all_type ^ key) {
        p_len0 = max(child.p_len0, max(t.x1, parent.p_len1) + (!sw) + child.all);
        p_len1 = max(child.p_len1, max(t.x0, parent.p_len0) + (!sw) + child.all);
      } else {
        p_len0 = max(child.p_len0, max(t.x0, parent.p_len0) + (!sw) + child.all);
        p_len1 = max(child.p_len1, max(t.x1, parent.p_len1) + (!sw) + child.all);
      }
 
      if(parent.all_type ^ key) {
        c_len0 = max(parent.c_len0, max(t.x1, child.c_len1) + (!sw) + parent.all);
        c_len1 = max(parent.c_len1, max(t.x0, child.c_len0) + (!sw) + parent.all);
      } else {
        c_len0 = max(parent.c_len0, max(t.x0, child.c_len0) + (!sw) + parent.all);
        c_len1 = max(parent.c_len1, max(t.x1, child.c_len1) + (!sw) + parent.all);
      }
 
 
      diameter = max({parent.diameter, child.diameter, t.z});
      if(key) {
        diameter = max({diameter, parent.p_len0 + (!sw) + max(child.c_len1, t.x1), child.c_len0 + (!sw) + t.x1});
        diameter = max({diameter, parent.p_len1 + (!sw) + max(child.c_len0, t.x0), child.c_len1 + (!sw) + t.x0});
      } else {
        diameter = max({diameter, parent.p_len0 + (!sw) + max(child.c_len0, t.x0), child.c_len0 + (!sw) + t.x0});
        diameter = max({diameter, parent.p_len1 + (!sw) + max(child.c_len1, t.x1), child.c_len1 + (!sw) + t.x1});
        diameter = max({diameter, t.x0 + (!sw) + t.y0, t.x1 + (!sw) + t.y1});
      }
 
 
      if(sw) {
        if(child.all_type) p_len1 = max(p_len1, child.all);
        else p_len0 = max(p_len0, child.all);
        if(parent.all_type) c_len1 = max(c_len1, parent.all);
        else c_len0 = max(c_len0, parent.all);
        diameter = max({diameter, parent.p_len0, child.c_len0, t.x0, 0});
      }
    }
  } e;
 
 
  using LCT = LinkCutTreeSubtree< Sum, Key, 1000000 >;
 
 
  int N;
  cin >> N;
  LCT lct(e);
  vector< LCT::Node * > vv(N), ee(N);
  for(int i = 0; i < N; i++) {
    vv[i] = lct.alloc(inf);
  }
  vector< int > S(N), T(N), P(N);
  vector< vector< pair< int, int > > > g(N);
  for(int i = 1; i < N; i++) {
    cin >> S[i] >> T[i] >> P[i];
    --S[i], --T[i];
    g[S[i]].emplace_back(T[i], i);
    g[T[i]].emplace_back(S[i], i);
  }
  function< void(int, int) > dfs = [&](int idx, int par) {
    for(auto &to : g[idx]) {
      if(to.first == par) continue;
      ee[to.second] = lct.alloc(P[to.second]);
      lct.link(vv[to.first], ee[to.second]);
      lct.link(ee[to.second], vv[idx]);
      dfs(to.first, idx);
    }
  };
  dfs(0, -1);
 
  int M;
  cin >> M;
  while(M--) {
    int x;
    cin >> x;
    lct.set_key(ee[x], ee[x]->key ^ 1);
    cout << max(0, ee[x]->sum.diameter) << "\n";
  }
}