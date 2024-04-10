#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int z = 0; z < 2; z++) {
			vector<int> A(N);
			for (int i = 0; i < N; i++) {
				cin >> A[i];
			}
			sort(A.begin(), A.end());
			for (int i = 0; i < N; i++) {
				cout << A[i] << " \n"[i+1==N];
			}
		}
	}

	return 0;
}