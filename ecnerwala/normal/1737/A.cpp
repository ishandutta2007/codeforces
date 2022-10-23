#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		std::array<int, 26> cnt; cnt.fill(0);
		string S; cin >> S;
		for (char c : S) cnt[c-'a']++;
		string res; res.reserve(K);
		for (int i = 0; i < K; i++) {
			int j;
			for (j = 0; j < N/K; j++) {
				if (cnt[j] > 0) {
					cnt[j]--;
				} else {
					break;
				}
			}
			res += char('a'+j);
		}
		cout << res << '\n';
	}

	return 0;
}