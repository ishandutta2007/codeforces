#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		string A, B; cin >> A >> B;
		cout << ([&]() -> bool {
			for (int i = 1; i < M; i++) {
				if (B[i] != A[N-M+i]) {
					return false;
				}
			}
			for (int i = 0; i <= N-M; i++) {
				if (A[i] == B[0]) return true;
			}
			return false;
		}() ? "YES" : "NO") << '\n';
	}

	return 0;
}