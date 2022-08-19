#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		assert(K % 2 == 0);
		string S; cin >> S;
		assert(int(S.size()) == N);

		auto go = [&]() -> bool {
			// must be perioidic mod K
			int c0 = 0;
			int c1 = 0;
			for (int i = 0; i < K; i++) {
				for (int j = i; j < N; j += K) {
					if (S[i] == '?') {
						S[i] = S[j];
						continue;
					} else if (S[j] == '?') {
						continue;
					} else if (S[i] != S[j]) {
						return false;
					}
				}
				if (S[i] == '0') c0++;
				else if (S[i] == '1') c1++;
				else if (S[i] == '?') ;
				else assert(false);
			}
			return max(c0, c1) <= (K/2);
		};

		bool ans = go();
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}