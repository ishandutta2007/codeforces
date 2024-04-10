// The code was written by gepardo
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

#define int int64_t

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

inline void raiseError(const string &description) {
	cerr << "Error : " << description << endl;
	exit(42);
}

inline map<int, int> divs(int m) {
	map<int, int> res;
	for (int i = 2; i*i <= m; ++i) {
		while (m % i == 0) {
			m /= i;
			++res[i];
		}
	}
	if (m != 1) {
		++res[m];
	}
	return res;
}

class SegmentTree {
private:
	int n, mod;
	vector<int64_t> tree;
	vector<int64_t> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (lazy[x] != 1) {
			tree[x] *= lazy[x];
			tree[x] %= mod;
			if (tl != tr) {
				lazy[x*2] *= lazy[x];
				lazy[x*2] %= mod;
				lazy[x*2+1] *= lazy[x];
				lazy[x*2+1] %= mod;
			}
			lazy[x] = 1;
		}
	}
	
	void update(int x, int tl, int tr, int l, int r, int64_t val) {
		if (l > r) {
			push(x, tl, tr);
		} else if (l == tl && r == tr) {
			lazy[x] *= val;
			lazy[x] %= mod;
			push(x, tl, tr);
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			update(x*2, tl, tm, l, min(r, tm), val);
			update(x*2+1, tm+1, tr, max(l, tm+1), r, val);
			tree[x] = (tree[x*2] + tree[x*2+1]) % mod;
		}
	}
	
	void updateOne(int x, int tl, int tr, int v, int64_t val) {
		push(x, tl, tr);
		if (tl == tr) {
			tree[x] = val;
		} else {
			int tm = (tl + tr) / 2;
			if (v <= tm) {
				updateOne(x*2, tl, tm, v, val);
				push(x*2+1, tm+1, tr);
			} else {
				push(x*2, tl, tm);
				updateOne(x*2+1, tm+1, tr, v, val);
			}
			tree[x] = (tree[x*2] + tree[x*2+1]) % mod;
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
			) % mod;
		}
	}
	
public:
	inline void update(int l, int r, int64_t val) {
		update(1, 0, n-1, l, r, val%mod);
	}
	
	inline void updateOne(int v, int64_t val) {
		updateOne(1, 0, n-1, v, val%mod);
	}
	
	inline int64_t sum(int l, int r) {
		return sum(1, 0, n-1, l, r);
	}
	
	SegmentTree(int n, int mod)
		: n(n), mod(mod), tree(4*n, 0), lazy(4*n, 1) {
	}
};

class FenwickTree {
private:
	int n;
	vector<int64_t> a;
	
	inline void add(int v, int64_t delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
public:
	inline void addRange(int l, int r, int64_t delta) {
		add(l, delta);
		add(r+1, -delta);
	}
	
	inline int64_t get(int v) {
		int64_t res = 0;
		for (; v >= 0; v &= v+1, v--) {
			res += a[v];
		}
		return res;
	}
	
	FenwickTree(int aN)
		: n(aN+1), a(n, 0) {
	}
};

int64_t extGcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t g = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

inline int64_t inverse(int64_t a, int64_t m) {
	int64_t x, y;
	int64_t g = extGcd(a, m, x, y);
	assert(g == 1);
	int64_t res = (x % m + m) % m;
	assert((res * a) % m == 1);
	return res;
}

inline int64_t binPow(int64_t a, int64_t n, int64_t m) {
	assert(n >= 0);
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, mod; cin >> n >> mod;
	auto divide = divs(mod);
	vector<int> vals, nknt;
	for (auto it : divide) {
		vals.push_back(it.first);
		nknt.push_back(it.second);
	}
	int k = vals.size();
	
	auto split = [&](int x) {
		vector<int> res(k+1);
		for (int i = 0; i < k; ++i) {
			while (x % vals[i] == 0) {
				x /= vals[i];
				++res[i];
			}
		}
		res.back() = x%mod;
		return res;
	};
	
	SegmentTree tree(n, mod);
	vector<FenwickTree> cnts(k, FenwickTree(n));
	SegmentTree rem(n, mod);
	
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		tree.updateOne(i, x);
		auto w = split(x);
		for (int j = 0; j < k; ++j) {
			cnts[j].addRange(i, i, w[j]);
		}
		rem.updateOne(i, w.back());
	}
	
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int type; cin >> type;
		if (type == 3) {
			int l, r; cin >> l >> r; --l; --r;
			cout << tree.sum(l, r) << "\n";
		} else if (type == 1) {
			int l, r, x; cin >> l >> r >> x; --l; --r;
			tree.update(l, r, x);
			auto w = split(x);
			for (int j = 0; j < k; ++j) {
				cnts[j].addRange(l, r, w[j]);
			}
			rem.update(l, r, w.back());
		} else if (type == 2) {
			int p, x; cin >> p >> x; --p;
			auto w = split(x);
			for (int j = 0; j < k; ++j) {
				cnts[j].addRange(p, p, -w[j]);
			}
			rem.update(p, p, inverse(w.back(), mod));
			int64_t val = rem.sum(p, p);
			for (int j = 0; j < k; ++j) {
				val *= binPow(vals[j], cnts[j].get(p), mod);
				val %= mod;
			}
			tree.updateOne(p, val);
		} else {
			assert(false);
		}
		/*for (int j = 0; j < n; ++j) {
			cout << tree.sum(j, j) << " ";
		}
		cout << "\n";
		for (int j = 0; j < k; ++j) {
			cout << vals[j] << "(" << nknt[j] << ") : ";
			for (int it = 0; it < n; ++it) {
				cout << cnts[j].get(it) << " ";
			}
			cout << "\n";
		}
		for (int j = 0; j < n; ++j) {
			cout << rem.sum(j, j) << " ";
		}
		cout << "\n";
		cout << "----" << endl;*/
	}
	
	return 0;
}