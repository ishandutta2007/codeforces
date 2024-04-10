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

class SegTree {
private:
	int n;
	vector< pair<int, int> > tree;
	vector<int> lazy;
	
	inline void push(int x, int tl, int tr) {
		tree[x].first += lazy[x];
		if (tl != tr) {
			lazy[x*2] += lazy[x];
			lazy[x*2+1] += lazy[x];
		}
		lazy[x] = 0;
	}
	
	inline void modify(int x, int tl, int tr, int l, int r, int delta) {
		push(x, tl, tr);
		if (l > r) return;
		if (l == tl && tr == r) {
			lazy[x] += delta;
			push(x, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		modify(x*2, tl, tm, l, min(r, tm), delta);
		modify(x*2+1, tm+1, tr, max(l, tm+1), r, delta);
		tree[x] = min(tree[x*2], tree[x*2+1]);
	}
	
	inline pair<int, int> query(int x, int tl, int tr, int l, int r) {
		push(x, tl, tr);
		if (l > r) return {INT_MAX, INT_MAX};
		if (l == tl && tr == r) return tree[x];
		int tm = (tl + tr) / 2;
		return min(query(x*2, tl, tm, l, min(r, tm)),
		           query(x*2+1, tm+1, tr, max(l, tm+1), r));
	}
	
	inline void build(int x, int tl, int tr) {
		if (tl == tr) {
			tree[x].second = tl;
			return;
		}
		int tm = (tl + tr) / 2;
		build(x*2, tl, tm);
		build(x*2+1, tm+1, tr);
		tree[x] = min(tree[x*2], tree[x*2+1]);
	}
public:
	inline void modify(int l, int r, int delta) {
		modify(1, 0, n-1, l, r, delta);
	}
	
	inline pair<int, int> query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
	
	SegTree(int n)
		: n(n), tree(4*n), lazy(4*n) {
		build(1, 0, n-1);
	}
};

struct PlusMinus {
	int n;
	SegTree st;
	set<int> unminus;
	
	inline void addPlus(int x) {
		auto iter = unminus.lower_bound(x);
		int fin = n;
		if (iter != end(unminus)) {
			fin = *iter;
			unminus.erase(iter);
		}
		st.modify(x, fin-1, +1);
	}
	
	inline void addMinus(int x) {
		auto q = st.query(x, n-1);
		int fin = n;
		if (q.first == 0) {
			fin = q.second;
			unminus.insert(q.second);
		}
		st.modify(x, fin-1, -1);
	}
	
	inline int getVal(int x) {
		return x < 0 ? 0 : st.query(x, x).first;
	}
	
	inline bool canEatUs(int x) {
		auto iter = unminus.lower_bound(x);
		return iter == end(unminus);
	}
	
	PlusMinus(int n)
		: n(n), st(n) {}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n; cin >> n;
	vector<int> p(n);
	vector<int> r(n);
	vector<int> q(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i]; --p[i];
		r[p[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> q[i]; --q[i];
	}
	
	PlusMinus pm(n);
	
	int pNum = n-1, pBomb = 0;
	
	auto goodNum = [&]() {
		assert(pNum >= 0);
		int pp = r[pNum];
		return pm.canEatUs(pp);
	};
	
	auto dump = [&]() {
		for (int i = 0; i < n; ++i) {
			cout << pm.getVal(i) << " ";
		}
		cout << endl;
		cout << "uminus:";
		for (int i : pm.unminus) {
			cout << " " << i;
		}
		cout << endl;
	};
	
	auto nextNum = [&]() {
		assert(pNum >= 0);
		int pp = r[pNum--];
		pm.addPlus(pp);
		//~ cout << "next num" << endl;
		//~ dump();
	};
	
	auto nextBomb = [&]() {
		assert(pBomb < n);
		int pp = q[pBomb++];
		pm.addMinus(pp);
		//~ cout << "next bomb" << endl;
		//~ dump();
	};
	
	for (int i = 0; i < n; ++i) {
		while (!goodNum()) nextNum();
		cout << pNum + 1 << " ";
		//~ cout << "! " << pNum + 1 << endl;
		nextBomb();
	}
	cout << endl;
	
	return 0;
}