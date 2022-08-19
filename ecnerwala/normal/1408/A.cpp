#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<array<int, 3>> A(N);
		for (int z = 0; z < 3; z++) {
			for (int i = 0; i < N; i++) {
				cin >> A[i][z];
			}
		}

		cout << A[0][0];
		int last = A[0][0];
		for (int i = 1; i < N; i++) {
			cout << " ";
			int z = 0;
			while (A[i][z] == last || A[i][z] == A[0][0]) z++;
			last = A[i][z];
			cout << A[i][z];
		}
		cout << '\n';
	}

	return 0;
}