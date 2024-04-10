#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N); for (auto& a : A) cin >> a;

		std::vector<int> X(N);
		for (int i = 0; i < N; i++) {
			X[A[i]-1] = (i+1) % N;
		}
		for (int i = 0; i < N; i++) {
			cout << X[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}