#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		assert(int(S.size()) == N);

		cout << [&]() -> int {
			int tot = 0;
			for (char c : S) {
				tot += (c == '1' ? -1 : +1);
			}
			if (tot < 0) {
				std::reverse(S.begin(), S.end());
				for (char& c : S) c ^= 1;
				tot = -tot;
			}
			assert(tot >= 0);

			std::vector<int> jmp(tot+1);
			{
				int s = 0;
				for (int i = 0; i < N; i++) {
					s += (S[i] == '1' ? -1 : +1);
					if (0 <= s && s <= tot) jmp[s] = (s + i+1) / 2;
				}
			}

			int cur_pref = 0;
			while (cur_pref < N && S[cur_pref] == '0') cur_pref++;

			int ans = 0;
			while (cur_pref < (N + tot) / 2) {
				cur_pref = jmp[std::min(cur_pref, tot)];
				ans++;
			}
			return ans;
		}() << '\n';
	}

	return 0;
}