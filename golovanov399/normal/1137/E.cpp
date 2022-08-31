#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Point {
	long long x, y;
};

const long long BASE = 1e18;
struct Li {
	long long x, y;

	Li(long long z): x(z / BASE), y(z % BASE) {}
	Li(long long _x, long long _y): x(_x), y(_y) {}

	pair<long long, long long> asPair() const {
		return {x, y};
	}

	bool operator <=(const Li& ot) const {
		return asPair() <= ot.asPair();
	}

	Li operator +(const Li& ot) const {
		long long new_x = x + ot.x;
		long long new_y = y + ot.y;
		new_x += new_y / BASE;
		new_y %= BASE;
		return {new_x, new_y};
	}
};

Li mult(long long a, long long b) {
	Li res = 0;
	Li _a = a;
	while (b) {
		if (b & 1ll) {
			res = res + _a;
		}
		b >>= 1;
		_a = _a + _a;
	}
	return res;
}

bool check(long long a, long long b, long long c, long long d) {
	//
	long double aa = a, bb = b, cc = c, dd = d;
	if (abs(aa * bb - cc * dd) > 1e18) {
		return aa * bb < cc * dd;
	} else {
		return a * b <= c * d;
	}
}

void normalize(vector<Point>& pts, long long s) {
	while (pts.size() >= 3) {
		int idx = (int)pts.size() - 3;
		// if ((pts[idx + 1].x - pts[idx].x) * (pts[idx + 2].y - pts[idx + 1].y) <=
		// 	(pts[idx + 1].y - pts[idx].y) * (pts[idx + 2].x - pts[idx + 1].x)) {
		if (check(pts[idx + 1].x - pts[idx].x, pts[idx + 2].y - pts[idx + 1].y,
				  pts[idx + 1].y - pts[idx].y,pts[idx + 2].x - pts[idx + 1].x)) {
			swap(pts[idx + 1], pts[idx + 2]);
			pts.pop_back();
		} else {
			break;
		}
	}
	while (pts.size() >= 2) {
		int idx = (int)pts.size() - 2;
		if (pts[idx].y <= pts[idx + 1].y + s * (pts[idx + 1].x - pts[idx].x)) {
			pts.pop_back();
		} else {
			break;
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	long long l = 0, r = n;
	
	long long overall_b = 0;
	long long overall_s = 0;
	vector<Point> pts = {{0, 0}};
	for (int i = 0; i < m; ++i) {
		int t = nxt();
		if (t == 1) {
			int k = nxt();
			l -= k;
			overall_b -= overall_s * k;
			overall_b = 0;
			overall_s = 0;
			pts = {{l, 0}};
		} else if (t == 2) {
			int k = nxt();
			pts.push_back({r, -overall_b - overall_s * (r - l)});
			r += k;
			normalize(pts, overall_s);
		} else {
			long long b = nxt(), s = nxt();
			overall_b += b;
			overall_s += s;
			normalize(pts, overall_s);
		}
		// for (auto x : pts) {
		// 	cerr << "(" << x.x << ", " << x.y + overall_b + overall_s * (x.x - l) << ") ";
		// }
		// cerr << "\n";

		printf("%lld %lld\n", pts.back().x - l + 1, pts.back().y + overall_b + overall_s * (pts.back().x - l));
	}

	return 0;
}