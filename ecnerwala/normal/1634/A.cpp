#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string S; cin >> S;
		bool is_pal = true;
		for (int i = 0; i < N; i++) {
			is_pal = is_pal && (S[i] == S[N - 1 - i]);
		}
		cout << (K == 0 || is_pal ? 1 : 2) << '\n';
	}

	return 0;
}