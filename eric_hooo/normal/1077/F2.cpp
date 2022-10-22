#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[5010];
long long f[5010], g[5010];
int q[5010], l, r;

int main() {
	int n, k, m; scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n + 1; i++) {
		f[i] = -INF;
	}
	f[0] = 0;
	for (int it = 0; it < m + 1; it++) {
		l = r = 0;
		for (int i = 0; i <= n + 1; i++) {
			while (l < r && i - q[l] > k) l++;
			g[i] = l < r ? f[q[l]] + a[i] : -INF;
			while (l < r && f[q[r - 1]] < f[i]) r--;
			q[r++] = i;
		}
		for (int i = 0; i <= n + 1; i++) {
			f[i] = g[i];
		}
	}
	printf("%lld\n", max(-1ll, f[n + 1]));
	return 0;
}