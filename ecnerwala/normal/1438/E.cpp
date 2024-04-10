#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int64_t> A(N); for (auto& a : A) cin >> a;

	int64_t ans = 0;

	for (int l = 0; l < 30; l++) {
		for (int i = 0; i < N; i++) {
			if (A[i] & (int64_t(1) << l)) {
				{
					int64_t cur_sum = 0;
					for (int j = i+2; j < N; j++) {
						cur_sum += A[j-1];
						if (cur_sum >= (int64_t(2) << l)) break;
						if (cur_sum < (int64_t(1) << l)) continue;
						if ((A[i] ^ A[j]) == cur_sum) ans++;
					}
				}
				{
					int64_t cur_sum = 0;
					for (int j = i-2; j >= 0; j--) {
						cur_sum += A[j+1];
						if (cur_sum >= (int64_t(2) << l)) break;
						if (cur_sum < (int64_t(1) << l)) continue;
						if ((A[i] ^ A[j]) == cur_sum) ans++;
					}
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}