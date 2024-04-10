//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

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

const int N = 2e5 + 7;

struct node; using pn = node*;
struct node { pn p, l, r; int key, val, cnt, acc; bool rev, lazy;
  node(int k=0, int v=0);
  inline int dir() { return this == p->r; }
  inline void setc(pn c, bool right) { (right?r:l) = c; c->p = this; }
} dat[N]; // nil = dat[0]
pn nil=[](){pn x=dat; x->l=x->r=x->p=x; x->key=-1; x->acc=0; x->cnt=0; return x;}();
node::node(int k, int v): p(nil), l(nil), r(nil),
  key(k), val(v), cnt(1), acc(1<<v), rev(0), lazy(false) {}
int nodeid = 0; template <class... T> pn new_node(T&& ...args) {
  return &(dat[++nodeid] = node(forward<T>(args)...)); }

namespace SplayTree {
//%%== Code for upwards propagating property (eg. count, min)
  inline void pull(pn x) { if (x != nil) {
    x->cnt = 1 + x->l->cnt + x->r->cnt;
    x->acc = x->l->acc | 1 << x->val | x->r->acc; } }
  //%%== Code for lazy propagating property (eg. reverse subtree, add)
  void rev(pn x) { if (x != nil) { x->rev ^= 1; swap(x->l, x->r); } }
  inline void modifyNode(pn x) { if (x != nil) {
    if(__builtin_popcount(x->acc) == 1) x->acc ^= 0b11;
    x->val ^= 1; x->lazy ^= true; } }
  inline void push(pn x) {
    if (x->rev) { rev(x->l); rev(x->r); x->rev=0; }
    if(x->lazy) { modifyNode(x->l); modifyNode(x->r); x->lazy = 0; } }
  pn pushTo(pn c) { if (c->p != nil) pushTo(c->p); push(c); return c; }
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
  //%%== Iterator-based access, returns nil when iterator exhausted
  pn nxt(pn x) { if (splay(x)->r == nil) return nil; x = x->r;
    while (push(x), x->l != nil) x = x->l; return x; }
  pn last(pn c) { if (splay(c) != nil)
    while (push(c), c->r != nil) c=c->r; return splay(c); }
  //%%== Utility code (rank, nth order statistic; requires cnt maintained)
  int idx(pn x) { return splay(x)->l->cnt; } // rank; for sz, remove '->l'
  pn nth(pn c, int n) {splay(c); while(c!=nil) { push(c); int l=c->l->cnt;
    if (n==l) break; if (n < l) c = c->l; else n = n-l-1, c = c->r; }
    return c; }
  //%%== Range query/update operations by iterator, range is EXCLUSIVE!
  pn range(pn c, pn l, pn r) { if (l == nil) {
    if (r == nil) return splay(c); return splay(r)->l; }
    if (l == r) return nil; splay(l);
    if (r == nil) return l->r; return splay(r,l)->l;}
  int pQuery(pn x) { return splay(x)->val; }
  pn find(pn c, int v) {
    while(c!=nil && (push(c), (c->acc & 1<<v))) {
      if(c->val == v) return c;
      c = (c->l->acc & 1<<v) ? c->l : c->r;
    }
    return nil;
  }
  //%%== Rope operations: split and merge, nil = right end
  pn append(pn l, pn r) { if (splay(l) == nil) return r;
    if (splay(r) == nil) return l; pn x = splay(last(l)); push(x);
    push(r); x->setc(r,1); pull(x->r); pull(x); return x; }
}

using namespace SplayTree;

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    pn ref = nil;
    for(int i=0; i<n; i++) {
      ref = append(ref, new_node(i, s[i] - '0'));
    }

    vector<int> ans;
    for(int i=n; i>0; i--) {
      if(pQuery(nth(ref, i-1)) + '0' == t[i-1]) continue;
      pn j = find(range(ref, nil, nth(ref, i)), t[i-1] - '0');
      if(j != nil) {
        ans.push_back(idx(j) + 1);
        pn c = range(ref, nil, nxt(j));
        rev(c);
        modifyNode(c);
        splay(c);
      }
      ans.push_back(i);
      pn c = range(ref, nil, nth(ref, i));
      rev(c);
      modifyNode(c);
      splay(c);
    }

    cout << ans.size() << " ";
    for(int it : ans) {
      cout << it << " ";
    }
    cout << nl;
  }

  return 0;
}