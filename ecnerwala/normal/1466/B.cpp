#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> X(N); for (auto& a : X) { cin >> a; a--; }
		vector<bool> seen(2*N+2);
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (seen[X[i]]) X[i]++;
			ans += !seen[X[i]];
			seen[X[i]] = true;
		}
		cout << ans << '\n';
	}

	return 0;
}