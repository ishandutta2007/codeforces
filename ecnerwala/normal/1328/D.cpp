#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		vector<int> C(N);

		int st = N;
		for (int i = 0; i < N; i++) {
			if (A[i] == A[(i+1)%N]) {
				st = (i+1);
			}
		}
		for (int i = st; i < st+N; i++) {
			C[i%N] = 1;
			while ((A[(i-1)%N] != A[i%N] && C[(i-1)%N] == C[i%N]) || (A[(i+1)%N] != A[i%N] && C[(i+1)%N] == C[i%N])) {
				C[i%N]++;
			}
		}
		cout << *max_element(C.begin(), C.end()) << '\n';
		for (int i = 0; i < N; i++) {
			cout << C[i] << " \n"[i+1==N];
		}
	}

	return 0;
}