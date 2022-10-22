#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<18;

struct node; using pn = node*;
struct node { pn l, r, p; ll key, val, cnt, lazy, acc;
  node() = default; node(ll k, ll v);
  inline int dir() { return this == p->r; }
  inline void setc(pn c, bool right) { (right?r:l) = c; c->p = this; }
} dat[2*N];
pn nil=[](){pn x=dat; x->l=x->r=x->p=x;x->acc=0;return x;}();
node::node(ll k, ll v): l(nil), r(nil), p(nil),
  key(k), val(v), cnt(1), lazy(0), acc(v) {}
int nodeid = 0; template <class... T> pn new_node(T&& ...args) {
  return &(dat[++nodeid] = node(forward<T>(args)...)); }

namespace SplayTree {
//%%== Code for upwards propagating property (eg. count, min)
inline void pull(pn x) { if (x != nil) {
  x->cnt = 1 + x->l->cnt + x->r->cnt;
	x->acc = x->l->acc + x->val + x->r->acc; } }
//%%== Code for lazy propagating property (eg. reverse subtree, add)
inline void modifyNode(pn x, ll v) { if (x != nil) {
	x->val += v; x->acc += v * x->cnt; x->lazy += v; } }
inline void push(pn x) {
  modifyNode(x->l, x->lazy); modifyNode(x->r, x->lazy); x->lazy=0;
}
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
ll pQuery(pn x) { return splay(x)->val; }
ll rQuery(pn c, pn l, pn r) { return range(c, l, r)->acc; }
void pUpdate(pn x, ll v) { splay(x)->val += v; pull(x); }          //RMQ
void rUpdate(pn c, pn l, pn r, ll v) {
  pn u = range(c, l, r); modifyNode(u, v); splay(u); }
//%%== Rope operations: split and merge, nil = right end
pn splitBefore(pn x) { if (splay(x)==nil) return nil;
  push(x); if (x->l!=nil) push(x->l);
  pn ret=x->l; x->l=x->l->p=nil; pull(ret); pull(x); return ret; }
pn append(pn l, pn r) { if (splay(l) == nil) return r;
  if (splay(r) == nil) return l; pn x = splay(last(l)); push(x);
  push(r); x->setc(r,1); pull(x->r); pull(x); return x; } }

struct SegTree {
	ll st[2*N], z[2*N];
	SegTree() {
		memset(st,0,sizeof st);
		memset(z,0,sizeof z);
	}

	void push(int i) {
		if(z[i]) {
			st[2*i] += z[i]/2;
			st[2*i+1] += z[i]/2;
			z[2*i] += z[i]/2;
			z[2*i+1] += z[i]/2;
			z[i] = 0;
		}
	}

	void pull(int i) {
		st[i] = st[2*i] + st[2*i+1];
	}

	void insert(int l, int r) {
		if(l <= r) insert(l,r,1,0,N-1);
	}
	void insert(int l, int r, int i, int s, int e) {
		if(r<s || e<l) return;
		if(l<=s && e<=r) {
			st[i] += e-s+1;
			z[i] += e-s+1;
			return;
		}
		push(i);
		int m = (s+e)/2;
		insert(l,r,2*i,s,m);
		insert(l,r,2*i+1,m+1,e);
		pull(i);
	}

	ll query(int l, int r) {
		if(l <= r) return query(l,r,1,0,N-1);
		else return 0;
	}
	ll query(int l, int r, int i, int s, int e) {
		if(r<s || e<l) return 0;
		if(l<=s && e<=r) {
			return st[i];
		}
		push(i);
		int m = (s+e)/2;
		return query(l,r,2*i,s,m) + query(l,r,2*i+1,m+1,e);
	}
};

SegTree lval, rval;

int search(int l, int r) {
	//cerr<<"search on "<<l<<" "<<r<<nl;
	while(l<r) {
		int m = (l+r)/2;
		int lv = lval.query(m, m);
		int rv = rval.query(m, m);
		//cerr<<"query "<<m<<" -> "<<lv<<" vs "<<rv<<nl;
		if(lv == rv) return m;
		if(lv > rv) {
			l = m+1;
		} else {
			r = m;
		}
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector<pair<int,int>> vals;
	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;
		vals.push_back(make_pair(a, i));
	}
	sort(vals.begin(), vals.end());

	ll inv = 0;
	int lb = INF;
	int rb = -INF;
	node* lroot = nil;
	node* rroot = nil;
	for(int i=0; i<n; i++) {
		int pos = vals[i].second;

		lroot = SplayTree::insert(lroot, new_node(pos, lval.query(pos, pos)));
		rroot = SplayTree::insert(rroot, new_node(pos, rval.query(pos, pos)));
		inv += i - SplayTree::idx(lroot);

		lval.insert(1, pos-1);
		rval.insert(pos+1, n);
		SplayTree::rUpdate(lroot, nil, lroot, 1);
		SplayTree::rUpdate(rroot, rroot, nil, 1);

		// left and right
		lb = min(lb, pos);
		rb = max(rb, pos);
		int m = search(1, n);
		ll left = rval.query(lb, m-1);
		ll right = lval.query(m, rb);
		ll lrem = SplayTree::rQuery(rroot, nil, SplayTree::lowerBound(rroot, m));
		ll rrem = SplayTree::rQuery(lroot, SplayTree::prv(SplayTree::lowerBound(lroot, m)), nil);
		//cerr<<"query "<<lb<<" "<<m<<" "<<rb<<nl;
		//cerr<<"got "<<m<<" -> "<<lval.query(m,m)<<" "<<rval.query(m,m)<<nl;
		//cerr<<"left,right,inv,rem = "<<left<<" "<<right<<" "<<inv<<" "<<lrem<<" "<<rrem<<nl;
		cout << left + right + inv - lrem - rrem << " ";
		//cerr<<nl;
	}
	cout << nl;

	return 0;
}