#include <cmath>
#include <cstdio>

using namespace std;

int sq(int x) {
	return x * x;
}

int main() {
	int r, d, n, ans = 0;
	scanf("%d%d%d", &r, &d, &n);
	d = r - d;
	while (n--) {
		int x, y, ri;
		scanf("%d%d%d", &x, &y, &ri);
		if (sq(x) + sq(y) <= sq(ri))
			continue;
		double dis = sqrt(sq(x) + sq(y));
		if (dis - ri >= d && dis + ri <= r)
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}