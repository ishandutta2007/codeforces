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
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

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

const int maxn = 131072;

int st[maxn << 1], x[maxn], y[maxn], a[maxn], b[maxn];

void cover(int l, int r, int v)
{
	for (l += maxn - 1, r += maxn + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if (~l & 1) st[l ^ 1] = v;
		if ( r & 1) st[r ^ 1] = v;
	}
}

int query(int x)
{
	int t = 0;
	for (x += maxn; x; x >>= 1)
		chkmax(t, st[x]);
	return t;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("E.in" , "r", stdin);
	freopen("E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	FOR (i, 1, n) {
		cin >> a[i];
	}
	FOR (i, 1, n) cin >> b[i];

	FOR (i, 1, m) {
		int t, k;
		
		cin >> t;
		if (t == 1) {
			cin >> x[i] >> y[i] >> k;
			cover(y[i], y[i] + k - 1, i);
		} else {
			cin >> k;
			int o = query(k);
			if (!o) cout << b[k] << endl;
			else cout << a[x[o] + (k - y[o])] << endl;
		}
	}

	return 0; 
}