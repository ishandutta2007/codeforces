#include <string>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 4005;

int dp[maxn][maxn], cost[10], i, j, n, m;
int lasta[maxn], lastb[maxn];
string a, b;

int main() {
	cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];
	cin >> a >> b;
	n = a.size();
	m = b.size();
	a = " " + a;
	b = " " + b;
	for (i = 1; i <= n; ++i)
		dp[i][0] = cost[1] * i;
	for (i = 1; i <= m; ++i)
		dp[0][i] = cost[0] * i;
	for (i = 1; i <= n; ++i) {
		memset(lastb, 0, sizeof(lastb));
		for (j = 1; j <= m; ++j) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min( min(dp[i - 1][j] + cost[1], dp[i][j - 1] + cost[0]), dp[i - 1][j - 1] + cost[2]);
				if (lasta[b[j]] > 0 && lastb[a[i]] > 0)
					dp[i][j] = min( dp[lasta[b[j]] - 1][lastb[a[i]] - 1] + (i - lasta[b[j]] - 1) * cost[1] + (j - lastb[a[i]] - 1) * cost[0] + cost[3], dp[i][j]);
			}
			lastb[b[j]] = j;
		}
		lasta[a[i]] = i;
	}

	cout << dp[n][m];
}