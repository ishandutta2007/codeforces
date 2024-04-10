//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 1;

struct node; using pn = node*;
struct node { pn l, r, p; int key, cnt; pair<int,int> val, acc; // val, key
  node(ll k=0, ll v=0);
  inline int dir() { return this == p->r; }
  inline void setc(pn c, bool right) { (right?r:l) = c; c->p = this; }
} dat[N]; // nil = dat[0]
pn nil=[](){pn x=dat; x->l=x->r=x->p=x; x->acc = make_pair(-INF, 0);
  x->cnt=0; return x;}();
node::node(ll k, ll v): l(nil), r(nil), p(nil),
  key(k), val(v, k), cnt(1), acc(v, k) {}
int nodeid = 0; template <class... T> pn new_node(T&& ...args) {
  return &(dat[++nodeid] = node(forward<T>(args)...)); }

namespace SplayTree {
//%%== Code for upwards propagating property (eg. count, min)
inline void pull(pn x) { if (x != nil) {
  x->cnt = 1 + x->l->cnt + x->r->cnt;
  x->acc = max(x->l->acc, max(x->val, x->r->acc)); } }
//%%== Code for lazy propagating property (eg. reverse subtree, add)
inline void push(pn x) { }
//%%== Core splay tree code (rotate, splay, delete)
inline void rot(pn x) { pn p = x->p; push(p); push(x); bool d=x->dir();
  p->setc(d ? x->l : x->r, d); p->p->setc(x, p->dir()); x->setc(p, !d);
  pull(p); pull(x); }
// splays node x until it is a child of node to
pn splay(pn x, pn to=nil) { if (x!=nil) { while (x->p!=to) {
  if (x->p->p!=to) rot(x->dir() == x->p->dir() ? x->p : x); rot(x); } }
  return x; }
pn del(pn y) { pn x=splay(y)->r; if (x==nil) x=y->l; else {
  while (push(x), x->l != nil) x = x->l; splay(x,y)->setc(y->l,0); }
  x->p=nil; pull(x); return x; }
//%%== BST methods (lb, find, insert) (conflicts with other features)
pn lb(pn c, ll k) { if (c == nil) return c; // c MUST BE THE ROOT
  push(c); if (c->key>=k) { pn l=lb(c->l,k); return l==nil?c:l; }
  return lb(c->r,k); }
pn lowerBound(pn ref, ll k) { return lb(splay(ref), k); }
pn find(pn c, ll k) { c=lb(splay(c),k); return c->key!=k?nil:splay(c); }
pn insert(pn c, pn x) { if (splay(c)==nil) return x; ll k=x->key; pn p;
  while (c!=nil) { push(c); p=c; c=(p->key>k?p->l:p->r); }
  p->setc(x,p->key<=k); return splay(x); }
//%%== Utility code (rank, nth order statistic; requires cnt maintained)
int idx(pn x) { return splay(x)->l->cnt; } // rank; for sz, remove '->l'
pn nth(pn c, int n) {splay(c); while(c!=nil) { push(c); int l=c->l->cnt;
  if (n==l) break; if (n < l) c = c->l; else n = n-l-1, c = c->r; }
  return c; }
//%%== Iterator-based access, returns nil when iterator exhausted
pn first(pn c) { if (splay(c) != nil)
  while (push(c), c->l != nil) c=c->l; return splay(c); }
pn last(pn c) { if (splay(c) != nil)
  while (push(c), c->r != nil) c=c->r; return splay(c); }
pn prv(pn x) { if (splay(x)->l == nil) return nil; x = x->l;
  while (push(x), x->r != nil) x = x->r; return x; }
pn nxt(pn x) { if (splay(x)->r == nil) return nil; x = x->r;
  while (push(x), x->l != nil) x = x->l; return x; }
//%%== Iterator-based insert, does NOT work with BST unless key sorted
pn insertBefore(pn c, pn at, pn x) { // to insert "last", use at=nil
  if (at==nil) { if (splay(c)!=nil) last(c)->setc(x,1); }
  else { pn p=prv(at); if (p==nil) at->setc(x,0); else p->setc(x,1); }
  return splay(x); }
//%%== Range query/update operations by iterator, range is EXCLUSIVE!
pn range(pn c, pn l, pn r) { if (l == nil) {
  if (r == nil) return splay(c); return splay(r)->l; }
  if (l == r) return nil; splay(l);
  if (r == nil) return l->r; return splay(r,l)->l;}
pair<int,int> rQuery(pn c, pn l, pn r) { return range(c, l, r)->acc; }
void pUpdate(pn x, ll v) { splay(x)->val.first = v; pull(x); }
//%%== Rope operations: split and merge, nil = right end
pn splitBefore(pn x) { if (splay(x)==nil) return nil;
  push(x); if (x->l!=nil) push(x->l);
  pn ret=x->l; x->l=x->l->p=nil; pull(ret); pull(x); return ret; }
pn append(pn l, pn r) { if (splay(l) == nil) return r;
  if (splay(r) == nil) return l; pn x = splay(last(l)); push(x);
  push(r); x->setc(r,1); pull(x->r); pull(x); return x; }
}

int dsu[N];
int find(int i) {
  if(dsu[i] == 0) return i;
  return dsu[i] = find(dsu[i]);
}
int link(int i, int j) {
  i = find(i);
  j = find(j);
  if(i == j) return 0;
  dsu[i] = j;
  return 1;
}

vector<int> adj[N];
bool alive[N];
bool vis[N];
int sz[N];
pn node[N];

int sid = 0;
void build(int u, int p, pn root) {
  vis[u] = true;
  sz[u] = 1;
  node[u]->key = ++sid;
  root = SplayTree::append(root, node[u]);
  for(int v : adj[u]) {
    if(v == p) continue;
    build(v, u, root);
    sz[u] += sz[v];
  }
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m, q;
  cin >> n >> m >> q;
  for(int i=1; i<=n; i++) {
    int v;
    cin >> v;
    node[i] = new_node(i, v);
  }
  vector<pair<int,int>> edges(m+1);
  for(int i=1; i<=m; i++) {
    int a, b;
    cin >> a >> b;
    edges[i] = make_pair(a, b);
  }

  vector<pair<int,int>> queries;
  vector<int> order;
  vector<bool> have(m+1);
  while(q--) {
    int t, i;
    cin >> t >> i;
    queries.emplace_back(t, i);
    if(t == 2) {
      order.push_back(i);
      have[i] = true;
    }
  }
  for(int i=1; i<=m; i++) {
    if(!have[i]) order.push_back(i);
  }
  reverse(order.begin(), order.end());

  for(int e : order) {
    auto [a, b] = edges[e];
    if(link(a, b)) {
      alive[e] = true;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  for(int i=1; i<=n; i++) {
    if(!vis[i]) {
      build(i, 0, nil);
    }
  }

  for(auto [t, i] : queries) {
    if(t == 1) {
      auto [val, key] = SplayTree::rQuery(node[i], nil, nil);
      SplayTree::pUpdate(node[key], 0);
      cout << val << nl;
    } else if(alive[i]) {
      auto [a, b] = edges[i];
      if(node[a]->key > node[b]->key) swap(a, b);
      pn left = SplayTree::splitBefore(node[b]);
      pn right = SplayTree::lowerBound(node[b], node[b]->key + sz[b]);
      SplayTree::splitBefore(right);
      SplayTree::append(left, right);
    }
  }

  return 0;
}