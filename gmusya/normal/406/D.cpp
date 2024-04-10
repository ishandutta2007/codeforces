#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

struct Point {
	ll x, y;

	Point operator-(const Point& point) const {
		return {x - point.x, y - point.y};
	}

	ll operator%(const Point& point) const {
		return x * point.y - y * point.x;
	}

	friend istream& operator>>(istream& in, Point& point) {
		return in >> point.x >> point.y;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<Point> points(n);
	for (int i = 0; i < n; ++i) {
		cin >> points[i];
	}
	vector<int> p(n, n - 1);
	vector<int> convex_hull;
	for (int i = n - 1; i >= 0; --i) {
		while (convex_hull.size() >= 2) {
			int ind1 = convex_hull[convex_hull.size() - 2];
			int ind2 = convex_hull[convex_hull.size() - 1];
			if ((points[i] - points[ind1]) % (points[ind2] - points[ind1]) > 0) {
				convex_hull.pop_back();
			} else {
				break;
			}
		}
		if (i != n - 1) {
			p[i] = convex_hull.back();
		}
		convex_hull.push_back(i);
	}
	vector<int> d(n);
	d[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		d[i] = d[p[i]] + 1;
	}
	vector<int> lg(n + 1);
	for (int i = 2; i <= n; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	vector<vector<int>> up(lg[n] + 1, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		up[0][i] = p[i];
	}
	for (int pow = 1; pow <= lg[n]; ++pow) {
		for (int i = 0; i < n; ++i) {
			up[pow][i] = up[pow - 1][up[pow - 1][i]];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		if (d[u] < d[v]) {
			swap(u, v);
		}
		for (int pow = 0; pow <= lg[n]; ++pow) {
			if ((d[u] - d[v]) & (1 << pow)) {
				u = up[pow][u];
			}
		}
		if (u == v) {
			cout << u + 1 << ' ';
			continue;
		}
		for (int pow = lg[n]; pow >= 0; --pow) {
			if (up[pow][u] != up[pow][v]) {
				u = up[pow][u];
				v = up[pow][v];
			}
		}
		cout << p[u] + 1 << ' ';
	}
	return 0;
}