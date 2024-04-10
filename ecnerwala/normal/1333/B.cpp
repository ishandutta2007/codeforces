#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
			B[i] -= A[i];
		}
		bool hasPlus = false;
		bool hasMinus = false;
		bool good = true;
		for (int i = 0; i < N; i++) {
			if (B[i] > 0) good = good && hasPlus;
			if (B[i] < 0) good = good && hasMinus;

			if (A[i] == 1) hasPlus = true;
			else if (A[i] == -1) hasMinus = true;
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}