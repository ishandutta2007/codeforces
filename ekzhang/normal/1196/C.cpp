#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define INF 100000
int Q, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		cin >> N;
		int minx = -INF, maxx = INF, miny = -INF, maxy = INF;
		while (N--) {
			int x, y, a, b, c, d;
			cin >> x >> y >> a >> b >> c >> d;
			if (!a) minx = max(minx, x);
			if (!b) maxy = min(maxy, y);
			if (!c) maxx = min(maxx, x);
			if (!d) miny = max(miny, y);
		}
		if (minx > maxx || miny > maxy)
			cout << 0 << '\n';
		else
			cout << 1 << ' ' << minx << ' ' << miny << '\n';
	}

	cout.flush();
	return 0;
}