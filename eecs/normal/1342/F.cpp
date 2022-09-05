#include <bits/stdc++.h>
using namespace std;

int T, n, a[15], f[16][1 << 15][15], sum[1 << 15], nxt[1 << 15][15], used[15];
pair<int, int> pre[16][1 << 15][15];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 1 << n; j++) {
				for (int k = 0; k < n; k++) f[i][j][k] = INT_MAX;
			}
		}
		for (int i = 1; i < 1 << n; i++) {
			int j = __builtin_ctz(i);
			sum[i] = sum[i ^ (1 << j)] + a[j];
			for (int j = n - 1, k = -1; ~j; j--) {
				nxt[i][j] = k;
				if (i >> j & 1) k = j;
			}
		}
		for (int i = 1; i < 1 << n; i++) {
			f[1][i][__builtin_ctz(i)] = sum[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 1 << n; j++) {
				int S = ((1 << n) - 1) ^ j;
				for (int k = 0; k < n; k++) if (f[i][j][k] < INT_MAX) {
					for (int T = S; T; T = (T - 1) & S) if (f[i][j][k] < sum[T]) {
						if (~nxt[T][k] && f[i + 1][j | T][nxt[T][k]] > sum[T]) {
							f[i + 1][j | T][nxt[T][k]] = sum[T];
							pre[i + 1][j | T][nxt[T][k]] = {j, k};
						}
					}
				}
			}
		}
		fill(used, used + n, 0);
		auto op = [&](int i, int j) {
			int _i = 0, _j = 0;
			for (int k = 0; k <= i; k++) {
				if (!used[k]) _i++;
			}
			for (int k = 0; k <= j; k++) {
				if (!used[k]) _j++;
			}
			printf("%d %d\n", _i, _j), used[i] = 1;
		};
		for (int i = n; i; i--) {
			for (int k = 0; k < n; k++) if (f[i][(1 << n) - 1][k] < INT_MAX) {
				printf("%d\n", n - i);
				for (int j = (1 << n) - 1; i; i--) {
					auto p = pre[i][j][k];
					int S = j ^ p.first;
					for (int x = 0; x < n; x++) {
						if ((S >> x & 1) && x ^ k) op(x, k);
					}
					j = p.first, k = p.second;
				}
				goto nxt;
			}
		}
		nxt:;
	}
	return 0;
}