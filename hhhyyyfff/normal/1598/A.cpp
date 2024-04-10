#include <bits/stdc++.h>

using namespace std;

int t, n, a[2][100];

void dfs(int x, int y) {
	if (x < 0 || x > 1 || y < 0 || y >= n || a[x][y] != 0) return;
	a[x][y] = 2;
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
			dfs(x + i, y + j);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%1d", &a[i][j]);
		if (a[0][0] == 1) {
			puts("NO");
			continue;
		}
		dfs(0, 0);
		puts(a[1][n - 1] == 2 ? "YES" : "NO");
	}
	return 0;
}