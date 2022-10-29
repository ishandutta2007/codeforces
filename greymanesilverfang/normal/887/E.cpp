// Problem: Given n non-intersecting circles and 2 points, the line through which goes through no circle.
// Draw the smallest circle going through the 2 points that does not intersect any other ones.

#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ld long double
using namespace std;
const ld INF = 1e12, epsilon = 1e-8; 
ld Y_AXIS, res = INF;
vector< pair<ld, bool> > forbid;

inline ld sqr(ld x) { return x * x; }
inline ld dist(ld x1, ld y1, ld x2 = 0, ld y2 = 0) { return sqr(x1 - x2) + sqr(y1 - y2); }
inline ld area(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) { return (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2); }
inline void mini(ld &a, ld b) { if (a > b) a = b; }

ld binsearch(ld x, ld y, int r) {
	ld L = -INF, R = INF, mid;
	while (L + epsilon < R) {
		mid = (L + R) / 2;
		(sqrt(dist(x, y, mid)) + r < sqrt(dist(mid, Y_AXIS)) ^ x < 0 ? R : L) = mid;
	}
	// printf("%Lf %Lf %d %Lf %Lf\n", x, y, r, mid, sqrt(dist(mid, Y_AXIS)));
	// printf("%.12Lf\n", sqrt(dist(x, y, mid)) + r - sqrt(dist(mid, Y_AXIS)));
	return mid;
}

bool check_zero() {
	int cnt = 0;
	for (pair<ld, bool> info : forbid)
		if (abs(++cnt -= (info.first > 0 ^ info.second) << 1) > 1)
			return false;
	return true;
}

int main() {
	int x1, y1, x2, y2, n; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
	Y_AXIS = sqrt(dist(x1, y1, x2, y2)) / 2;
	for (int i = 0; i < n; ++i) {
		int x, y, r; scanf("%d%d%d", &x, &y, &r);
		ld xx = area(x, y, x1, y1, x2, y2) / Y_AXIS / 2;
		ld yy = sqrt(dist(x, y, (x1 + x2) / 2.0, (y1 + y2) / 2.0) - sqr(xx));
		// printf("%.12Lf\n", sqr(yy) + sqr(xx));
		forbid.push_back(make_pair(binsearch(xx, yy,  r), xx > 0));
		forbid.push_back(make_pair(binsearch(xx, yy, -r), xx < 0));
	}
	if (check_zero()) {
		printf("%.9Lf", Y_AXIS);
		return 0;
	}
	sort(forbid.begin(), forbid.end());
	int cnt = 0;
	for (pair<ld, bool> info : forbid)
		if (info.second && !--cnt || !info.second && !cnt++)
			mini(res, sqrt(dist(info.first, Y_AXIS)));
	printf("%.9Lf", res);
	return 0;
}