/*input
7
0 0
0 1000
1 1000
1000 999
1001 1
1000 0
1 -1
*/
#include <bits/stdc++.h>

using namespace std;

long double din[2][2500][2500];
int n;
struct Point {
	long double x, y;
	long double dist(const Point &o)const {
		return sqrtl((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
	}
};

Point p[2500];

#define next(a) (((a)+1)%n)
#define prev(a) (((a)-1+n)%n)

long double atstum(bool kur, int a, int b) {
	if (din[kur][a][b] >= -0.5l)
		return din[kur][a][b];

	if (a == b)
		return din[kur][a][b] = 0;

	if (kur == 0)
		din[0][a][b] = max(p[a].dist(p[b]) + atstum(1, next(a), b), p[a].dist(p[next(a)]) + atstum(0, next(a), b));
	else
		din[1][a][b] = max(p[b].dist(p[a]) + atstum(0, a, prev(b)), p[b].dist(p[prev(b)]) + atstum(1, a, prev(b)));

	return din[kur][a][b];
}

int main () {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			din[0][i][j] = din[1][i][j] = -1;
	}

	long double ma = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			ma = max(ma, p[i].dist(p[j]) + atstum(0, i, prev(j)) + atstum(0, j, prev(i)));
			ma = max(ma, p[i].dist(p[j]) + atstum(1, next(i), j) + atstum(1, next(j), i));
		}
	}

	cout << fixed << setprecision(10) << ma;

	return 0;
}