#include <bits/stdc++.h>
using namespace std;

int a[100010];
int deg[100010], id[100010];
long long ans[100010];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			id[i] = i, deg[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			deg[x]++, deg[y]++;
		}
		sort(id + 1, id + n + 1, cmp);
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += 1ll * a[i] * deg[i];
		}
		ans[n - 1] = sum;
		int cur = 1;
		for (int i = n - 2; i >= 1; i--) {
			while (deg[id[cur]] == 1) cur++;
			ans[i] = ans[i + 1] - a[id[cur]], deg[id[cur]]--;
		}
		for (int i = 1; i <= n - 1; i++) {
			printf("%I64d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}