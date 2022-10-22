#include <bits/stdc++.h>
using namespace std;

int n, m;
int vis[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			vis[y] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				for (int j = 1; j <= n; j++) {
					if (i == j) continue;
					printf("%d %d\n", i, j);
				}
				break;
			}
		}
	}
	return 0;
}