#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

const ll INF = (ll)1000000000000000000;

struct point {
	ll x, y;
};
int main() {
	ll MAXN;
	ll x0, y0, ax, ay, bx, by;
	ll xs, ys, t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	vector <point> points(100);
	points[0] = { x0, y0 };
	for (ll i = 1; i < 100; i++) {
		points[i].x = ax * points[i - 1].x + bx;
		points[i].y = ay * points[i - 1].y + by;
		if ((INF - bx) / ax / points[i - 1].x == 0 || (INF - by) / ay / points[i - 1].y == 0) {
			MAXN = i;
			break;
		}
	}
	ll ans = 0;
	for (ll i = 0; i < MAXN; i++) {
		if (abs(xs - points[i].x) + abs(ys - points[i].y) > t)
			continue;
		ll cnt = 1;
		ll mt = t - (abs(xs - points[i].x) + abs(ys - points[i].y));
		for (ll j = i - 1; j >= 0 && mt > 0; j--) {
			mt -= abs(points[j + 1].x - points[j].x) + abs(points[j + 1].y - points[j].y);
			if (mt >= 0)
				cnt++;
		}
		ans = max(ans, cnt);
		cnt = 1;
		mt = t - (abs(xs - points[i].x) + abs(ys - points[i].y));
		for (ll j = i + 1; j < MAXN && mt > 0; j++) {
			mt -= abs(points[j].x - points[j - 1].x) + abs(points[j].y - points[j - 1].y);
			if (mt >= 0)
				cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}