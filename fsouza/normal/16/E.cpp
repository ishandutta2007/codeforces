#include <iostream>
#include <cstdio>

#define MAXN 18

using namespace std;

double dp[1<<MAXN], P[MAXN][MAXN];

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &P[i][j]);

	for (int s = 0; s < (1<<n); s++) dp[s] = 0.0;
	dp[(1<<n)-1] = 1.0;

	for (int s = (1<<n)-1; s > 0; s--) {
		int many = __builtin_popcount(s);

		if (many == 1) continue;

		int mp = many*(many-1)/2;

		for (int i = 0; i < n; i++)
			if (s & (1<<i)) {
				for (int s2 = s; s2; s2 -= s2&-s2) {
					int j = __builtin_ctz(s2&-s2);
//					if (i == j) continue;
					dp[s ^ (1<<j)] += dp[s] * P[i][j]/mp;
				}
			}
	}

	for (int i = 0; i < n; i++) {
		printf("%.10f", dp[1<<i]);
		if (i+1 < n) printf(" ");
	}
	printf("\n");

	return 0;
}