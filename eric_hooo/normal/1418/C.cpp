#include <bits/stdc++.h>
using namespace std;

int a[200010];
int f[200010], g[200010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		g[0] = 0, f[0] = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			f[i] = g[i - 1] + a[i], g[i] = f[i - 1];
			if (i > 1) f[i] = min(f[i], g[i - 2] + a[i] + a[i - 1]);
			if (i > 1) g[i] = min(g[i], f[i - 2]);
		}
		printf("%d\n", min(f[n], g[n]));
	}
	return 0;
}