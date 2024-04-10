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
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

class ConvexHullTrick {
public:
	struct Line {
		int64_t k, b;
		
		inline int64_t val(int64_t x) const {
			return k*x + b;
		}
	};
private:
	vector<Line> lines;
	int last;
	
	inline void addLine(Line ln) {
		while (!lines.empty() && lines.back().k == ln.k) {
			if (ln.b > lines.back().b) {
				lines.pop_back();
			} else {
				return;
			}
		}
		while (lines.size() > 1) {
			Line a = ln, b = lines.back(), c = lines[(int)lines.size() - 2];
			if (
				(double)(a.k - c.k) * (b.b - a.b) <= 
				(double)(a.b - c.b) * (b.k - a.k)
			) {
				lines.pop_back();
			} else {
				break;
			}
		}
		lines.push_back(ln);
	}
public:
	inline int64_t query(int64_t x) {
		while (last+1 < (int)lines.size() && lines[last].val(x) < lines[last+1].val(x)) {
			last++;
		}
		return lines[last].val(x);
	}
	
	inline bool empty() {
		return lines.empty();
	}
	
	ConvexHullTrick(const vector<Line> &v) {
		lines.reserve(v.size());
		for (Line ln: v) {
			addLine(ln);
		}
		last = 0;
	}
	
	ConvexHullTrick() {}
};

struct Block {
	int sz;
	ConvexHullTrick minTr;
	ConvexHullTrick maxTr;
	vector<int64_t> a, b;
	vector<int> ord;
	int64_t inc = 0;
	int off;
	bool needRebuild;
	
	inline int64_t queryAll() {
		if (needRebuild) {
			rebuild();
		}
		return max(abs(minTr.query(inc)), abs(-maxTr.query(inc)));
	}
	
	inline int64_t query(int l, int r) {
		l -= off; r -= off;
		if (l >= r) {
			return LLONG_MIN;
		}
		if (l == 0 && r == sz) {
			return queryAll();
		}
		int64_t res = LLONG_MIN;
		for (int i = l; i < r; ++i) {
			int64_t val = a[i] + inc*b[i];
			res = max(res, abs(val));
		}
		return res;
	}
	
	inline void rebuild() {
		for (int i = 0; i < sz; ++i) {
			a[i] += inc*b[i];
		}
		inc = 0;
		vector<ConvexHullTrick::Line> ln(sz);
		for (int i = 0; i < sz; ++i) {
			ln[ord[i]] = {b[i], a[i]};
		}
		maxTr = ConvexHullTrick(ln);
		reverse(begin(ln), end(ln));
		for (int i = 0; i < sz; ++i) {
			ln[i].k *= -1;
			ln[i].b *= -1;
		}
		minTr = ConvexHullTrick(ln);
		needRebuild = false;
	}
	
	inline void addAll(int64_t delta) {
		inc += delta;
	}
	
	inline void add(int l, int r, int64_t delta) {
		l -= off; r -= off;
		if (l >= r || delta == 0) {
			return;
		}
		if (l == 0 && r == sz) {
			addAll(delta);
			return;
		}
		for (int i = l; i < r; ++i) {
			a[i] += delta*b[i];
		}
		needRebuild = true;
	}
	
	Block(vector<int64_t>::iterator ai, vector<int64_t>::iterator bi, int sz, int off)
		: sz(sz), a(ai, ai + sz), b(bi, bi + sz), ord(sz), off(off), needRebuild(true) {
		vector< pair<int, int> > v(sz);
		for (int i = 0; i < sz; ++i) {
			a[i] *= b[i];
		}
		for (int i = 0; i < sz; ++i) {
			v[i] = {b[i], i};
		}
		sort(begin(v), end(v));
		for (int i = 0; i < sz; ++i) {
			ord[v[i].second] = i;
		}
	}
	
	Block() {}
};

class SqrtDecomposition {
private:
	int n, block, bSz;
	vector<Block> blk;
public:
	inline void add(int l, int r, int64_t delta) {
		if (l > r) {
			return;
		}
		r++;
		int lb = (l + block - 1) / block, rb = r / block;
		if (lb > rb) {
			blk[l/block].add(l, r, delta);
		} else {
			if (l < lb*block) {
				blk[lb-1].add(l, lb*block, delta);
			}
			if (rb*block < r) {
				blk[rb].add(rb*block, r, delta);
			}
			for (int i = lb; i < rb; i++) {
				blk[i].addAll(delta);
			}
		}
	}
	
	inline int64_t query(int l, int r) {
		if (l > r) {
			return LLONG_MIN;
		}
		int64_t res = LLONG_MIN;
		r++;
		int lb = (l + block - 1) / block, rb = r / block;
		if (lb > rb) {
			res = max(res, blk[l/block].query(l, r));
		} else {
			if (l < lb*block) {
				res = max(res, blk[lb-1].query(l, lb*block));
			}
			if (rb*block < r) {
				res = max(res, blk[rb].query(rb*block, r));
			}
			for (int i = lb; i < rb; i++) {
				res = max(res, blk[i].queryAll());
			}
		}
		return res;
	}
	
	SqrtDecomposition(vector<int64_t> a, vector<int64_t> b)
		: n(a.size()), block(max(1, (int)sqrt(n / 6) + 1)), bSz(n / block + 1),
		  blk(bSz) {
		for (int i = 0; i < bSz; ++i) {
			int lb = i*block, rb = min(n, (i+1)*block);
			blk[i] = Block(begin(a) + lb, begin(b) + lb, rb-lb, lb);
		}
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, q; cin >> n >> q;
	vector< vector<int> > g(n);
	for (int i = 1; i < n; ++i) {
		int p; cin >> p; --p;
		g[p].push_back(i);
	}
	vector<int> aa(n), bb(n);
	for (int i = 0; i < n; ++i) {
		cin >> aa[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> bb[i];
	}
	
	vector<int64_t> a(n), b(n);
	vector<int64_t> tl(n), tr(n);
	int ktr = 0;
	function<void(int, int64_t, int64_t)> dfs = [&](int v, int64_t qa, int64_t qb) {
		tl[v] = ktr;
		for (int to : g[v]) {
			dfs(to, qa + aa[v], qb + bb[v]);
		}
		tr[v] = ktr;
		a[ktr] = qa + aa[v];
		b[ktr] = qb + bb[v];
		++ktr;
	};
	dfs(0, 0, 0);
	
	SqrtDecomposition sqd(a, b);
	for (int i = 0; i < q; ++i) {
		int type; cin >> type;
		if (type == 1) {
			int v, x; cin >> v >> x; --v;
			sqd.add(tl[v], tr[v], x);
		} else {
			int v; cin >> v; --v;
			cout << sqd.query(tl[v], tr[v]) << "\n";
		}
	}
	
	return 0;
}