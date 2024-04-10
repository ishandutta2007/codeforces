#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int> X(N); for (int& x : X) cin >> x;
		vector<int> Y(N); for (int& y : Y) cin >> y;

		cout << [&]() -> int {
			if (N == 1) return 1;
			sort(X.begin(), X.end());

			array<vector<int>, 2> num_cover;
			for (int z = 0; z < 2; z++) {
				num_cover[z].resize(N);
				for (int i = 0, j = 0; i < N; i++) {
					while (X[i] - X[j] > K) j++;
					num_cover[z][i] = i-j+1;
				}

				for (int& x : X) x = -x;
				reverse(X.begin(), X.end());
			}
			// num_cover[1] is the reversed one
			reverse(num_cover[1].begin(), num_cover[1].end());

			int ans = 0;
			int left_cover = 0;
			for (int i = 0; i < N; i++) {
				ans = max(ans, left_cover + num_cover[1][i]);
				left_cover = max(left_cover, num_cover[0][i]);
			}
			return ans;
		}() << '\n';
	}

	return 0;
}