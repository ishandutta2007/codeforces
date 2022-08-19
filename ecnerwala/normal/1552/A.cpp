#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		string T = S;
		sort(T.begin(), T.end());
		int ans = 0;
		for (int i = 0; i < N; i++) ans += T[i] != S[i];
		cout << ans << '\n';
	}

	return 0;
}