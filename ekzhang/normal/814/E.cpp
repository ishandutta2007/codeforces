#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 53
#define MOD 1000000007
#define HALF ((MOD+1)/2)
int N;
int D[MAXN];
LL memo[MAXN][MAXN];
LL dp[MAXN][2][MAXN][MAXN]; int foo = 0;
int t[MAXN];

LL fact[10000];

#define INC(a, b) a = (a + b) % MOD

void solve2(int idx, int k) {
	for (int t2 = 0; t2 < 2; t2++) {
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				dp[foo][t2][i][j] = 0;
			}
		}
	}
	t[foo] = 0;
	dp[foo][t[foo]][0][0] = 1;
	for (int city = idx; city < idx + k; city++) {
		t[foo] ^= 1;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; i + j <= k; j++) {
				dp[foo][t[foo]][i][j] = 0;
			}
		}
		for (int i = 0; i <= k; i++) {
			for (int j = 0; i + j <= k; j++) {
				if (dp[foo][!t[foo]][i][j] == 0) continue;
				LL x = dp[foo][!t[foo]][i][j];
				if (!x) continue;

				if (D[city] == 2) {
					INC(dp[foo][t[foo]][i+1][j], x);
					if (i) INC(dp[foo][t[foo]][i-1][j], i * x);
                    if (j) INC(dp[foo][t[foo]][i+1][j-1], j * x);
				}
				else {
					INC(dp[foo][t[foo]][i][j+1], x);
					if (i) INC(dp[foo][t[foo]][i][j], i * x);
					if (j) INC(dp[foo][t[foo]][i+2][j-1], j * x);
					if (i >= 2) INC(dp[foo][t[foo]][i-2][j], (i * (i - 1) / 2) * x);
					if (j >= 2) INC(dp[foo][t[foo]][i+2][j-2], (j * (j - 1) / 2) * x);
					if (i && j) INC(dp[foo][t[foo]][i][j-1], i * j * x);
				}
			}
		}
	}
}

LL solve(int idx, int k) {
	if (N - idx < k) {
		return 0;
	}
	if (k == 0) {
		return idx == N;
	}
	if (~memo[idx][k]) {
		return memo[idx][k];
	}

	LL ans = 0;
	if (k == 1) {
		ans = solve(idx + 1, D[idx] - 1);
	}
	else {
		solve2(idx, k);

		for (int i = 0; i <= k; i++) {
			for (int j = 0; i + j <= k; j++) {
				if (!dp[foo][t[foo]][i][j]) continue;
				++foo;
				LL cur = dp[foo-1][t[foo-1]][i][j] * solve(idx + k, i + 2 * j);
				--foo;
				cur %= MOD;
				cur *= fact[i + 2 * j];
				cur %= MOD;
				for (int p = 0; p < j; p++) {
					cur = (cur * HALF) % MOD;
				}
				ans = (ans + cur) % MOD;
			}
		}
	}

	return memo[idx][k] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}

	fact[0] = 1;
	for (int i = 1; i <= 2 * N; i++) {
		fact[i] = (i * fact[i-1]) % MOD;
	}

	memset(memo, -1, sizeof memo);
	++D[0];
	cout << solve(0, 1) << endl;

	return 0;
}