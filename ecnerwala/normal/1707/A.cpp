#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, Q; cin >> N >> Q;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		int cur_iq = 0;
		int cur_ans = 0;
		std::string ans(N, '?');
		for (int i = N-1; i >= 0; i--) {
			int a = A[i];
			if (cur_iq + 1 <= Q && cur_iq + 1 <= a) {
				cur_iq ++;
				cur_ans++;
				ans[i] = '1';
			} else if (cur_iq >= a) {
				cur_ans++;
				ans[i] = '1';
			} else {
				ans[i] = '0';
			}
		}
		cout << ans << '\n';
	}

	return 0;
}