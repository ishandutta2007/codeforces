#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		int N; cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		sort(A.begin(), A.end());
		bool ans = false;
		for (int i = 0; i+1 < N; i++) {
			if (A[i+1] - A[i] == 1) {
				ans = true;
			}
		}
		cout << (ans+1) << '\n';
	}

	return 0;
}