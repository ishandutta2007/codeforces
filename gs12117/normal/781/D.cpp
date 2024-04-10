#include<cstdio>
#include<bitset>
using namespace std;
int eg[1001000][3];
int a[2][505][505];
bitset<505> dp[62][2][505];
long long int ldg[2][505];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &eg[i][0], &eg[i][1], &eg[i][2]);
		a[eg[i][2]][eg[i][0]][eg[i][1]] = 1;
		dp[0][eg[i][2]][eg[i][0]][eg[i][1]] = 1;
	}
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[i][j][k] == 0)continue;
				for (int ii = 1; ii <= n; ii++) {
					if (dp[i][j][k][ii] == 1) {
						dp[i + 1][j][k] |= dp[i][1 - j][ii];
					}
				}
				if (dp[i + 1][j][k] == 0) {
					ldg[j][k] = 0;
					for (int ii = 1; ii <= n; ii++) {
						if (dp[i][j][k][ii] == 1) {
							if(ldg[j][k]<ldg[1 - j][ii])ldg[j][k] = ldg[1 - j][ii];
						}
					}
					ldg[j][k] += 1LL << i;
				}
			}
		}
	}
	if (dp[60][0][1] != 0)ldg[0][1] = -1;
	if (ldg[0][1] > 1000000000000000000LL)ldg[0][1] = -1;
	printf("%I64d\n", ldg[0][1]);
	return 0;
}