#include <bits/stdc++.h>

using namespace std;

int t, n, q, Li, Ri, a[100002], lst[100002], nxt[100002], xs[100002];
long long sum[100002];

long long f(int Li, int Ri) {
	return (sum[Ri] - sum[Li - 1]) - (xs[Ri] ^ xs[Li - 1]);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			lst[i] = a[i] ? i: lst[i - 1];
			sum[i] = sum[i - 1] + a[i];
			xs[i] = xs[i - 1] ^ a[i];
		}
		nxt[n + 1] = n + 1;
		for (int i = n; i; --i)
			nxt[i] = a[i] ? i : nxt[i + 1];
		while (q--) {
			scanf("%d%d", &Li, &Ri);
			if (sum[Ri] == sum[Li - 1]) {
				printf("%d %d\n", Li, Li);
				continue;
			}
			long long v = f(Li, Ri);
			int l = nxt[Li], r = lst[Ri];
			while (l <= lst[r - 1] && f(l, lst[r - 1]) == v) r = lst[r - 1];
			int ansl = l, ansr = r;
			do {
				l = nxt[l + 1];
				if (r < l) r = l;
				while (r <= Ri && f(l, r) < v) r = nxt[r + 1];
				if (r <= Ri && r - l < ansr - ansl) {
					ansl = l;
					ansr = r;
				}
			} while (r <= Ri);
			printf("%d %d\n", ansl, ansr);
		}
	}
	return 0;
}