#include <bits/stdc++.h>
using namespace std;
int n, m;
pair < int, pair < int, int > > e[160];
struct matrix {
	int a[160][160];
	friend matrix operator * (const matrix &a, const matrix &b) {
		bitset < 160 > x[160], y[160];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) x[i][j] = a.a[i][j], y[i][j] = b.a[j][i];
		matrix ans;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) ans.a[i][j] = !!(x[i] & y[j]).count();
		return ans;
	}
	matrix() {memset(a, 0, sizeof a);}
};
matrix power(matrix a, int b) {
	matrix res = a, ans;
	for (int i = 1; i <= n; i++) ans.a[i][i] = 1;
	for (; b; b >>= 1, res = res * res) if (b & 1) ans = ans * res;
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) return puts("0"), 0;
	for (int i = 1; i <= m; i++) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		e[i] = {d, {u, v}};
	}
	sort(e + 1, e + 1 + m);
	e[m + 1].first = e[m].first + n;
	matrix now, nowc;
	for (int i = 1; i <= n; i++) now.a[i][i] = 1;
	if (e[1].first != 0) return puts("Impossible"), 0;
	for (int i = 1; i <= m; i++) {
		int l = e[i].first, r = min(e[i + 1].first, e[i].first + n);
		nowc.a[e[i].second.first][e[i].second.second] = 1;
		matrix nowd = nowc;
		nowd.a[n][n] = 1;
		if ((now * power(nowd, r - l)).a[1][n]) {
			int ans = r;
			while (l <= r) {
				int mid = l + r >> 1;
				if ((now * power(nowd, mid - e[i].first)).a[1][n]) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			return printf("%d\n", ans), 0;
		}
		now = now * power(nowc, e[i + 1].first - e[i].first);
	}
	return puts("Impossible"), 0;
}