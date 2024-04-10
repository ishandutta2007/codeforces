// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, a[N], b[N], t1, t2;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		t1 = t2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			if (x == 0) a[++t1] = abs(y);
			else b[++t2] = abs(x);
		}
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		double ans = 0;
		for (int i = 1; i <= n; i++)
			ans += sqrt((double)a[i] * a[i] + (double)b[i] * b[i]);
		printf("%.10lf\n", ans);
	}
	return 0;
}