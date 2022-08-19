#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			string S; cin >> S;
			ans += (S.back() == 'R');
			if (i == N-1) {
				for (char c : S) {
					ans += c == 'D';
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}