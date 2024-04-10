#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a;
		int tot = std::accumulate(A.begin(), A.end(), 0);
		if (tot == 0) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		sort(A.begin(), A.end());
		if (tot > 0) {
			reverse(A.begin(), A.end());
		}
		for (int i = 0; i < N; i++) {
			cout << A[i] << " \n"[i+1==N];
		}
	}

	return 0;
}