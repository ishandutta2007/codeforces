#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define MAXK 103
#define MOD 998244353
int N, K, L;
int A[MAXN];
int dp[MAXN][MAXK];
int total[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K >> L;
	if (L == 1) {
		// BAD
		cout << 0 << endl;
		return 0;
	}

	map<int, int> pre;
	dp[0][0] = total[0] = 1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] != -1)
			pre[A[i]]++;
		if (i >= L) {
			if (A[i - L] != -1) {
				if (--pre[A[i - L]] == 0)
					pre.erase(A[i - L]);
			}
		}

		if (A[i] == -1) {
			for (int j = 1; j <= K; j++)
				dp[i + 1][j] = total[i];
		}
		else {
			dp[i + 1][A[i]] = total[i];
		}

		if (i >= L - 1) {
			if (pre.size() == 1) {
				int val = pre.begin()->first;
				int amt = (MOD + total[i + 1 - L] - dp[i + 1 - L][val]) % MOD;
				dp[i + 1][val] = (dp[i + 1][val] + MOD - amt) % MOD;
			}
			else if (pre.empty()) {
				for (int val = 1; val <= K; val++) {
					int amt = (MOD + total[i + 1 - L] - dp[i + 1 - L][val]) % MOD;
					dp[i + 1][val] = (dp[i + 1][val] + MOD - amt) % MOD;
				}
			}
		}

		// calculate total
		for (int j = 0; j <= K; j++)
			total[i + 1] = (total[i + 1] + dp[i + 1][j]) % MOD;
	}

	cout << total[N] << endl;
	return 0;
}