#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int64_t> A(N);
		for (auto& a : A) cin >> a;
		int64_t X; cin >> X;

		std::vector<int64_t> pref(N+1);
		for (int i = 0; i < N; i++) {
			pref[i+1] = pref[i] + (A[i] - X);
		}

		int ans = N;
		int64_t max_unused = pref[0];
		for (int i = 2; i <= N; i++) {
			if (pref[i] < max_unused) {
				ans--;
				max_unused = pref[i];
				i++;
			} else {
				max_unused = std::max(max_unused, pref[i-1]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}