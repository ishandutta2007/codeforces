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
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;

	long long x, y, t;
	cin >> x >> y >> t;

	vector<Point> pts;
	Point p = {x0, y0};
	while (p.x + p.y <= x + y + t) {
		pts.push_back(p);
		p = {p.x * ax + bx, p.y * ay + by};
	}

	int ans = 0;
	for (int i = 0; i < (int)pts.size(); ++i) {
		for (int j = 0; j < (int)pts.size(); ++j) {
			if (abs(x - pts[i].x) + abs(y - pts[i].y) + abs(pts[i].x - pts[j].x) + abs(pts[i].y - pts[j].y) <= t) {
				ans = max(ans, abs(i - j) + 1);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}