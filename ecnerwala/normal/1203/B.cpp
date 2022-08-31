#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		int N; cin >> N;
		vector<int> A(4*N);
		for (int i = 0; i < 4 * N; i++) cin >> A[i];
		sort(A.begin(), A.end());
		bool good = true;
		for (int i = 0; i < 4 * N; i += 2) {
			if (A[i] != A[i+1]) good = false;
		}
		int area = A.front() * A.back();
		for (int i = 0, j = 4 * N-1; i < j; i += 2, j -= 2) {
			if (A[i] * A[j] != area) good = false;
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}