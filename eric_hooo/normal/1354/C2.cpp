#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const double pi = 3.1415926535898;
const double sqrt2 = 1.41421356237;

typedef pair <double, double> pdd;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		pdd del = mp(1, 0), now(0, 0);
		double the = 360.0 / n / 2; the = the / 180 * pi;
		double S = sin(the), C = cos(the);
		for (int i = 0; i < n; i++) {
			now.fi += del.fi, now.se += del.se;
			pdd tmp(del.fi * C - del.se * S, del.fi * S + del.se * C);
			del = tmp;
		}
		pdd mid(now.fi / 2, now.se / 2);
		double ans = -1;
		for (int i = 0; i < (n + 1) / 2; i++) {
			now.fi += del.fi, now.se += del.se;
			pdd tmp(del.fi * C - del.se * S, del.fi * S + del.se * C);
			del = tmp;
			ans = max(ans, (now.se + mid.fi - now.fi - mid.se) * sqrt2);
		}
		printf("%.8f\n", ans);
	}
	return 0;
}