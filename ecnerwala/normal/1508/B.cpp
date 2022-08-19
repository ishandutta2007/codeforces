#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; int64_t K; cin >> N >> K; K--;
		if (N <= 62 && K >= (1ll << (N-1))) {
			cout << -1 << '\n';
			continue;
		}
		vector<int> A; A.reserve(N);
		for (int i = 0; i < N; ) {
			int j = i+1;
			while (j < N && N-j-1 <= 62 && K >= (1ll << (N-j-1))) {
				K -= (1ll << (N-j-1));
				j++;
			}
			for (int z = j-1; z >= i; z--) {
				A.push_back(z);
			}
			i = j;
		}
		for (int i = 0; i < N; i++) {
			cout << A[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}