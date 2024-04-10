#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int R, C; cin >> R >> C;
	if (R == 1 && C == 1) {
		cout << 0 << '\n';
		exit(0);
	}
	vector<int> A(R);
	vector<int> B(C);
	if (R <= C) {
		iota(A.begin(), A.end(), 1);
		iota(B.begin(), B.end(), R+1);
	} else {
		iota(B.begin(), B.end(), 1);
		iota(A.begin(), A.end(), C+1);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << A[i] * B[j] / __gcd(A[i], B[j]) << " \n"[j+1==C];
		}
	}

	return 0;
}