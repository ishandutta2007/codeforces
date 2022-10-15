#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
	//~ #define USE_FILE_IO
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
const int mod = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct Point {
	int x, y, c;
};

struct Query {
	int l, r, val;
};

struct SegTree {
private:
	struct Node {
		int64_t sum;
		int lazy;
		int mval;
		int mcnt;
		int sval;
	};
	
	int n;
	vector<Node> tree;
	
	inline void merge(int x) {
		Node &t = tree[x];
		const Node *l = &tree[x*2];
		const Node *r = &tree[x*2+1];
		t = {l->sum + r->sum, 0, -1, -1, -1};
		if (l->mval < r->mval) {
			swap(l, r);
		}
		if (l->mval == r->mval) {
			t.mval = l->mval;
			t.mcnt = l->mcnt + r->mcnt;
			t.sval = max(l->sval, r->sval);
		} else {
			t.mval = l->mval;
			t.mcnt = l->mcnt;
			t.sval = max(l->sval, r->mval);
		}
	}
	
	inline void build(const vector<int> &p, int x, int l, int r, int mx) {
		if (l == r) {
			tree[x] = {(int64_t)mx * p[l], 0, mx, p[l], INT_MIN};
			return;
		}
		int m = (l + r) / 2;
		build(p, x*2, l, m, mx);
		build(p, x*2+1, m+1, r, mx);
		merge(x);
	}
	
	inline void push(int x, int l, int r) {
		int lz = tree[x].lazy;
		if (lz == 0) {
			return;
		}
		if (l != r) {
			if (tree[x*2].mval + tree[x*2].lazy == tree[x].mval) {
				tree[x*2].lazy += lz;
			}
			if (tree[x*2+1].mval + tree[x*2+1].lazy == tree[x].mval) {
				tree[x*2+1].lazy += lz;
			}
		}
		tree[x].lazy = 0;
		tree[x].mval += lz;
		tree[x].sum += (int64_t)tree[x].mcnt * lz;
	}
	
	inline void upd(int x, int tl, int tr, int l, int r, int b) {
		push(x, tl, tr);
		if (l > r || tree[x].mval <= b) return;
		if (l == tl && tr == r && tree[x].sval < b) {
			tree[x].lazy = b - tree[x].mval;
			push(x, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		upd(x*2, tl, tm, l, min(r, tm), b);
		upd(x*2+1, tm+1, tr, max(tm+1, l), r, b);
		merge(x);
	}
public:
	inline void upd(int l, int r, int b) {
		upd(1, 0, n-1, l, r, b);
	}
	
	inline int64_t ask() {
		push(1, 0, n-1);
		return tree[1].sum;
	}
	
	SegTree(int n, int mx, const vector<int> &p)
		: n(n), tree(4*n) {
		build(p, 1, 0, n-1, mx);
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, k, l; cin >> n >> k >> l;
	vector<Point> v(n);
	map<int, int> cx, cy;
	for (Point &p : v) {
		cin >> p.x >> p.y >> p.c; --p.c;
		cx[p.x] = cy[p.y] = 42;
	}
	cx[0] = cy[0] = cx[l-1] = cy[l-1] = 42;
	
	vector<int> dx, dy;
	for (auto &it : cx) {
		it.second = dx.size();
		dx.push_back(it.first);
	}
	for (auto &it : cy) {
		it.second = dy.size();
		dy.push_back(it.first);
	}
	for (Point &p : v) {
		p.x = cx[p.x];
		p.y = cy[p.y];
	}
	int kx = dx.size(), ky = dy.size();
	int64_t ans = 0;
	
	vector<int> p(ky);
	for (int i = 0; i < ky; ++i) {
		p[i] = (i == ky-1 ? l : dy[i+1]) - dy[i];
	}
	
	for (int up = 0; up < kx; ++up) {
		vector<vector<Query>> qry(ky);
		vector<vector<Point>> py(ky);
		vector<vector<pair<int, int>>> stks(k);
		
		for (const Point &p : v) {
			if (p.x < up) continue;
			py[p.y].push_back(p);
		}
		
		for (int i = ky-1; i >= 0; --i) {
			sort(begin(py[i]), end(py[i]), [](const Point &a, const Point &b) { return make_pair(a.c, a.x) < make_pair(b.c, b.x); });
			int pc = -1;
			for (const Point &p : py[i]) {
				if (p.c == pc) continue;
				pc = p.c;
				auto &stk = stks[p.c];
				int val = l - dx[p.x];
				int pos = i+1, pval = 0;
				while (!stk.empty() && stk.back().first < val) {
					qry[i].push_back({pos, stk.back().second-1, pval});
					pos = stk.back().second;
					pval = stk.back().first;
					stk.pop_back();
				}
				qry[i].push_back({pos, (stk.empty() ? ky : stk.back().second) - 1, pval});
				stk.emplace_back(val, i);
			}
		}
		
		SegTree st(ky, l+1, p);
		for (int i = 0; i < k; ++i) {
			auto &stk = stks[i];
			int le = 0, pv = 0;
			reverse(begin(stk), end(stk));
			for (auto [val, pos] : stk) {
				st.upd(le, pos-1, pv);
				le = pos;
				pv = val;
			}
			st.upd(le, ky-1, pv);
		}
		
		int64_t mx = (up == 0) ? 1 : dx[up] - dx[up-1];
		for (int i = 0; i < ky; ++i) {
			int64_t my = (i == 0) ? 1 : dy[i] - dy[i-1];
			int64_t mm = mx * my % mod;
			int64_t qq = st.ask() % mod;
			ans += qq * mm % mod;
			ans %= mod;
			st.upd(i, i, 0);
			for (Query q : qry[i]) {
				st.upd(q.l, q.r, q.val);
			}
		}
	}
	
	cout << ans << endl;
	return 0;
}