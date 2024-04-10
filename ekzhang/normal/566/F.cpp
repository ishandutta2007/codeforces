#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define MAXA 1000000

int N;
int A[MAXN];
int dp[MAXA + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	fill(dp, dp + MAXA + 1, 1);
	sort(A, A + N);

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[A[i]]);
		for (int j = 2 * A[i]; j <= MAXA; j += A[i]) {
			dp[j] = max(dp[j], dp[A[i]] + 1);
		}
	}

	cout << ans << endl;
	return 0;
}