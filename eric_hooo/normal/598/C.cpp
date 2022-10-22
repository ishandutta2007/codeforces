#include <bits/stdc++.h>
#define double long double
using namespace std;

const double pi = 3.141592653589793238462643383279;

struct Point {
	int x, y, id;
	double arg;
	bool operator < (const Point &A) const {
		return arg < A.arg;
	}
}a[100010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].arg = acos(1.0 * a[i].x / sqrt((double)a[i].x * a[i].x + a[i].y * a[i].y));
		a[i].id = i;
		if (a[i].y < 0) a[i].arg = 2 * pi - a[i].arg;
	}
	sort(a, a + n);
	int x = a[0].id, y = a[n - 1].id;
	double arg = a[0].arg + 2 * pi - a[n - 1].arg;
	for (int i = 1; i < n; i++) {
		double tmp = a[i].arg - a[i - 1].arg;
		if (tmp < arg) arg = tmp, x = a[i].id, y = a[i - 1].id;
	}
	printf("%d %d\n", x + 1, y + 1);
	return 0;
}