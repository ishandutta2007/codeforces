#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

typedef long long ll;

const int N = 4010, K = 80, P = 998244353;

int k;
int comb[K][K];
int a1[K], a2[K];
pair<int, int> t1[N], t2[N];

void solve(int n, pair<int, int>* t, int* a);

int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &k);
	if (k % 2) {
		puts("0");
		return 0;
	}
	k /= 2;
	for (int i = 1; i < n; ++i)
		scanf("%d%d", &t1[i].first, &t1[i].second);
	for (int i = 1; i < m; ++i)
		scanf("%d%d", &t2[i].first, &t2[i].second);
	solve(n, t1, a1);
	solve(m, t2, a2);
	for (int i = 0; i <= k * 2; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			if (comb[i][j] >= P)
				comb[i][j] -= P;
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; ++i)
		ans = (ans + (ll)comb[k * 2][i * 2] * a1[i] % P * a2[k - i] % P) % P;
	printf("%d\n", ans);
	return 0;
}

void solve(int n, pair<int, int>* t, int* a) {
	static int dp[K][N * 3], sum[K][N];
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i <= n * 3 - 2; ++i)
		dp[0][i] = 1;
	for (int i = 1; i <= k; ++i) {
		for (int e = 1; e < n; ++e) {
			int u = t[e].first, v = t[e].second;
			sum[i - 1][u] += dp[i - 1][n * 2 - 1 + e];
			if (sum[i - 1][u] >= P)
				sum[i - 1][u] -= P;
			sum[i - 1][v] += dp[i - 1][n + e];
			if (sum[i - 1][v] >= P)
				sum[i - 1][v] -= P;
		}
		for (int j = 0; j < i; ++j) {
			for (int e = 1; e < n; ++e) {
				int u = t[e].first, v = t[e].second;
				dp[i][u] = (dp[i][u] + dp[j][u] * (ll)dp[i - j - 1][n * 2 - 1 + e]) % P;
				dp[i][v] = (dp[i][v] + dp[j][v] * (ll)dp[i - j - 1][n + e]) % P;
				dp[i][n + e] = (dp[i][n + e] + dp[j][n + e] * (ll)(sum[i - j - 1][u] - dp[i - j - 1][n * 2 - 1 + e]) % P + P) % P;
				dp[i][n * 2 - 1 + e] = (dp[i][n * 2 - 1 + e] + dp[j][n * 2 - 1 + e] * (ll)(sum[i - j - 1][v] - dp[i - j - 1][n + e]) % P + P) % P;
			}
		}
	}
	for (int i = 0; i <= k; ++i) {
		for (int u = 1; u <= n; ++u) {
			a[i] += dp[i][u];
			if (a[i] >= P)
				a[i] -= P;
		}
	}
}