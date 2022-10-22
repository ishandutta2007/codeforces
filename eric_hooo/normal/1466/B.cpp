#include <bits/stdc++.h>
using namespace std;

int vis[200010];
int a[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) {
			vis[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			vis[a[i]]++;
		}
		int ans = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (vis[i] == 0) continue;
			int j = i, sum = 0;
			while (j <= 2 * n && vis[j]) sum += vis[j], j++;
			ans += min(sum, j - i + 1);
			i = j - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}