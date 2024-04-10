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

signed main() {
	setup();
	
	Point a, b;
	int r;
	cin >> r;
	cin >> a.x >> a.y >> b.x >> b.y;
	// cout << sqrt(dist(a, b)) << '\n';	
	cout << (int) (sqrt(dist(a, b)) + 2 * r - 1e-6) / (2 * r);

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}