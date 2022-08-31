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

		if ([&]() -> bool {
			if (N & 1) return false;
			std::sort(A.begin(), A.end());
			for (int i = 0; i < N/2; i++) {
				B[2*i] = A[i];
			}
			for (int i = 0; i < N/2; i++) {
				B[2*i+1] = A[N/2+i];
			}
			for (int i = 0; i < N; i++) {
				if (B[i] == B[(i+1)%N]) return false;
			}
			return true;
		}()) {
			cout << "YES" << '\n';
			for (int i = 0; i < N; i++) {
				cout << B[i] << " \n"[i+1==N];
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}