#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#define car first
#define cdr second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; t = x, x = y % x, y = t); return y; }

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph(int n) {adj.clear (); adj.resize (n + 5);}
  Graph() {adj.clear (); }
  void resize(int n) {adj.resize (n + 5); }
  void add(int s, edge e){adj[s].push_back (e);}
  void del(int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
  vector<edge>& operator [](int t) {return adj[t];}
};

const int maxn = 110000;

struct info {
	int size;
	int64 sum, val;
};
struct node {
	node *lc, *rc;
	info x;
};

node Tnull, *null = &Tnull;

info operator + (info l, info r)
{
	info t;
	t.size = l.size + r.size;
	t.sum  = l.sum + r.sum;
	t.val  = l.val + r.val + r.sum * l.size - l.sum * r.size;
	return t;
}

int64 x[maxn];
const int64 delta = 1ll << 48;

node *get_new()
{
	node *p = new node;
	p->lc = p->rc = null;
	p->x = (info){0, 0, 0};
	return p;
}

node *insert(node *t, node *v, int64 k, int d)
{
	if (t == null) t = get_new();
	if (d == -1) return v;
	if (~k >> d & 1) t->lc = insert(t->lc, v, k, d - 1);
	else t->rc = insert(t->rc, v, k, d - 1);
	t->x = t->lc->x + t->rc->x;
	return t;
}

node *erase(node *t, int64 k, int d)
{
	if (d == -1) return null;
	if (~k >> d & 1) t->lc = erase(t->lc, k, d - 1);
	else t->rc = erase(t->rc, k, d - 1);
	t->x = t->lc->x + t->rc->x;
	return t;
}

info query(int64 L, int64 R, node *t, int64 l, int64 r)
{
	if (t == null) return t->x;
	if (L <= l && r <= R) return t->x;
	int64 m = (l + r + 1) >> 1; info ret = (info){0};
	if (L < m) ret = ret + query(L, R, t->lc, l, m);
	if (m < R) ret = ret + query(L, R, t->rc, m, r);
	return ret;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("E.in" , "r", stdin);
	freopen("E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int n, m; 

	cin >> n;

	null->lc = null->rc = null;

	node *root = null;
	FOR (i, 1, n) {
		cin >> x[i];
		node *p = get_new();
		p->x = (info){1, x[i], 0};
		root = insert(root, p, x[i] + delta, 60);
	}

	cin >> m;
	FOR (i, 1, m) {
		int64 t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			root = erase(root, x[a] + delta, 60);
			x[a] += b;

			node *p = get_new();
			p->x = (info){1, x[a], 0};
			root = insert(root, p, x[a] + delta, 60);
		} else {
			info i = query(a + delta, b + delta + 1, root, 0, (1ll << 61));
			cout << i.val << endl;
		}
	}

	return 0; 
}