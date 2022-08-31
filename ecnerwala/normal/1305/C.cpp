#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	if (N > M) {
		cout << 0 << '\n';
	} else {
		int ans = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				ans *= abs(A[i] - A[j]) % M;
				ans %= M;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}