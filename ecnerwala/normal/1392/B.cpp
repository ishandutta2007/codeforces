#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; int64_t K; cin >> N >> K;
		if (K >= 2) {
			K = (K - 2) % 2 + 2;
		}
		vector<int> A(N); for (auto& a : A) cin >> a;
		while (K--) {
			int d = *max_element(A.begin(), A.end());
			for (auto& a : A) a = d - a;
		}
		for (int i = 0; i < N; i++) {
			cout << A[i] << " \n"[i+1==N];
		}
	}

	return 0;
}