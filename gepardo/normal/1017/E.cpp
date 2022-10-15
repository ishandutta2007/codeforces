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
	
	auto ccw = [&](Point a, Point b, Point c) -> bool {
		return orientedSquare(a, b, c) > 0;
	};
	
	if (pts.size() < 3) {
		return pts;
	}
	sort(pts.begin(), pts.end(), [&](const Point &a, const Point &b) {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	});
	Point pUp = pts.front(), pDown = pts.back();
	vector<Point> up, down;
	up.push_back(pUp);
	down.push_back(pUp);
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
		if (i == (int)pts.size() -1 || ccw(pUp, pts[i], pDown)) {
			while (
				(int)down.size() >= 2 &&
				!ccw(down[(int)down.size()-2], down.back(), pts[i])
			) {
				down.pop_back();
			}
			down.push_back(pts[i]);
		}
	}
	for (int i = (int)down.size() - 2; i > 0; i--) {
		up.push_back(down[i]);
	}
	return up;
}

struct Triangle {
	Point a, b;
	
	Triangle()
		: a({0, 0}), b({0, 0}) {
	}
};

inline int64_t sqd(const Point &a, const Point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline bool zarro(const Triangle &a) {
	return !a.a.x && !a.a.y && !a.b.x && !a.b.y;
}

inline bool operator==(const Triangle &a, const Triangle &b) {
	if (zarro(a) || zarro(b)) {
		return zarro(a) == zarro(b);
	}
	return (
		sqd(a.a, {0, 0}) == sqd(b.a, {0, 0}) &&
		sqd(a.b, {0, 0}) == sqd(b.b, {0, 0}) &&
		sqd(a.a, a.b) == sqd(b.a, b.b)
	);
}

inline basic_string<Triangle> triangulate(const vector<Point> &v) {
	int n = v.size();
	basic_string<Triangle> res(n, Triangle());
	for (int i = 0; i < n; i++) {
		int j = (i+1) % n;
		int k = (i+2) % n;
		res[i].a = {v[i].x - v[j].x, v[i].y - v[j].y};
		res[i].b = {v[j].x - v[k].x, v[j].y - v[k].y};
	}
	return res;
}

template<typename Container>
vector<int> prefixFunction(const Container &s) {
	int n = s.size();
	vector<int> pi(n);
	pi[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && !(s[i] == s[j])) {
			j = pi[j-1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

inline bool test() {
	int n, m; cin >> n >> m;
	vector<Point> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].x >> b[i].y;
	}
	a = convexHull(a);
	b = convexHull(b);
	if (a.size() != b.size()) {
		return false;
	}
	n = a.size();
	auto t = triangulate(a) + Triangle() + triangulate(b) + triangulate(b);
	for (int i: prefixFunction(t)) {
		if (i == n) {
			return true;
		}
	}
	return false;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	cout << (test() ? "YES" : "NO") << endl;
	return 0;
}