#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i], A[i]--;
		bool ans = [&]() -> bool {
			return A[0] < A[N-1];
		}();
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}