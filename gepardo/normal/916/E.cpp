// This code was written by alex256
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

const int logN = 20;

struct LCAFinder {
	int n;
	vector< vector<int> > g;
	vector<int> tin, tout, qin, qout;
	vector< vector<int> > up;
	int timer, qimer;
	
	void dfs(int v, int p = 0) {
		tin[v] = timer++;
		qin[v] = qout[v] = qimer++;
		up[v][0] = p;
		for (int i = 1; i < logN; i++) {
			up[v][i] = up[up[v][i-1]][i-1];
		}
		for (int to: g[v]) {
			if (to != p) {
				dfs(to, v);
				qout[v] = max(qout[v], qout[to]);
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
	
	inline int wayDown(int a, int b) {
		assert(upper(a, b));
		for (int i = logN-1; i >= 0; i--) {
			if (!upper(up[b][i], a)) {
				b = up[b][i];
			}
		}
		return b;
	}
	
	LCAFinder(int n)
		: n(n), g(n), tin(n), tout(n), qin(n), qout(n),
		  up(n, vector<int>(logN)), timer(0), qimer(0) {
	}
};

class SegmentTree {
private:
	int n;
	vector<int64_t> tree;
	vector<char> isLazy;
	vector<int64_t> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (isLazy[x]) {
			tree[x] += lazy[x] * (tr - tl + 1);
			if (tl != tr) {
				isLazy[x*2] = true;
				lazy[x*2] += lazy[x];
				isLazy[x*2+1] = true;
				lazy[x*2+1] += lazy[x];
			}
			isLazy[x] = false;
			lazy[x] = 0;
		}
	}
	
	void update(int x, int tl, int tr, int l, int r, int64_t val) {
		if (l > r) {
			push(x, tl, tr);
		} else if (l == tl && r == tr) {
			isLazy[x] = true;
			lazy[x] += val;
			push(x, tl, tr);
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			update(x*2, tl, tm, l, min(r, tm), val);
			update(x*2+1, tm+1, tr, max(l, tm+1), r, val);
			tree[x] = tree[x*2] + tree[x*2+1];
		}
	}
	
	void updateOne(int x, int tl, int tr, int v, int64_t val) {
		if (tl == tr) {
			isLazy[x] = true;
			lazy[x] = val;
			push(x, tl, tr);
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			if (v <= tm) {
				updateOne(x*2, tl, tm, v, val);
				push(x*2+1, tm+1, tr);
			} else {
				push(x*2, tl, tm);
				updateOne(x*2+1, tm+1, tr, v, val);
			}
			tree[x] = tree[x*2] + tree[x*2+1];
		}
	}
	
	int64_t sum(int x, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		} else if (l == tl && r == tr) {
			push(x, tl, tr);
			return tree[x];
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			return (
				sum(x*2, tl, tm, l, min(r, tm)) +
				sum(x*2+1, tm+1, tr, max(l, tm+1), r)
			);
		}
	}
public:
	inline void update(int l, int r, int64_t val) {
		update(1, 0, n-1, l, r, val);
	}
	
	inline void updateOne(int v, int64_t val) {
		updateOne(1, 0, n-1, v, val);
	}
	
	inline int64_t sum(int l, int r) {
		return sum(1, 0, n-1, l, r);
	}
	
	SegmentTree(int n)
		: n(n), tree(4*n, 0), isLazy(4*n, false), lazy(4*n) {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, q; cin >> n >> q;
	LCAFinder lca(n);
	SegmentTree st(n);
	vector<int> val(n);
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		lca.g[a].push_back(b);
		lca.g[b].push_back(a);
	}
	lca.precalc();
	for (int i = 0; i < n; i++) {
		st.updateOne(lca.qin[i], val[i]);
	}
	int root = 0;
	for (int i = 0; i < q; i++) {
		int qid; cin >> qid;
		switch (qid) {
			case 1 : { 
				cin >> root; root--;
			} break;
			case 2 : {
				int u, v, x; cin >> u >> v >> x; u--; v--;
				int hang = 0;
				if (lca.upper(root, u) ^ lca.upper(root, v)) {
					hang = root;
				} else if (lca.upper(root, u)) {
					hang = lca.lca(u, v);
				} else {
					int l = lca.lca(u, v);
					if (lca.upper(l, root)) {
						int l1 = lca.lca(u, root);
						int l2 = lca.lca(v, root);
						hang = lca.upper(l1, l2) ? l2 : l1;
					} else {
						hang = l;
					}
				}
				if (lca.upper(hang, root)) {
					st.update(lca.qin[0], lca.qout[0], x);
					if (hang != root) {
						int wd = lca.wayDown(hang, root);
						st.update(lca.qin[wd], lca.qout[wd], -x);
					}
				} else {
					st.update(lca.qin[hang], lca.qout[hang], x);
				}
			} break;
			case 3 : {
				int v; cin >> v; v--;
				int64_t ans = 0;
				if (lca.upper(v, root)) {
					ans = st.sum(lca.qin[0], lca.qout[0]);
					if (v != root) {
						int wd = lca.wayDown(v, root);
						ans -= st.sum(lca.qin[wd], lca.qout[wd]);
					}
				} else {
					ans = st.sum(lca.qin[v], lca.qout[v]);
				}
				cout << ans << "\n";
			} break;
			default: {
				raiseError("Illegal query type!");
			}
		}
	}
	return 0;
}