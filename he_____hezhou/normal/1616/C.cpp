#include <bits/stdc++.h>
using namespace std;
int T, n, a[75];
int check(int a, int b, int c, int x, int y, int z) {
	return (b - a) * (z - y) == (c - b) * (y - x);
}
void rmain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int ans = n - 1;
	for (int x = 1; x <= n; x++)
		for (int y = x + 1; y <= n; y++) {
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				if (!check(x, y, i, a[x], a[y], a[i])) cur++;
			}
			ans = min(ans, cur);
		}
	printf("%d\n", ans);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}