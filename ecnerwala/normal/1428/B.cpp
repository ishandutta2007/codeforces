#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		assert(int(S.size()) == N);

		bool can_right = true;
		bool can_left = true;
		for (char c : S) {
			if (c == '<') can_right = false;
			if (c == '>') can_left = false;
		}
		if (can_left || can_right) {
			cout << N << '\n';
		} else {
			int ans = 0;
			for (int i = 0; i < N; i++) {
				if (S[i] == '-' || S[(i+1)%N] == '-') ans++;
			}
			cout << ans << '\n';
		}
	}

	return 0;
}