#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, X; cin >> N >> X;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i]; A[i] &= 1;
		}
		sort(A.begin(), A.end());
		int mi = accumulate(A.begin(), A.begin()+X, 0);
		int ma = accumulate(A.end()-X, A.end(), 0);
		if (mi % 2 == 0) mi++;
		cout << (mi <= ma ? "Yes" : "No") << '\n';
	}

	return 0;
}