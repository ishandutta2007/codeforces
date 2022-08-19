#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		int last_1 = -K-1;
		string S; cin >> S;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] == '0') {
				if (i - last_1 > K) {
					ans++;
					S[i] = '1';
					last_1 = i;
				}
			} else if (S[i] == '1') {
				if (i - last_1 <= K) {
					S[last_1] = '0';
					ans--;
				}
				last_1 = i;
			} else assert(false);
		}
		cout << ans << '\n';
	}

	return 0;
}