#include <bits/stdc++.h>
using namespace std;

int row[100010], col[100010];

int main() {
	int n; scanf("%d", &n);
	for (int k = 1; k <= n; k++) {
		if ((n - k) * 2 - 1 <= k) {
			printf("%d\n", k);
			int t = n - k;
			for (int i = 1; i <= t; i++) {
				printf("%d %d\n", n - i + 1, n - t + i);
				assert(!row[n - i + 1] && !col[n - t + i]);
				row[n - i + 1] = 1, col[n - t + i] = 1;
			}
			for (int i = 1; i < t; i++) {
				printf("%d %d\n", t + t - i, t + i);
				assert(!row[t + t - i] && !col[t + i]);
				row[t + t - i] = 1, col[t + i] = 1;
			}
			int j = t + 1;
			for (int i = t + 1; i <= n; i++) {
				if (row[i]) continue;
				while (col[j]) j++;
				col[j] = 1;
				printf("%d %d\n", i, j);
			}
			return 0;
		}
	}
	return 0;
}