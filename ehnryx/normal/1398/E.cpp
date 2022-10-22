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

const int N = 2e5 + 7;

struct node; using pn = node*;
struct node { pn l, r, p; int key, cnt; ll val, acc;
  node(int k=0, ll v=0);
  inline int dir() { return this == p->r; }
  inline void setc(pn c, bool right) { (right?r:l) = c; c->p = this; }
} dat[N]; // nil = dat[0]
pn nil=[](){pn x=dat; x->l=x->r=x->p=x; x->acc=0; x->cnt=0; return x;}();
node::node(int k, ll v): l(nil), r(nil), p(nil),
  key(k), cnt(1), val(v), acc(v) {}
int nodeid = 0; template <class... T> pn new_node(T&& ...args) {
  return &(dat[++nodeid] = node(forward<T>(args)...)); }

namespace SplayTree {
inline void pull(pn x) { if (x != nil) {
  x->cnt = 1 + x->l->cnt + x->r->cnt;
  x->acc = x->l->acc + x->val + x->r->acc; } }
inline void rot(pn x) { pn p = x->p; bool d=x->dir();
  p->setc(d ? x->l : x->r, d); p->p->setc(x, p->dir()); x->setc(p, !d);
  pull(p); pull(x); }
pn splay(pn x, pn to=nil) { if (x!=nil) { while (x->p!=to) {
  if (x->p->p!=to) rot(x->dir() == x->p->dir() ? x->p : x); rot(x); } }
  return x; }
pn del(pn y) { pn x=splay(y)->r; if (x==nil) x=y->l; else {
  while (x->l != nil) x = x->l; splay(x,y)->setc(y->l,0); }
  x->p=nil; pull(x); return x; }
pn insert(pn c, pn x) { if (splay(c)==nil) return x; ll k=x->key; pn p;
  while (c!=nil) { p=c; c=(p->key>k?p->l:p->r); }
  p->setc(x,p->key<=k); return splay(x); }
int idx(pn x) { return splay(x)->l->cnt; } // rank; for sz, remove '->l'
pn nth(pn c, int n) {splay(c); while(c!=nil) { int l=c->l->cnt;
  if (n==l) break; if (n < l) c = c->l; else n = n-l-1, c = c->r; }
  return c; }
pn prv(pn x) { if (splay(x)->l == nil) return nil; x = x->l;
  while (x->r != nil) x = x->r; return x; }
pn nxt(pn x) { if (splay(x)->r == nil) return nil; x = x->r;
  while (x->l != nil) x = x->l; return x; }
pn range(pn c, pn l, pn r) { if (l == nil) {
  if (r == nil) return splay(c); return splay(r)->l; }
  if (l == r) return nil; splay(l);
  if (r == nil) return l->r; return splay(r,l)->l;}
ll rQuery(pn c, pn l, pn r) { return range(c, l, r)->acc; }
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

  int n;
  cin >> n;

  map<pair<int,int>,pn> light, fire;
  pn root = SplayTree::insert(nil, new_node(0, 0));

  ll ans = 0;
  for(int bs=0; bs<n; bs++) {
    int t, d;
    cin >> t >> d;
    ans += d;

    if(d > 0) {
      pn cur = new_node(-d, d);
      if(t == 0) {
        fire[make_pair(d, bs)] = cur;
      } else {
        light[make_pair(d, bs)] = cur;
      }
      root = SplayTree::insert(root, cur);
    } else {
      if(t == 0) {
        auto it = fire.lower_bound(make_pair(-d, -1));
        root = SplayTree::del(it->second);
        fire.erase(it);
      } else {
        auto it = light.lower_bound(make_pair(-d, -1));
        root = SplayTree::del(it->second);
        light.erase(it);
      }
    }

    if(light.empty()) {
      cout << ans << nl;
    } else {
      pn r = SplayTree::nth(root, light.size());
      ll add = SplayTree::rQuery(root, nil, r);
      if(SplayTree::idx(light.begin()->second) < SplayTree::idx(r)) {
        add -= light.begin()->first.first;
        add += r->val;
        r = SplayTree::nxt(r);
      }
      if(fire.empty()) {
        r = SplayTree::prv(r);
        add -= r->val;
      } else if(SplayTree::idx(fire.rbegin()->second) >= SplayTree::idx(r)) {
        r = SplayTree::prv(r);
        add -= r->val;
        add += fire.rbegin()->first.first;
      }
      cout << ans + add << nl;
    }
  }

  return 0;
}