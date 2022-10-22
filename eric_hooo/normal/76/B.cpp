#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[100010], b[100010], ll[100010], rr[100010];
vector <int> from[200010];
int minj[100010], cnt[100010];
int f[100010], g[100010];

int main () {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	int n, m, wjy, yjw; scanf("%d%d%d%d", &n, &m, &wjy, &yjw);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] += 10000000;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		b[i] += 10000000;
	}
	for (int i = 0; i < m; i++) {
		if (!i) ll[i] = 0;
		else ll[i] = lower_bound(a, a + n, b[i - 1] + b[i] + 1 >> 1) - a;
		if (i + 1 == m) rr[i] = n - 1;
		else rr[i] = upper_bound(a, a + n, b[i + 1] + b[i] >> 1) - a - 1;
		minj[i] = 0x3f3f3f3f, cnt[i] = 0;
		for (int j = ll[i] + 1; j <= rr[i] - 1; j++) {
			if (minj[i] > abs(a[j] - b[i])) {
				minj[i] = abs(a[j] - b[i]);
				cnt[i] = 1;
			} else if (minj[i] == abs(a[j] - b[i])) cnt[i]++;
		}
	}
	ll[m] = rr[m] = INF;
	f[0] = 0, g[0] = -INF;
	for (int i = 0; i < m; i++) {
		if (ll[i] == rr[i] + 1) {
			f[i + 1] = f[i], g[i + 1] = g[i];
		} else if (ll[i] == rr[i]) {
			if (ll[i + 1] == ll[i]) {
				f[i + 1] = f[i];
				g[i + 1] = f[i] + 1;
			} else {
				f[i + 1] = max(f[i] + 1, g[i]);
				g[i + 1] = -INF;
			}
		} else {
			long long maxj = -INF;
			int L = abs(a[ll[i]] - b[i]), R = abs(a[rr[i]] - b[i]);
			int mn = min(L, minj[i]);
			int nc = (L < minj[i] ? 1 : L == minj[i] ? cnt[i] + 1 : cnt[i]); // ll
			int ncc = (R < mn ? 1 : R == mn ? nc + 1 : nc); // ll & rr
			int nnc = (R < minj[i] ? 1 : R == minj[i] ? cnt[i] + 1 : cnt[i]); // rr
			if (ll[i + 1] == rr[i]) {
				f[i + 1] = max(f[i] + nc, g[i] + cnt[i]);
				g[i + 1] = max(f[i] + ncc, g[i] + nnc);
			} else {
				f[i + 1] = max(f[i] + ncc, g[i] + nnc);
				g[i + 1] = -INF;
			}
		}
	}
	printf("%d\n", n - max(f[m], g[m]));
	return 0;
}
/*
3 2 0 2
0 1 3
2 5

*/