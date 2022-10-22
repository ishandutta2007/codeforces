#include <bits/stdc++.h>
using namespace std;
int main () {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	int t1 = n - m, t2 = -k - 1;
	if (t1 <= t2) {
		printf("0.000000\n");
		return 0;
	}
	t1 = t2 * 2 - t1;
	int x = t1 + n + m >> 1, y = n + m - t1 >> 1;
	if (x < 0 || y < 0) {
		printf("1.000000\n");
		return 0;
	}
	long double ans = 1; // C(x + y, x) / C(n + m, n)
	for (int i = 1; i <= max(x, n); i++) {
		if (i <= x) ans *= (x + y - i + 1);
		if (i <= n) ans /= (n + m - i + 1);
		if (i <= n) ans *= i;
		if (i <= x) ans /= i;
	}
	printf("%.6f\n", (double)(1 - ans));
	return 0;
}