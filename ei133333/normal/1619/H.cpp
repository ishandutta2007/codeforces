#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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

struct LinkCutTree {

  struct Node {
    Node *l, *r, *p;
    int idx;

    bool rev;
    int sz;

    bool is_root() {
      return !p || (p->l != this && p->r != this);
    }

    Node(int idx) :
        idx(idx), sz(1), l(nullptr), r(nullptr), p(nullptr), rev(false) {}
  };

  LinkCutTree() = default;

  Node *make_node(int idx) {
    return new Node(idx);
  }


  void toggle(Node *t) {
    assert(t);
    swap(t->l, t->r);
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
    for(Node *cur = t; cur; cur = cur->p) {
      splay(cur);
      cur->r = rp;
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

  vector< int > get_path(Node *x) {
    vector< int > vs;
    function< void(Node *) > dfs = [&](Node *cur) {
      if(!cur) return;
      push(cur);
      dfs(cur->r);
      vs.push_back(cur->idx);
      dfs(cur->l);
    };
    expose(x);
    dfs(x);
    return vs;
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
  int N, Q;
  cin >> N >> Q;
  vector< int > P(N);
  cin >> P;
  for(auto &p: P) --p;

  LinkCutTree lct;
  vector< LinkCutTree::Node * > vs(N);
  map< int, int > uku;
  for(int i = 0; i < N; i++) {
    vs[i] = lct.make_node(i);
  }
  for(int i = 0; i < N; i++) {
    if(lct.get_root(vs[i]) == lct.get_root(vs[P[i]])) {
      uku[i] = P[i];
    } else {
      lct.evert(vs[i]);
      lct.link(vs[i], vs[P[i]]);
    }
  }
  for(int i = 0; i < Q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    --a;
    if(t == 1) {
      --b;
      if(uku.count(a) and uku[a] == P[a]) {
        uku.erase(a);
      } else {
        lct.cut(vs[a]);
        auto p = lct.get_root(vs[P[a]])->idx;
        if(uku.count(p) and lct.get_root(vs[p]) != lct.get_root(vs[uku[p]])) {
          lct.link(vs[p], vs[uku[p]]);
          uku.erase(p);
        }
      }
      if(uku.count(b) and uku[b] == P[b]) {
        uku.erase(b);
      } else {
        lct.cut(vs[b]);
        auto p = lct.get_root(vs[P[b]])->idx;
        if(uku.count(p) and lct.get_root(vs[p]) != lct.get_root(vs[uku[p]])) {
          lct.link(vs[p], vs[uku[p]]);
          uku.erase(p);
        }
      }
      swap(P[a], P[b]);
      if(lct.get_root(vs[a]) == lct.get_root(vs[P[a]])) {
        uku[a] = P[a];
      } else {
        lct.evert(vs[a]);
        lct.link(vs[a], vs[P[a]]);
      }
      if(lct.get_root(vs[b]) == lct.get_root(vs[P[b]])) {
        uku[b] = P[b];
      } else {
        lct.evert(vs[b]);
        lct.link(vs[b], vs[P[b]]);
      }
    } else {
      lct.expose(vs[a]);
      int root_dist = vs[a]->sz - 1;
      int root = lct.get_root(vs[a])->idx;
      assert(uku.count(root));
      lct.expose(vs[uku[root]]);
      int loop_dist = vs[uku[root]]->sz;
      if(b <= root_dist) {
        cout << lct.get_kth(vs[a], b)->idx + 1 << "\n";
      } else {
        b -= root_dist + 1;
        b %= loop_dist;
        cout << lct.get_kth(vs[uku[root]], b)->idx + 1 << "\n";
      }
    }
  }
}