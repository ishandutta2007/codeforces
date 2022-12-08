#include <bits/stdc++.h>

using namespace std;
#define N 1001

int T, n, k, a[N][N], b[N], c[N][N], d[N][N], ans[N][N];

bool solve() {
	for (int i, j = 1; j <= k; ++j) {
		i = b[j - 1] + 1;
		while (i <= n && (!a[i][i] ||
			c[1][j - 1] + 1 > i || d[1][j - 1] + 1 > i)) ++i;
		if (i > n) return 0;
		c[0][j] = d[0][j] = b[j] = i;
		for (int t = 1; t <= k - j; ++t) {
			i = c[t - 1][j];
			while (i + t <= n && (!a[i][i + t] ||
				c[t + 1][j - 1] + 1 > i)) ++i;
			if ((i + t) > n) return 0;
			c[t][j] = i;
			i = d[t - 1][j];
			while (i + t <= n && (!a[i + t][i] ||
				d[t + 1][j - 1] + 1 > i)) ++i;
			if ((i + t) > n) return 0;
			d[t][j] = i;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		k = n - k + 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%1d", &a[i][j]);
		if (!solve()) {
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				ans[i][j] = 1;
		for (int i = 1; i <= k; ++i)
			ans[b[i]][b[i]] = 0;
		for (int i = 1; i < k; ++i)
			for (int j = 1; j <= k - i; ++j)
				ans[c[i][j]][c[i][j] + i] = 0;
		for (int i = 1; i < k; ++i)
			for (int j = 1; j <= k - i; ++j)
				ans[d[i][j] + i][d[i][j]] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				putchar(ans[i][j] + '0');
			puts("");
		}
	}
	return 0;
}