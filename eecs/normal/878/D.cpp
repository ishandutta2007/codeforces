#include <bits/stdc++.h>
using namespace std;

int n, K, q, a[12][100010], pos[12];
bitset<4096> b[110000];

int main() {
	scanf("%d %d %d", &n, &K, &q);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 1 << K; j++) {
			if (j >> i & 1) b[i].set(j);
		}
	}
	int tot = K - 1;
	for (int i = 0, op, x, y; i < q; i++) {
		scanf("%d %d %d", &op, &x, &y), x--, y--;
		if (op == 1) {
			b[++tot] = b[x] | b[y];
		} else if (op == 2) {
			b[++tot] = b[x] & b[y];
		} else {
			for (int j = 0; j < K; j++) {
				pos[j] = j;
			}
			sort(pos, pos + K, [&](int u, int v) { return a[u][y] < a[v][y]; });
			int mask = 0;
			for (int j = K - 1; ~j; j--) {
				mask |= 1 << pos[j];
				if (b[x].test(mask)) { printf("%d\n", a[pos[j]][y]); break; }
			}
		}
	}
	return 0;
}