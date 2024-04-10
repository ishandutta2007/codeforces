#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int a[MAXN], n, T;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int u, v; scanf("%d%d", &u, &v);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		int ans = 2e9;
		for (int i = 1; i <= n; i++) {
			if (i > 1 && abs(a[i] - a[i - 1]) >= 2) {
				ans = 0; break;
			}
		}
		if (ans == 0) {
			printf("%d\n", ans);
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (i < n) {
				if (a[i] == a[i + 1]) ans = min(ans, v + min(u, v));
				else ans = min(ans, min(u, v));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}