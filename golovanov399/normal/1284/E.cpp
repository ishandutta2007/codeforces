#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Point {
	long long x, y;
	int id;

	Point operator -(const Point& p) const {
		return {x - p.x, y - p.y, id};
	}

	long long sprod(const Point& p) const {
		return x * p.x + y * p.y;
	}

	long long vprod(const Point& p) const {
		return x * p.y - y * p.x;
	}

	int half() const {
		if (y) {
			return y < 0;
		} else {
			return x < 0;
		}
	}

	bool operator <(const Point& p) const {
		if (half() != p.half()) {
			return !half();
		} else {
			return vprod(p) > 0;
		}
	}
};


int main() {
	int n = nxt();
	vector<Point> pts(n);
	for (int i = 0; i < n; ++i) {
		pts[i].x = nxt();
		pts[i].y = nxt();
		pts[i].id = i;
	}
	long long ans = 1ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
	for (int i = 0; i < n; ++i) {
		vector<Point> a = pts;
		a.erase(a.begin() + i);
		for (auto& p : a) {
			p = p - pts[i];
		}
		sort(all(a));
		int cnt = 0;
		int r = 0;
		for (int j = 0; j < n - 1; ++j) {
			while (cnt < n - 1 && a[j].vprod(a[r]) >= 0) {
				r += 1;
				if (r == n - 1) {
					r = 0;
				}
				++cnt;
			}
			ans -= 1ll * (cnt - 1) * (cnt - 2) * (cnt - 3) / 6;
			--cnt;
		}
	}

	cout << ans << "\n";

	return 0;
}