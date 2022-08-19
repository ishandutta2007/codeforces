#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int64_t K; cin >> K;
		std::vector<int64_t> A(N);
		for (auto& a : A) {
			cin >> a;
		}
		std::sort(A.begin(), A.end());
		bool good = false;
		for (int i = 0, j = 0; i < N; i++) {
			while (j < N && A[j] < A[i] + K) j++;
			if (j < N && A[j] == A[i]+K) {
				good = true;
				break;
			}
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}