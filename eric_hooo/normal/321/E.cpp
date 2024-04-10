#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[4010][4010], rng[4010][4010];
int f[4010], g[4010];

int calc(int x, int y) {
	return y >= x ? INF : f[y] + rng[y + 1][x];
}

void solve(int l, int r, int L, int R) {
	if (l > r) return ;
	int mid = l + r >> 1;
	int p = -1;
	for (int i = L; i <= R; i++) {
		int val = calc(mid, i);
		if (g[mid] > val) {
			g[mid] = val, p = i;
		}
	}
	solve(l, mid - 1, L, p), solve(mid + 1, r, p, R);
}

int main () {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			rng[i][j] = a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1];
			rng[i][j] /= 2;
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int it = 0; it < k; it++) {
		memset(g, 0x3f, sizeof(g));
		solve(it + 1, n, it, n - 1);
		swap(f, g);
	}
	printf("%d\n", f[n]);
	return 0;
}