#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <cmath>

// #include <algorithm>
#define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) {x = _x, y = _y;}
};

Point operator+ (const Point &a, const Point &b) {
	return {a.x + b.x, a.y + b.y};
}

Point operator- (const Point &a, const Point &b) {
	return {a.x - b.x, a.y - b.y};
}

Point operator* (const Point &a, const int &b) {
	return {a.x * b, a.y * b};
}

int operator* (const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}

int operator^ (const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

int dist(const Point &a, const Point &b) {
	return (a - b) * (a - b);
}

const double pi = 3.141592653589793238462643;

signed main() {
	setup();
	
	int n;
	cin >> n;
	Point O;
	cin >> O.x >> O.y;
	vector<Point> c;
	int mx = 0;
	int mn = 1e15;
	for(int i = 0; i < n; ++i) {
		Point a;
		cin >> a.x >> a.y;
		c.push_back(a);
		mx = max(dist(O, a), mx);
		mn = min(dist(O, a), mn);
	}
	double z = sqrt(mn);
	for(int i = 0; i < n; ++i) {
		Point a = c[i];
		Point b = c[(i + 1) % n];
		if ((b - a) * (O - a) >= 0 && (a - b) * (O - b) >= 0) {
			// cout << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << '\n';
			double s = (double) abs((b - a) ^ (O - a));
			// cout << s << ' ';
			s = (double) s / sqrt(dist(a, b));
			z = min(s, z);
		}
	}

	// cout << z << ' ';

	cout << setprecision(15) << pi * (mx - z * z);

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}