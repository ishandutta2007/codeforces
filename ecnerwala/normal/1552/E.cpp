#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, K; cin >> N >> K;
	int B = (N-1)/(K-1) + 1;
	vector<array<int, 2>> A(N, {-1, -1});
	vector<int> prv(N, -1);
	int cur = 0;
	for (int i = 0; i < N*K; i++) {
		int c; cin >> c; c--;
		if (A[c][0] == -1) {
			if (prv[c] != -1) {
				A[c] = {prv[c], i};
				cur++;
				if (cur == B) {
					cur = 0;
					std::fill(prv.begin(), prv.end(), -1);
				}
			} else {
				prv[c] = i;
			}
		}
	}

	for (int i = 0; i < N; i++) cout << A[i][0]+1 << ' ' << A[i][1]+1 << '\n';

	return 0;
}