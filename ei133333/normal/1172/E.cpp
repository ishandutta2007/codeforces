#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 60) - 1;
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


int main() {
  struct tap {
    int64 sz, szsum, cashsz, cashszsum;

    tap() : sz(0), szsum(0), cashsz(0), cashszsum(0) {}


    void merge(int64 key, const tap &parent, const tap &child) {
      szsum = cashszsum;
      szsum += parent.sz * parent.sz;
      szsum += child.sz * child.sz;

      sz = key;
      sz += parent.sz;
      sz += child.sz;
      sz += cashsz;
    }

    void toggle() {
    }

    void add(const tap &child) {
      cashszsum += child.sz * child.sz;
      cashsz += child.sz;
    }

    void erase(const tap &child) {
      cashszsum -= child.sz * child.sz;
      cashsz -= child.sz;
    }
  } e;

  int N, M;
  cin >> N >> M;
  vector< int > C(N);
  cin >> C;

  using pi = pair< int64, int >;

  using LCT = LinkCutTreeSubtree< tap, int64 >;
  LCT lct(e);
  vector< LCT::Node * > sub(N);
  vector< map< int, vector< pair< int, int > > > > belong(N + 1);
  for(int i = 0; i < N; i++) {
    --C[i];
    sub[i] = lct.make_node(1);
    belong[C[i]][-1].emplace_back(i, 0);
  }

  vector< int > parent(N + 1, -1);
  vector< int > g[400001];

  g[N].emplace_back(0);
  sub.emplace_back(lct.make_node(1));

  function< void(int, int) > dfs = [&](int idx, int par) {
    parent[idx] = par;
    for(auto &to : g[idx]) {
      if(to == par) continue;
      dfs(to, idx);
    }
  };
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    lct.evert(sub[y]);
    lct.link(sub[y], sub[x]);
  }
  lct.evert(sub[0]);
  lct.link(sub[0], sub[N]);
  dfs(N, -1);

  for(int i = 0; i < M; i++) {
    int u, x;
    cin >> u >> x;
    --u, --x;
    if(C[u] != x) {
      belong[C[u]][i].emplace_back(u, 1); // set black
      C[u] = x;
      belong[x][i].emplace_back(u, 0); // set white
    }
  }


  vector< int64 > ans(M + 1);


  for(int i = 0; i < N; i++) {

    int last = -1;
    int64 path = 1LL * N * N;

    set< int > st;

    for(auto &vs : belong[i]) {
      ans[last + 1] += path;
      ans[vs.first + 1] -= path;

      for(auto &p : vs.second) {
        if(!p.second) {
          st.emplace(p.first);
          path -= lct.query(lct.get_root(sub[p.first])).szsum;
          lct.cut(sub[p.first]);
          path += lct.query(lct.get_root(sub[parent[p.first]])).szsum;
          path += lct.query(lct.get_root(sub[p.first])).szsum;
        } else {
          st.erase(p.first);
          path -= lct.query(lct.get_root(sub[p.first])).szsum;
          path -= lct.query(lct.get_root(sub[parent[p.first]])).szsum;
          lct.link(sub[p.first], sub[parent[p.first]]);
          path += lct.query(lct.get_root(sub[p.first])).szsum;
        }
      }
      last = vs.first;
    }
    ans[last + 1] += path;
    for(auto &p : st) lct.link(sub[p], sub[parent[p]]);
  }

  int64 ret = 0;
  for(int j = 0; j <= M; j++) {
    ret += ans[j];
    cout << 1LL * N * N * N - ret << "\n";
  }
}