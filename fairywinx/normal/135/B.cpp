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

bool its_pr(Point a, Point b, Point c, Point d) {
	return (d - a) * (b - a) == 0 && (b - c) * (d - c) == 0;
}

bool its_kv(Point a, Point b, Point c, Point d) {
	if (!its_pr(a, b, c, d))
		return false;
	return (c - a) * (d - b) == 0;
}

bool rek_per1(vector<Point> &now, int kol, vector<Point> &can, vector<int> &used) {
	if (kol == can.size())
		return its_pr(now[0], now[1], now[2], now[3]);
	for(int i = 0; i < can.size(); ++i) {
		if (!used[i]) {
			now.push_back(can[i]);
			used[i] = 1;
			if (rek_per1(now, kol + 1, can, used)) {
				used = vector<int> (can.size());
				now = vector<Point> ();
				return true;
			}
			used[i] = 0;
			now.pop_back();
		}
	}
	return false;
}

bool rek_per2(vector<Point> &now, int kol, vector<Point> &can, vector<int> &used) {
	if (kol == can.size())
		return its_kv(now[0], now[1], now[2], now[3]);
	for(int i = 0; i < can.size(); ++i) {
		if (!used[i]) {
			now.push_back(can[i]);
			used[i] = 1;
			if (rek_per2(now, kol + 1, can, used)) {
				used = vector<int> (can.size());
				now = vector<Point> ();
				return true;
			}
			used[i] = 0;
			now.pop_back();
		}
	}
	return false;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

signed main() {
	setup();
	
	int n = 8;
	vector<Point> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;

	for(int mask = 0; mask < (1 << n); ++mask) {
		vector<Point> kv;
		vector<int> kv1;
		vector<int> pr1;
		vector<Point> pr;
		for(int i = 0; i < n; ++i) {
			if ((1 << i) & mask) {
				kv1.push_back(i);
				kv.push_back(a[i]);
			}
			else {
				pr1.push_back(i);
				pr.push_back(a[i]);
			}
		}
		if (kv.size() != 4)
			continue;
		vector<Point> z;
		vector<int> used(4);
		if (rek_per1(z, 0, pr, used) && rek_per2(z, 0, kv, used)) {
			cout << "YES\n";
			for(auto i: kv1)
				cout << i + 1 << ' ';
			cout << '\n';
			for(auto i: pr1) 
				cout << i + 1 << ' ';
			cout << '\n';
			return 0;
		}
	}
	cout << "NO\n";

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}