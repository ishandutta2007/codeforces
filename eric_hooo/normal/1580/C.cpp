#include <bits/stdc++.h>
using namespace std;

int X[200010], Y[200010];
int beg[200010];
int sum[450][200010];
int ans[200010];

void Calc(int l, int r, int x, int y) {
	int k = x + y;
	if (1ll * k * k <= r - l + 1) {
		int tl = l % k, tr = (r - l) % k;
		for (int t = x; t < k; t++) {
			sum[k][l + t]++;
			int nr = r + (t - tr + k) % k;
			if (nr < 200005) sum[k][nr]--;
		}
	} else {
		for (int i = l; i < r; i += k) {
			if (i + x < r) {
				ans[i + x]++, ans[min(i + k, r)]--;
			}
		}
	}
}

int main() {
	memset(beg, -1, sizeof(beg));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &X[i], &Y[i]);
	}
	for (int i = 1; i <= m; i++) {
		int op, x; scanf("%d%d", &op, &x);
		if (beg[x] == -1) beg[x] = i;
		else {
			Calc(beg[x], i, X[x], Y[x]);
			beg[x] = -1;
		}
	}
	for (int x = 1; x <= n; x++) {
		if (beg[x] != -1) {
			Calc(beg[x], m + 1, X[x], Y[x]);
			beg[x] = -1;
		}
	}
	for (int i = 1; i <= m; i++) {
		ans[i] += ans[i - 1];
	}
	for (int i = 1; i < 450; i++) {
		for (int j = 1; j <= m; j++) {
			if (j > i) sum[i][j] += sum[i][j - i];
			ans[j] += sum[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}