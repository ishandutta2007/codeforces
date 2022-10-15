// Code written by gepardo
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

class DisjointSetUnion {
private:
	int n;
	vector<int> p;
public:
	int parent(int v) {
		if (p[v] < 0) {
			return v;
		} else {
			return p[v] = parent(p[v]);
		}
	}
	
	inline bool merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b) {
			return false;
		}
		p[b] = a;
		return true;
	}
	
	DisjointSetUnion(int n)
		: n(n), p(n, -1) {
	}
};

struct Edge {
	int a, b, c;
};

inline bool operator<(const Edge &a, const Edge &b) {
	return a.c < b.c;
}

const int logN = 20;

struct LCAFinder {
	int n;
	vector< vector<int> > g;
	vector<int> tin, tout;
	vector< vector<int> > up;
	int timer;
	
	void dfs(int v, int p = 0) {
		tin[v] = timer++;
		up[v][0] = p;
		for (int i = 1; i < logN; i++) {
			up[v][i] = up[up[v][i-1]][i-1];
		}
		for (int to: g[v]) {
			if (to != p) {
				dfs(to, v);
			}
		}
		tout[v] = timer++;
	}
	
	inline void precalc() {
		dfs(0);
	}
	
	inline bool upper(int a, int b) {
		return tin[a] <= tin[b] && tout[a] >= tout[b];
	}
	
	inline int lca(int a, int b) {
		if (upper(a, b)) {
			return a;
		}
		if (upper(b, a)) {
			return b;
		}
		for (int i = logN-1; i >= 0; i--) {
			if (!upper(up[a][i], b)) {
				a = up[a][i];
			}
		}
		return up[a][0];
	}
	
	LCAFinder(int n)
		: n(n), g(n), tin(n), tout(n),
		  up(n, vector<int>(logN)), timer(0) {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, k, m; cin >> n >> k >> m;
	vector< vector<int> > g(n);
	DisjointSetUnion dsu(n);
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b; a--; b--;
		dsu.merge(a, b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<Edge> ee(m);
	for (int i = 0; i < m; i++) {
		cin >> ee[i].a >> ee[i].b >> ee[i].c; ee[i].a--; ee[i].b--;
	}
	sort(ee.begin(), ee.end());
	int64_t ans = 0;
	for (Edge e: ee) {
		if (dsu.merge(e.a, e.b)) {
			g[e.a].push_back(e.b);
			g[e.b].push_back(e.a);
			ans -= e.c;
		}
	}
	
	vector<int> q(n, INT_MAX);
	q[0] = 0;
	DisjointSetUnion d2(n);
	LCAFinder lca(n);
	lca.g = g;
	lca.precalc();
	
	auto add = [&](int a, int b, int val) {
		assert(lca.upper(a, b));
		b = d2.parent(b);
		while (!lca.upper(b, a)) {
			int c = lca.up[b][0];
			q[b] = val;
			d2.merge(c, b);
			b = d2.parent(b);
		}
	};
	
	for (Edge e: ee) {
		int l = lca.lca(e.a, e.b);
		add(l, e.a, e.c);
		add(l, e.b, e.c);
	}
	
	for (int i = 0; i < n; i++) {
		if (q[i] == INT_MAX) {
			cout << -1 << endl;
			return 0;
		}
		ans += q[i];
	}
	
	cout << ans << endl;
	return 0;
}