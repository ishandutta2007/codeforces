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
const int module = 998244353; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

inline int64_t mulMod(int64_t a, int64_t b) {
	return (a*b) % module;
}

inline int64_t powMod(int64_t a, int64_t n) {
	if (n == 1) {
		return a;
	}
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= module;
		}
		a *= a;
		a %= module;
		n >>= 1;
	}
	return res;
}

inline int64_t rev(int64_t a) {
	return powMod(a, module-2);
}

struct FreqCounter {
	vector<int> freq;
	vector<int> kfr;
	
	inline void change(int x, int delta) {
		kfr[freq[x]]--;
		freq[x] += delta;
		kfr[freq[x]]++;
	}
	
	inline void add(int x) {
		change(x, +1);
	}
	
	inline void del(int x) {
		change(x, -1);
	}
	
	FreqCounter(int n, int m)
		: freq(m), kfr(n+1) {
		kfr[0] = m;
	}
};

struct Query {
	int l, r, k, idx;
};

const int block = 200;
const int mfact = 300000;
int f[mfact], rf[mfact];

inline bool kCmp(const Query &a, const Query &b) {
	return make_pair(a.k, a.l - a.r) < make_pair(b.k, b.l - b.r);
}

inline bool moCmp(const Query &a, const Query &b) {
	return make_pair(a.l/block, a.r) < make_pair(b.l/block, b.r);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	f[0] = rf[0] = 1;
	for (int i = 1; i < mfact; i++) {
		f[i] = mulMod(f[i-1], i);
		rf[i] = rev(f[i]);
	}
	
	int n, m, q; cin >> n >> m >> q;
	vector<int> e(n);
	vector<int> knt(m);
	for (int i = 0; i < n; i++) {
		cin >> e[i]; e[i]--;
		knt[e[i]]++;
	}
	
	const int hlim = min(n+1, 200);
	vector<int> heavies;
	for (int i = 0; i < m; i++) {
		if (knt[i] >= hlim) {
			heavies.push_back(i);
		}
	}
	
	vector<Query> qry(q);
	vector<int> res(q);
	int qktr = 0;
	for (Query &q: qry) {
		cin >> q.l >> q.r >> q.k; q.l--; q.r--;
		q.idx = qktr++;
	}
	
	sort(qry.begin(), qry.end(), kCmp);
	for (int r = 0; r < q;) {
		int l = r;
		int qk = qry[l].k;
		while (r < q && qk == qry[r].k) {
			r++;
		}
		
		int64_t bans = 1;
		for (int i = 0; i < m; i++) {
			bans = mulMod(bans, f[qk + knt[i]]);
		}
		
		int ptr = n, fct = 1;
		for (int i = l; i < r; i++) {
			int len = qry[i].r - qry[i].l + 1;
			while (ptr > len) {
				ptr--;
				fct = mulMod(fct, ((int64_t)m*qk + n - ptr) % module);
			}
			res[qry[i].idx] = mulMod(bans, fct);
		}
	}
	
	sort(qry.begin(), qry.end(), moCmp);
	int l = 0, r = -1;
	FreqCounter counter(n, m);
	for (int i = 0; i < n; i++) {
		counter.add(e[i]);
	}
	
	for (Query q: qry) {
		while (q.l < l) {
			counter.del(e[--l]);
		}
		while (q.r > r) {
			counter.del(e[++r]);
		}
		while (q.l > l) {
			counter.add(e[l++]);
		}
		while (q.r < r) {
			counter.add(e[r--]);
		}
		
		int64_t ans = 1;
		for (int i = 0; i < hlim; i++) {
			if (counter.kfr[i]) {
				ans = mulMod(ans, powMod(rf[q.k + i], counter.kfr[i]));
			}
		}
		for (int i: heavies) {
			int freq = counter.freq[i];
			if (freq >= hlim) {
				ans = mulMod(ans, rf[q.k + freq]);
			}
		}
		
		res[q.idx] = mulMod(res[q.idx], ans);
	}
	
	for (int i = 0; i < q; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}