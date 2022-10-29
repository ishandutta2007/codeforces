#include <cstdio>
const int MOD = 1000000007;
int C[1000][1000];

int main() {
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j)
			if (i < j) C[i][j] = 0;
			else if (j == 0) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	if (n > 2 * k && m > 2 * k)
		printf("%lld", (long long) C[n-1][2*k] * C[m-1][2*k] % MOD);
	else printf("0");
}