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

struct Coord3D {
	int x, y, z;
	int tag = 0;
	
	inline auto toTuple() const {
		return make_tuple(x, y, z, tag);
	}
};

inline bool operator<(const Coord3D &a, const Coord3D &b) {
	return a.toTuple() < b.toTuple();
}

inline istream &operator>>(istream &is, Coord3D &c) {
	is >> c.x >> c.y >> c.z;
	c.x--; c.y--; c.z--;
	return is;
}

inline int cmp(int a, int l, int r) {
	if (a < l) {
		return -1;
	} else if (l <= a && a <= r) {
		return 0;
	} else if (r < a) {
		return +1;
	} else {
		// Happens only on Mars
		assert(false);
	}
}

class Fenwick {
private:
	vector<int> a;
	int n;
public:
	inline void modify(int v, int delta) {
		for (; v < n; v |= v+1) {
			a[v] = min(a[v], delta);
		}
	}
	
	inline int query(int v) {
		int res = INT_MAX;
		for (; v >= 0; v &= v+1, v--) {
			res = min(res, a[v]);
		}
		return res;
	}
	
	Fenwick(int n)
		: a(n, INT_MAX), n(n) {
	}
};

inline int mul(int x, int sgn, int rng) {
	if (sgn < 0) {
		return rng-x-1;
	} else if (sgn == 0) {
		return 0;
	} else if (sgn > 0) {
		return x;
	} else {
		// Happens only on Mars
		assert(false);
	}
}

inline bool submask(int a, int b) {
	int oa = a, ob = b;
	for (int i = 0; i < 3; i++) {
		int qa = a%3, qb = b%3;
		if (qa != qb && qb != 1) {
			return false;
		}
		a /= 3; b /= 3;
	}
	return true;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int xm, ym, zm; cin >> xm >> ym >> zm;
	int n, m, k; cin >> n >> m >> k;
	vector<Coord3D> open(n);
	for (int i = 0; i < n; i++) {
		cin >> open[i];
	}
	vector<Coord3D> close(m);
	for (int i = 0; i < m; i++) {
		cin >> close[i];
		close[i].tag = -1;
	}
	vector<Coord3D> qry(k);
	for (int i = 0; i < k; i++) {
		cin >> qry[i];
		qry[i].tag = i;
	}
	
	Coord3D lb {INT_MAX, INT_MAX, INT_MAX}, rb {INT_MIN, INT_MIN, INT_MIN};
	for (Coord3D c: open) {
		lb.x = min(lb.x, c.x);
		lb.y = min(lb.y, c.y);
		lb.z = min(lb.z, c.z);
		rb.x = max(rb.x, c.x);
		rb.y = max(rb.y, c.y);
		rb.z = max(rb.z, c.z);
	}
	
	auto segmentate = [&](const Coord3D &c) {
		return
			(cmp(c.x, lb.x, rb.x) + 1) * 9 + 
			(cmp(c.y, lb.y, rb.y) + 1) * 3 + 
			(cmp(c.z, lb.z, rb.z) + 1) * 1 ; 
	};
	
	vector< vector<Coord3D> > bySegment(27);
	
	for (Coord3D c: close) {
		int seg = segmentate(c);
		if (seg == 13) {
			cout << "INCORRECT" << endl;
			return 0;
		}
		for (int i = 0; i < 27; i++) {
			if (submask(i, seg)) {
				bySegment[i].push_back(c);
			}
		}
	}
	cout << "CORRECT" << endl;
	
	vector<string> res(k, "UNKNOWN");
	for (Coord3D c: qry) {
		int seg = segmentate(c);
		if (seg == 13) {
			res[c.tag] = "OPEN";
		} else {
			bySegment[seg].push_back(c);
		}
	}
	
	for (int i = -1; i <= +1; i++) {
		for (int j = -1; j <= +1; j++) {
			for (int k = -1; k <= +1; k++) {
				for (Coord3D &c: bySegment[(i+1) * 9 + (j+1) * 3 + (k+1) * 1]) {
					c.x = mul(c.x, i, xm);
					c.y = mul(c.y, j, ym);
					c.z = mul(c.z, k, zm);
				}
			}
		}
	}
	
	vector< vector<Coord3D> > coordByX(xm);
	for (auto v: bySegment) {
		for (int i = 0; i < xm; i++) {
			coordByX[i].clear();
		}
		for (Coord3D c: v) {
			coordByX[c.x].push_back(c);
		}
		for (int i = 0; i < xm; i++) {
			sort(coordByX[i].begin(), coordByX[i].end());
		}
		Fenwick f(ym);
		for (int i = 0; i < xm; i++) {
			for (Coord3D c: coordByX[i]) {
				if (c.tag < 0) {
					f.modify(c.y, c.z);
				} else {
					if (f.query(c.y) <= c.z) {
						res[c.tag] = "CLOSED";
					}
				}
			}
		}
	}
	
	for (int i = 0; i < k; i++) {
		cout << res[i] << "\n";
	}
	
	return 0;
}