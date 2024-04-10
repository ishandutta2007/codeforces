#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int Q, N;
int V[MAXN], C[MAXN];
LL dp[MAXN];

LL solve(LL a, LL b) {
	memset(dp, 128 | 63, sizeof dp);
	dp[0] = 0;
	int best = 0, second = 1;
	for (int i = 0; i < N; i++) {
		int c = C[i], v = V[i];
		LL x = max(dp[c] + a * v, dp[best == c ? second : best] + b * v);
		if (x > dp[c]) {
			dp[c] = x;
			if (c != best && x > dp[second])
				second = c;
			if (dp[second] > dp[best])
				swap(best, second);
		}
	}
	return *max_element(dp, dp + N + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> V[i];
	for (int i = 0; i < N; i++)
		cin >> C[i];

	while (Q--) {
		int a, b;
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}

	cout.flush();
	return 0;
}