#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, m, a[N], r[N];

double p[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= m; i++) scanf("%d%lf", r + i, p + i);
		int k = n;
		while (k && a[k] == k) k--;
		if (!k) {
			printf("%d\n", 1);
		} else {
			double ans = 0, s = 1;
			for (int i = 1; i <= m; i++) {
				if (r[i] >= k) ans += s * p[i], s *= (1 - p[i]);
			}
			printf("%.10lf\n", ans);
		}
	}	
	return 0;
}