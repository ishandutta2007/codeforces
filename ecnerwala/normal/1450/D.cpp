#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a, a--; }

		vector<int> freq(N); for (auto a : A) freq[a]++;

		// k = 1 case first
		// 0 if not a permutation, 1 if it is
		string ans(N, '\0');
		bool is_good = freq[0] > 0;
		ans[0] = is_good ? '1' : '0';
		for (int i = 1, l = 0, r = N; i < N; i++) {
			if (is_good) {
				// you need a[i-1] to be unique and on an end, and you need a[i] to exist
				if (freq[i-1] != 1) {
					is_good = false;
				} else if (freq[i] == 0) {
					is_good = false;
				} else if (i-1 == A[l]) {
					l++;
				} else if (i-1 == A[r-1]) {
					--r;
				} else {
					is_good = false;
				}
			}
			ans[i] = is_good ? '1' : '0';
		}
		ans[N-1] = char('0' + *min_element(freq.begin(), freq.end()));
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}

	return 0;
}