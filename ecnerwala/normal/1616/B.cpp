#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		if (N >= 2 && S[1] >= S[0]) {
			cout << S[0] << S[0] << '\n';
		} else {
			int L = 1;
			while (L < N && S[L] <= S[L-1]) {
				L++;
			}
			for (int i = 0; i < L; i++) {
				cout << S[i];
			}
			for (int i = L-1; i >= 0; i--) {
				cout << S[i];
			}
			cout << '\n';
		}
	}

	return 0;
}