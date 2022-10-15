#include <vector>
#include <algorithm>
#include <cstdint>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

const int infinity = 1234567890;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct ConvexHullLine {
	int64_t a, b;
	
	inline int64_t f(int64_t x) {
		return a*x + b;
	}
	
	ConvexHullLine() {
	}
	
	ConvexHullLine(int64_t a, int64_t b)
		: a(a), b(b) {
	}
};

inline bool operator<(ConvexHullLine a, ConvexHullLine b) {
	return make_pair(a.a, -a.b) < make_pair(b.a, -b.b);
}

class ConvexHullTrick {
	private:
		vector<ConvexHullLine> convexHull;
		
		inline void add(ConvexHullLine ln) {
			while (convexHull.size() > 1) {
				ConvexHullLine
					_1 = convexHull[convexHull.size() - 2],
					_2 = convexHull[convexHull.size() - 1],
					_3 = ln;
				if ((_2.a - _1.a) * (_2.b - _3.b) <=
				    (_1.b - _2.b) * (_3.a - _2.a)) {
					convexHull.pop_back();
				} else {
					break;
				}
			}
			convexHull.push_back(ln);
		}
	public:
		inline int64_t query(int64_t x) {
			int l = 0, r = (int)convexHull.size() - 1;
			while (l < r) {
				int m = (l + r) / 2;
				if (convexHull[m].f(x) >
				    convexHull[m+1].f(x)) {
					r = m;
				} else {
					l = m+1;
				}
			}
			return convexHull[l].f(x);
		}
		
		ConvexHullTrick(vector<ConvexHullLine> lines) {
			sort(lines.begin(), lines.end());
			convexHull.clear();
			for (ConvexHullLine ln: lines) {
				add(ln);
			}
		}
};

signed main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int64_t> a(n), p(n+1);
	vector<ConvexHullLine> lines;
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i] * (i+1);
	}
	p[0] = 0;
	for (int i = 0; i < n; i++) {
		p[i+1] = p[i] + a[i];
	}
	for (int i = 0; i <= n; i++) {
		lines.emplace_back(i, -p[i]);
	}
	ConvexHullTrick trick(lines);
	int64_t add = 0;
	for (int i = 0; i < n; i++) {
		add = max(add, trick.query(a[i]) + p[i] - a[i] * i);
	}
	cout << ans + add << endl;
	return 0;
}