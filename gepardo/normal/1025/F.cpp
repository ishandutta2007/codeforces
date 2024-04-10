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

struct Point {
	int64_t x, y;
};

inline bool operator<(const Point &a, const Point &b) {
	return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

struct Vector {
	int64_t A, B;
	
	inline void normalize() {
		if (B < 0) {
			A *= -1;
			B *= -1;
		}
	}
};

inline bool operator<(Vector a, Vector b) {
	a.normalize();
	b.normalize();
	int64_t deg = a.A * b.B - a.B * b.A;
	if (deg == 0 && b.B == 0) {
		return (a.B > 0) < (b.B > 0);
	}
	return deg < 0;
}

inline int64_t getC(const Vector &v, const Point &p) {
	return p.x*v.A + p.y*v.B;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n; cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end());
	
	vector<int> p(n), r(n);
	iota(p.begin(), p.end(), 0);
	iota(r.begin(), r.end(), 0);
	
	vector< tuple<Vector, int, int> > ln;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			ln.emplace_back(Vector {v[j].y - v[i].y, v[i].x - v[j].x}, i, j);
		}
	}
	sort(ln.begin(), ln.end());
	
	int64_t ans = 0;
	for (auto it: ln) {
		
		Vector dir; int ia, ib; tie(dir, ia, ib) = it;
		int a = r[ia], b = r[ib];
		if (getC(dir, v[0]) > getC(dir, v.back())) {
			dir.A *= -1;
			dir.B *= -1;
		}
		
		auto find = [&](int64_t nc) {
			auto iter = lower_bound(v.begin(), v.end(), Point {nc, LLONG_MIN}, [&](const Point &a, const Point &b) {
				assert(b.y == LLONG_MIN);
				return getC(dir, a) < b.x;
			});
			assert(iter != v.end() && iter+1 != v.end());
			int64_t l = iter - v.begin();
			int64_t r = n - l - 2;
			ans += l * (l-1) / 2 * r * (r-1) / 2;
		};
		
		assert(getC(dir, v[a]) == getC(dir, v[b]));
		find(getC(dir, v[a]));
		
		swap(v[a], v[b]);
		swap(p[a], p[b]);
		swap(r[ia], r[ib]);
	}
	
	cout << ans << endl;
	
	return 0;
}