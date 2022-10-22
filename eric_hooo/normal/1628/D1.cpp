#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int inv2 = 500000004;

int f[2010][2010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		n -= m, swap(n, m);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 && j == 0) f[0][0] = 0;
				else if (i == 0) f[i][j] = f[i][j - 1];
				else if (j == 0) f[i][j] = (f[i - 1][j] + k) % mod;
				else {
					f[i][j] = 1ll * (f[i - 1][j] + f[i][j - 1]) * inv2 % mod;
				}
			}
		}
		printf("%lld\n", 1ll * f[n][m] % mod);
	}
	return 0;
}