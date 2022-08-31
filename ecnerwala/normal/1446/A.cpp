#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int64_t W; cin >> W;
		vector<int64_t> A(N); for (auto& a : A) cin >> a;

		[&]() {
			for (int i = 0; i < N; i++) {
				if (2 * A[i] >= W && A[i] <= W) {
					cout << 1 << '\n';
					cout << i+1 << '\n';
					return;
				}
			}

			int64_t tot = 0;
			vector<int> ans; ans.reserve(N);
			for (int i = 0; i < N; i++) {
				if (A[i] <= W) {
					tot += A[i];
					ans.push_back(i);
					if (tot * 2 >= W) {
						cout << ans.size() << '\n';
						for (int z = 0; z < int(ans.size()); z++) {
							cout << ans[z]+1 << " \n"[z+1==int(ans.size())];
						}
						return;
					}
				}
			}
			cout << -1 << '\n';
		}();
	}

	return 0;
}