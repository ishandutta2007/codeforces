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

int64 ans1, ans2, sz[maxn];
Graph<int> G;

int64 aux = 0;
int n;
bool o[maxn];

int64 A(int64 n) 
{
	return n * (n - 1) / 2;
}

void dfs(int v, int fa, int d)
{
	int64 S = 0;
	sz[v] = 1;
	for (auto &u : G[v]) {
		if (u != fa) {
			dfs(u, v, d + 1);
			sz[v] += sz[u];
			S += A(sz[u]);
		}
	}

	// ans1 += S * (n - sz[v]);
	ans1 += (A(sz[v]) - S) * A(n - sz[v]);
	for (auto &u : G[v]) {
		if (u != fa) {
			ans2 += (S - A(sz[u])) * A(sz[u]);
		}
	}
}

void dfs2(int v, int s)
{
	if (v < s) ++aux;
	o[v] = true;
	for (auto &u : G[v]) {
		if (!o[u]) {
			dfs2(u, s);
		}
	}
	o[v] = false;
}

void count()
{
	FOR (i, 1, n) {
		if (!o[i]) {
			dfs2(i, i);
		}
	}
}

void dfs1(int v, int fa, int s)
{
	o[v] = true;
	if (v > s) {
		count();
	}
	for (auto &u : G[v]) {
		if (u != fa) {
			dfs1(u, v, s);
		}
	}
	o[v] = false;
}

void bf()
{
	FOR (i, 1, n) {
		dfs1(i, 0, i);
	}
	cerr << aux << endl;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("D.in" , "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	cin >> n;
	// n = 20;
	G.resize(n);
	FOR (i, 2, n) {
		int s, t;
		cin >> s >> t;
		// s = i, t = rand() % (i - 1) + 1;
		G.add(s, t);
		G.add(t, s);
	}
	dfs(1, 0, 0);

	cerr << ans1 << " " << ans2 << endl;
	cout << ans1 * 2 - ans2 << endl;
	// bf();
	return 0; 
}