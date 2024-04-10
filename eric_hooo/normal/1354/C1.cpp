#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const double pi = 3.1415926535898;

typedef pair <double, double> pdd;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		pdd del = mp(1, 0), now(0, 0);
		double the = 360.0 / n / 2; the = the / 180 * pi;
		double S = sin(the), C = cos(the);
		for (int i = 0; i < n / 2; i++) {
			pdd tmp(del.fi * C - del.se * S, del.fi * S + del.se * C);
			del = tmp;
			now.fi += del.fi, now.se += del.se;
		}
		printf("%.8f\n", now.se * 2 - 1);
	}
	return 0;
}