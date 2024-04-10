#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 5005, P = 1e9 + 7;

int n, K, q, a[N], f[N][N], g[N];

int main() {
	scanf("%d%d%d", &n, &K, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), f[0][i] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % P;
		}
	}
	for (int i = 0; i <= K; i++)
		for (int j = 1; j <= n; j++)
			g[j] = (g[j] + (LL)f[i][j] * f[K - i][j]) % P;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + (LL)g[i] * a[i]) % P;
	while (q--) {
		int i, x; scanf("%d%d", &i, &x);
		ans = (ans - (LL)g[i] * a[i] % P + P) % P;
		a[i] = x;
		ans = (ans + (LL)g[i] * a[i]) % P;
		printf("%d\n", ans);
	}
	return 0;
}