#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, p, k, a[N], x, y, ans, b[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &p, &k);
		for (int i = 1; i <= n; i++) scanf("%1d", a + i);
		scanf("%d%d", &x, &y);
		ans = 2e9;
		for (int i = n; i; i--) {
			b[i] = !a[i];
			if (i + k <= n) b[i] += b[i + k];
		}
		for (int i = 1; i <= n; i++) {
			if (i + p - 1 <= n)ans = min(ans, y * (i - 1) + x * b[i + p - 1]);
		}
		printf("%d\n", ans);
	}	
	return 0;
}