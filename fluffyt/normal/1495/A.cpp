#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100005;
int x[MAXN], y[MAXN], T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int a = 0, b = 0;
		for (int i = 1; i <= 2 * n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			if (u == 0) y[++b] = abs(v);
			else x[++a] = abs(u);
		}
		sort(x + 1, x + 1 + n);
		sort(y + 1, y + 1 + n);
		double ans = 0;
		for (int i = 1; i <= n; i++)
			ans += sqrt((LL)x[i] * x[i] + (LL)y[i] * y[i]);
		printf("%.12lf\n", ans);
	}
	return 0;
}