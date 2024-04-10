#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	std::vector<int> nimbers(1000);
	for (int i = 0; i < 1000; i++) {
		std::set<int> vals;
		for (int j = 0; j+2 <= i; j++) {
			vals.insert(nimbers[j] ^ nimbers[i-j-2]);
		}
		nimbers[i] = 0;
		while (vals.count(nimbers[i])) nimbers[i]++;
	}
	auto get_nimber = [&](int v) {
		if (v >= 1000) v = (v - (1000 - 34)) % 34 + 1000 - 34;
		return nimbers[v];
	};

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		int A_cnt = 0, B_cnt = 0;
		for (int i = 0; i < int(S.size()); i++) {
			if (S[i] == 'R') A_cnt++;
			else if (S[i] == 'B') B_cnt++;
			else assert(false);
		}
		if (A_cnt > B_cnt) {
			cout << "Alice" << '\n';
		} else if (A_cnt < B_cnt) {
			cout << "Bob" << '\n';
		} else {
			assert(A_cnt == B_cnt);
			int nim_val = 0;
			for (int i = 0; i < int(S.size()); i++) {
				int cnt = 1;
				while (i+1 < int(S.size()) && S[i+1] != S[i]) i++, cnt++;
				nim_val ^= get_nimber(cnt);
			}
			if (nim_val == 0) {
				cout << "Bob" << '\n';
			} else {
				cout << "Alice" << '\n';
			}
		}
	}

	return 0;
}