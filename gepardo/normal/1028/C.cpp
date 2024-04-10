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

struct Rect {
	int x1, y1, x2, y2;
};

inline Rect intr(Rect a, Rect b) {
	return {max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
}

class SegmentTree {
private:
	int n;
	vector<int64_t> tree;
	vector<int64_t> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (lazy[x]) {
			tree[x] += lazy[x];
			if (tl != tr) {
				lazy[x*2] += lazy[x];
				lazy[x*2+1] += lazy[x];
			}
			lazy[x] = 0;
		}
	}
	
	void update(int x, int tl, int tr, int l, int r, int64_t val) {
		if (l > r) {
			push(x, tl, tr);
		} else if (l == tl && r == tr) {
			lazy[x] += val;
			push(x, tl, tr);
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			update(x*2, tl, tm, l, min(r, tm), val);
			update(x*2+1, tm+1, tr, max(l, tm+1), r, val);
			tree[x] = max(tree[x*2], tree[x*2+1]);
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
			return max(
				sum(x*2, tl, tm, l, min(r, tm)),
				sum(x*2+1, tm+1, tr, max(l, tm+1), r)
			);
		}
	}
public:
	inline void update(int l, int r, int64_t val) {
		update(1, 0, n-1, l, r, val);
	}
	
	inline int64_t sum(int l, int r) {
		return sum(1, 0, n-1, l, r);
	}
	
	SegmentTree(int n)
		: n(n), tree(4*n, 0), lazy(4*n) {
	}
};


struct Event {
	int t, d, l, r;
};

inline bool operator<(Event a, Event b) {
	return make_tuple(a.t, a.d, a.l, a.r) < make_tuple(b.t, b.d, b.l, b.r);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<Rect> v(n);
	vector<Event> ev;
	map<int, int> ky;
	for (int i = 0; i < n; i++) {
		cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
		ky[v[i].y1] = ky[v[i].y2] = 42;
	}
	int kk = 0;
	vector<int> q;
	for (auto &it: ky) {
		it.second = kk++;
		q.push_back(it.first);
	}
	for (int i = 0; i < n; i++) {
		v[i].y1 = ky[v[i].y1];
		v[i].y2 = ky[v[i].y2];
		ev.push_back({v[i].x1, -1, v[i].y1, v[i].y2});
		ev.push_back({v[i].x2, +1, v[i].y1, v[i].y2});
	}
	SegmentTree st(2*n);
	sort(ev.begin(), ev.end());
	for (Event e: ev) {
		st.update(e.l, e.r, -e.d);
		if (st.sum(0, kk-1) >= n-1) {
			int l = 0, r = kk-1;
			while (l != r) {
				int m = (l + r) / 2;
				if (st.sum(l, m) >= n-1) {
					r = m;
				} else {
					l = m+1;
				}
			}
			cout << e.t << " " << q[l] << endl;
			return 0;
		}
	}
	return 0;
}