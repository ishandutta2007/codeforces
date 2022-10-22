#include <bits/stdc++.h>
using namespace std;

map <int, long long> a;

long double N;

long double dfs(int x, int dep, long long maxj = -1) {
	if (dep == 0) return max(maxj, a[x]) / N;
	long long t1 = a.count(x << 1) ? a[x << 1] : 0, t2 = a.count(x << 1 | 1) ? a[x << 1 | 1] : 0;
	long long cur = a.count(x) ? a[x] : 0, ls = cur - t2, rs = cur - t1;
	if (ls > rs) return dfs(x << 1, dep - 1, max(maxj, rs)) + max(ls, maxj) * (1 << dep - 1) / N;
	return dfs(x << 1 | 1, dep - 1, max(maxj, ls)) + max(rs, maxj) * (1 << dep - 1) / N;
}

int main () {
	int h, q; scanf("%d%d", &h, &q);
	N = 1 << h;
	while (q--) {
		char op[7]; scanf("%s", op);
		if (op[0] == 'a') {
			int x, v; scanf("%d%d", &x, &v);
			while (x) a[x] += v, x >>= 1;
		} else {
			printf("%.8f\n", (double)dfs(1, h));
		}
	}
	return 0;
}