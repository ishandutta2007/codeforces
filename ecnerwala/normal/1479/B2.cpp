#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N);
	for (auto& a : A) cin >> a, a--;
	vector<int> lastSeen(N, -1);
	A.resize(N = int(unique(A.begin(), A.end()) - A.begin()));
	vector<int> dp(N+1);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		lastSeen[A[i]] = i;
		dp[i+1] = dp[i];
		if (i+2 < N && lastSeen[A[i+2]] != -1) {
			dp[i+1] = max(dp[i+1], dp[lastSeen[A[i+2]]] + 1);
		}
	}

	cout << N - dp[N] << '\n';

	return 0;
}