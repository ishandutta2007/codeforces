#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, L, a[N];

double f[N], g[N];

double inline val(int i, int t) {
	return max(f[i] + (t - a[i]) / ((double)i + 1), g[i + 1] + (a[i + 1] - t) / (1.0 + (n - i)));
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &L);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		double v = 1, last = 0;
		for (int i = 1; i <= n; i++) {
			f[i] = f[i - 1] + (a[i] - last) / v;
			last = a[i], v++;
		}
		v = 1, last = L;
		g[n + 1] = 0;
		for (int i = n; i; i--) {
			g[i] = g[i + 1] + (last - a[i]) / v;
			last = a[i], v++;
		}
		double ans = 2e9;
		a[n + 1] = L;
		for (int i = 0; i <= n; i++) {
			if (f[i] <= g[i] && f[i + 1] >= g[i + 1]) {
				double v1 = i + 1, v2 = n - i + 1;
				ans = ((f[i] - g[i + 1]) * v1 * v2 - v1 * a[i + 1] - v2 * a[i]) / (- v1 - v2);
				ans = f[i] + (ans - a[i]) / v1;
			}
		}
		printf("%.13f\n", ans);
	}	
	return 0;
}