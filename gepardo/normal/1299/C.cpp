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

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

struct Point {
	int64_t x, y;
	
	Point() {
	}
	
	Point(int64_t x, int64_t y)
		: x(x), y(y) {
	}
};

inline int64_t orientedSquare(const Point &a, const Point &b, const Point &c) {
	return (a.x - b.x) * (a.y - c.y) - (a.x - c.x) * (a.y - b.y);
}

vector<Point> convexHull(vector<Point> pts) {
	auto cw = [&](Point a, Point b, Point c) -> bool {
		return orientedSquare(a, b, c) < 0;
	};
	
	if (pts.size() < 3) {
		return pts;
	}
	sort(pts.begin(), pts.end(), [&](const Point &a, const Point &b) {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	});
	Point pUp = pts.front(), pDown = pts.back();
	vector<Point> up;
	up.push_back(pUp);
	for (int i = 1; i < (int)pts.size(); i++) {
		if (i == (int)pts.size() - 1 || cw(pUp, pts[i], pDown)) {
			while (
				(int)up.size() >= 2 &&
				!cw(up[(int)up.size()-2], up.back(), pts[i])
			) {
				up.pop_back();
			}
			up.push_back(pts[i]);
		}
	}
	return up;
}

signed main() {
	int n; scanf("%d", &n);
	int64_t p = 0;
	vector<Point> v(n+1);
	vector<double> res(n);
	v[0] = {0, 0};
	for (int i = 1; i <= n; ++i) {
		int h; scanf("%d", &h);
		p += h;
		v[i] = {i, -p};
		res[i-1] = h;
	}
	auto hull = convexHull(v);
	for (int i = 1; i < (int)hull.size(); ++i) {
		double sum = 0;
		for (int j = hull[i-1].x; j < hull[i].x; ++j) {
			sum += res[j];
		}
		sum /= hull[i].x - hull[i-1].x;
		for (int j = hull[i-1].x; j < hull[i].x; ++j) {
			printf("%.10f\n", sum);
		}
	}
	return 0;
}