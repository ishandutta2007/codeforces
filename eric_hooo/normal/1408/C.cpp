#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-8;

int a[100010];
long double t1[100010], t2[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, L; scanf("%d%d", &n, &L);
		a[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		a[n + 1] = L, n += 2;
		t1[0] = 0;
		for (int i = 1; i < n; i++) {
			t1[i] = t1[i - 1] + (long double)(a[i] - a[i - 1]) / i;
		}
		t2[n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) {
			t2[i] = t2[i + 1] + (long double)(a[i + 1] - a[i]) / (n - 1 - i);
		}
		int pos = 0;
		while (pos < n && t1[pos] < t2[pos]) pos++; pos--;
		long double l = max(t1[pos], t2[pos + 1]), r = 2000000000;
		long double v1 = pos + 1, v2 = n - 1 - pos;
		while (l + EPS < r) {
			long double mid = (l + r) / 2;
			long double p1 = a[pos] + (mid - t1[pos]) * v1, p2 = a[pos + 1] - (mid - t2[pos + 1]) * v2;
			if (p1 < p2) l = mid + EPS;
			else r = mid;
		}
		printf("%.15f\n", (double)l);
	}
	return 0;
}