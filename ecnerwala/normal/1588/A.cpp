#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		std::vector<int> B(N);
		for (auto& b : B) cin >> b;
		std::sort(A.begin(), A.end());
		std::sort(B.begin(), B.end());
		bool good = true;
		for (int i = 0; i < N; i++) {
			int d = B[i] - A[i];
			if (d != 0 && d != 1) good = false;
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}