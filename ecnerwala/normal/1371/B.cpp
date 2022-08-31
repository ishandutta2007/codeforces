#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t N, R; cin >> N >> R;
		R = min(R, N);
		// sum from k = 1 to R of min(k, N+1-k)
		cout << R * (R+1) / 2 - (R == N ? N-1 : 0) << '\n';
		//int64_t M = (N+1) / 2;
		//cout << M * (M+1) / 2 + (R-M) * ((N+1-R) + (N+1-(M+1))) / 2 << '\n';
	}
	return 0;
}