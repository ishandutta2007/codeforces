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
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 pow(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
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

const int maxv = 1100, maxe = 160000;
const double eps = 1e-9;

struct edge {
	int t, c;
	double w;
	edge *n, *o;
};

int S, T, maxflow, tms;
double phi, mincost;
double dist[maxv];
int nptr[maxv], x[maxv], y[maxv], o[maxv];
edge graph[maxe << 1], *eptr = graph, *adj[maxv];

void adde(int s, int t, int c, double w)
{
	*++eptr = (edge){t, c, +w, adj[s]}, adj[s] = eptr;
	*++eptr = (edge){s, 0, -w, adj[t]}, adj[t] = eptr;
	adj[s]->o = adj[t], adj[t]->o = adj[s];
}

bool modify_dist()
{
	fill(dist, dist + maxv, 1e300), dist[T] = 0;
	int head = T, tail = T, v; double dtmp; edge *e;
	for (; head; head = nptr[v], nptr[v] = 0)
		for (e = adj[v = head]; e; e = e->n)
			if (e->o->c && (dtmp = dist[v] - e->w) < dist[e->t] - eps) {
				dist[e->t] = dtmp;
				if (nptr[e->t] || e->t == tail) continue;
				if (head != tail && dist[nptr[v]] > dtmp)
					nptr[e->t] = nptr[v], nptr[v] = e->t;
				else
					nptr[tail] = e->t, tail = e->t;
			}
	for (int v = 1; v <= T; ++v) {
		for (e = adj[v]; e; e = e->n) {
			e->w -= dist[v] - dist[e->t];
		}
	}
	phi += dist[S];
	return phi < 1e150;
}

int augment(int v, int f)
{
	if (v == T) return maxflow += f, mincost += f * phi, f;
	o[v] = tms; int k = f;
	for (edge *e = adj[v]; e; e = e->n) 
		if (e->w < eps && o[e->t] != tms && e->c) {
			int x = augment(e->t, min(f, e->c));
			e->c -= x, e->o->c += x, f -= x;
			if (!f) return k;
		}
	return k - f;
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen("E.in" , "r", stdin);
	freopen("E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio (false);

	int n;

	cin >> n;
	// n = 400;

	S = n * 2 + 1, T = S + 1;
	int my = -oo;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		// x[i] = rand() % 2000 - 1000, y[i] = rand() % 2000 - 1000;
		chkmax(my, y[i]);
	}
	for (int i = 1; i <= n; ++i) {
		adde(i + n, T, 2, 0);
		adde(S, i, 1, 0);
		for (int j = 1; j <= n; ++j) {
			if (y[i] < y[j]) {
				adde(i, j + n, 1, hypot(x[i] - x[j], y[i] - y[j]));
			}
		}
	}

	for (; modify_dist(); ) {
		for (; ++tms, augment(S, oo); )
			;
	}
	if (maxflow != n - 1) {
		cout << -1 << endl;
	} else {
		cout << setprecision(15) << mincost << endl;
	}

	return 0; 
}