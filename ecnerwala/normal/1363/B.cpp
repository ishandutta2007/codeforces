#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int N = int(S.size());
		vector<int> pref(N+1);
		for (int i = 0; i < N; i++) {
			pref[i+1] = pref[i] + (S[i] - '0');
		}
		int ans = N;
		for (int i = 0; i <= N; i++) {
			int cnd = (i - pref[i]) + (pref[N] - pref[i]);
			cnd = min(cnd, N - cnd);
			ans = min(ans, cnd);
		}
		cout << ans << '\n';
	}

	return 0;
}