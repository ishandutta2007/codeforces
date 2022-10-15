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

inline vector<int> apply(vector<int> a, vector<int> b) {
	int n = a.size();
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = a[b[i]];
	}
	return c;
}

struct MyBitset {
	uint64_t a = 0, b = 0;
	
	inline void put(int x) {
		if (x < 64) {
			a |= (uint64_t)1 << x;
		} else {
			x -= 64;
			b |= (uint64_t)1 << x;
		}
	}
	
	inline void unput(int x) {
		if (x < 64) {
			a &= ~((uint64_t)1 << x);
		} else {
			x -= 64;
			b &= ~((uint64_t)1 << x);
		}
	}
	
	inline int get(int x) const {
		if (x < 64) {
			return (a >> x) & 1;
		}
		x -= 64;
		return (b >> x) & 1;
	}
	
	inline int size() const {
		return __builtin_popcountll(a) + __builtin_popcountll(b);
	}
};

inline ostream& operator<<(ostream &os, const MyBitset &a) {
	for (int i = 0; i < 128; ++i) {
		os << a.get(i);
	}
	return os;
}

inline bool operator<(const MyBitset &a, const MyBitset &b) {
	return make_pair(a.a, a.b) < make_pair(b.a, b.b);
}

const int sparseDepth = 20;

class SparseTable {
private:
	int n;
	vector< vector<int> > a;
	vector<int> lg;
	function<int(int, int)> mx;
public:
	inline int rmq(int l, int r) {
		int w = lg[r - l + 1];
		return mx(a[w][l], a[w][r - (1 << w) + 1]);
	}
	
	SparseTable(const vector<int> &v, function<int(int, int)> mx)
		: n(v.size()), a(sparseDepth, vector<int>(n)), lg(n+1), mx(mx) {
		lg[1] = 0;
		for (int i = 2; i <= n; i++) {
			lg[i] = lg[i/2] + 1;
		}
		for (int i = 0; i < n; i++) {
			a[0][i] = v[i];
		}
		for (int i = 1; i < sparseDepth; i++) {
			for (int j = 0; j <= n - (1 << i); j++) {
				a[i][j] = mx(a[i-1][j], a[i-1][j + (1 << (i-1))]);
			}
		}
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n, k; cin >> n >> k;
	//~ int k = 5;
	
	vector< vector<int> > ps;
	map< vector<int>, int> rps;
	vector<int> p(k);
	iota(begin(p), end(p), 0);
	do {
		rps[p] = ps.size();
		ps.push_back(p);
	} while (next_permutation(begin(p), end(p)));
	
	int pc = ps.size();
	static int op[140][140] = {};
	for (int i = 0; i < pc; ++i) {
		for (int j = 0; j < pc; ++j) {
			op[i][j] = rps[apply(ps[i], ps[j])];
		}
	}
	
	auto merge = [&](MyBitset a, int perm) {
		if (a.get(perm)) return a;
		queue<int> q;
		q.push(perm);
		a.put(perm);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int i = 0; i < pc; ++i) {
				if (!a.get(i)) continue;
				if (!a.get(op[i][v])) {
					a.put(op[i][v]);
					q.push(op[i][v]);
				}
				if (!a.get(op[v][i])) {
					a.put(op[v][i]);
					q.push(op[v][i]);
				}
			}
		}
		return a;
	};
	
	set<MyBitset> states;
	queue<MyBitset> q;
	
	MyBitset base; base.put(0);
	states.insert(base);
	q.push(base);
	
	while (!q.empty()) {
		auto v = q.front(); q.pop();
		for (int i = 0; i < pc; ++i) {
			auto nv = merge(v, i);
			if (!states.count(nv)) {
				states.insert(nv);
				q.push(nv);
			}
		}
	}
	
	vector<MyBitset> st(begin(states), end(states));
	static int g[160][160], knt[160];
	for (int i = 0; i < (int)st.size(); ++i) {
		for (int j = 0; j < pc; ++j) {
			auto ni = merge(st[i], j);
			int idx = lower_bound(begin(st), end(st), ni) - begin(st);
			g[i][j] = idx;
		}
		knt[i] = st[i].size();
	}
	
	static int f[160][160];
	for (int i = 0; i < (int)st.size(); ++i) {
		for (int j = 0; j < (int)st.size(); ++j) {
			int v = i;
			for (int k = 0; k < pc; ++k) {
				if (st[j].get(k)) {
					v = g[v][k];
				}
			}
			f[i][j] = v;
		}
	}
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		vector<int> p(k);
		for (int j = 0; j < k; ++j) {
			cin >> p[j]; --p[j];
		}
		a[i] = g[0][rps[p]];
	}
	SparseTable sparse(a, [&](int a, int b) { return f[a][b]; });
	
	int64_t ans = 0;
	for (int i = 0; i < n; ++i) {
		int rb = i;
		while (rb < n) {
			int last = sparse.rmq(i, rb);
			int l = rb, r = n;
			while (l != r) {
				int m = (l + r) / 2;
				if (sparse.rmq(i, m) != last) {
					r = m;
				} else {
					l = m+1;
				}
			}
			ans += (l - rb) * knt[last];
			rb = l;
		}
	}
	cout << ans << endl;
	
	return 0;
}