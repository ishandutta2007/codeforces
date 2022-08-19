#include<bits/stdc++.h>

int solve(int N, std::string S, std::string T) {
	using namespace std;
	array<int, 26> cnt; fill(cnt.begin(), cnt.end(), 0);
	int min_j = -1;
	vector<int> dp(N+1);
	vector<int> ndp(N+1);
	for (int i = 0; i < N; i++) {
		cnt[S[i]-'a']--;
		while (cnt[S[i]-'a'] < 0) {
			++min_j;
			if (min_j == N) {
				return -1;
			}
			cnt[T[min_j]-'a']++;
		}
		int cur_best = N+1;
		for (int j = min_j; j <= N; j++) {
			// don't move at all
			cur_best = min(cur_best, dp[j]+1);
			ndp[j] = cur_best;
			if (j < N && T[j] == S[i]) {
				cur_best = min(cur_best, dp[j]);
			}
		}
		swap(dp, ndp);
	}
	return dp[N];
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int CASES; cin >> CASES;
	while (CASES--) {
		int N; cin >> N;
		string S, T; cin >> S >> T;
		int ans = solve(N, S, T);
		cout << ans << '\n';
	}

	return 0;
}