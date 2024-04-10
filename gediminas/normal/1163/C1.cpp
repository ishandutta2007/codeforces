#include <bits/stdc++.h>

using namespace std;
/*input
4
0 0
1 1
0 3
1 2
*/
/*input
4
0 0
0 2
0 4
2 0
*/
/*input
3
-1 -1
1 0
3 1
*/
struct Point {
	long long x, y;
	Point() {}
	Point(long long x, long long y): x(x), y(y) {}
	Point operator-(Point b) {
		return Point(x - b.x, y - b.y);
	}
	Point norm() {
		long long gc = __gcd(x, y);
		Point t(x / gc, y / gc);

		if (t.x < 0) {
			t.x *= -1;
			t.y *= -1;
		}
		else if (t.x == 0) {
			t.y = 1;
		}

		return t;
	}
	bool operator<(const Point &b)const {
		if (x == b.x) {
			return y < b.y;
		}

		return x < b.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	Point a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
	}

	int ats = 0;

	map<Point, vector<Point>> t;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			t[(a[j] - a[i]).norm()].push_back(a[i]);
		}
	}

	long long vis = 0;
	long long mi = 0;

	for (auto &&[b, s] : t) {
		for (int i = 0; i < (long long)s.size();) {
			bool blog = false;

			for (int j = 0; j < i; ++j) {
				auto v = s[i] - s[j];

				if (v.x * b.y == v.y * b.x) {
					blog = true;
					break;
				}
			}

			if (blog) {
				s.erase(s.begin() + i);
			}
			else {
				++i;
			}
		}

		vis += (long long)s.size();

		if (s.size() > 0) {
			mi += ((long long)s.size() - 1) * ((long long)s.size()) / 2;
		}
	}

	cout << vis*(vis - 1) / 2 - mi << endl;
}