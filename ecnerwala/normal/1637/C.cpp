#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		N -= 2;
		{ int garbage; cin >> garbage; }
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		{ int garbage; cin >> garbage; }

		if (N == 1) {
			if (A[0] & 1) {
				cout << -1 << '\n';
			} else {
				cout << A[0]/2 << '\n';
			}
			continue;
		}

		int num_even = 0;
		int num_odd = 0;
		int num_big = 0;
		int last_val = 0;
		int64_t ans = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == 0) continue;
			if (A[i] & 1) {
				num_odd++;
			} else {
				num_even++;
			}
			num_big += (A[i] >= 2);
			last_val = A[i];
			ans += (A[i]+1)/2;
		}
		if (num_even == 0 && num_odd == 0) {
			cout << 0 << '\n';
		} else if (num_big == 0) {
			cout << -1 << '\n';
		} else if (num_even > 0 || num_odd >= 2) {
			cout << ans << '\n';
		} else {
			if (last_val == 3) {
				cout << -1 << '\n';
			} else {
				cout << ans+1 << '\n';
			}
		}
	}

	return 0;
}