#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		M = min(M, N);
		string S; cin >> S;
		string T = S;
		for (int z = 0; z < M; z++) {
			for (int i = 0; i < N; i++) {
				if (S[i] == '1') {
					T[i] = '1';
				} else {
					T[i] = '0' ^ (i > 0 ? S[i-1] : '0') ^ (i < N-1 ? S[i+1] : '0');
				}
			}
			std::swap(T, S);
		}
		cout << S << '\n';
	}

	return 0;
}