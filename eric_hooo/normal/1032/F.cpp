#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n;
vector <int> from[300010];
int dp[300010][2][2], alive[300010];
long long tmp[2][2];

void dfs(int x, int last) {
	for (auto v : from[x]) if (v != last) {
		dfs(v, x);
	}
	dp[x][0][0] = 1;
	for (auto v : from[x]) if (v != last) {
		memset(tmp, 0, sizeof(tmp));
		for (int p = 0; p < 2; p++) {
			for (int q = 0; q < 2; q++) {
				tmp[p][q] += 1ll * dp[x][p][q] * alive[v];
				for (int np = 0; np < 2; np++) {
					for (int nq = 0; nq < 2; nq++) {
						if (p + np < 2) tmp[p + np][1] += 1ll * dp[x][p][q] * dp[v][np][nq];
					}
				}
			}
		}
		for (int p = 0; p < 2; p++) {
			for (int q = 0; q < 2; q++) {
				dp[x][p][q] = tmp[p][q] % mod;
			}
		}
	}
	for (int q = 0; q < 2; q++) {
		swap(dp[x][0][q], dp[x][1][q]);
	}
	alive[x] = (1ll * dp[x][0][0] + dp[x][0][1] + dp[x][1][0]) % mod;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1);
	printf("%d\n", alive[1]);
	return 0;
}