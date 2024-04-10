#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	string S; cin >> S;
	std::vector<std::array<int, 2>> pref(N);
	for (int i = 1; i < N; i++) {
		pref[i] = pref[i-1];
		if (S[i-1] == S[i]) pref[i][S[i]-'0']++;
	}
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r; l--, r--;
		std::array<int, 2> cnt;
		for (int z = 0; z < 2; z++) cnt[z] = pref[r][z] - pref[l][z];
		cout << std::max(cnt[0], cnt[1]) + 1 << '\n';
	}

	return 0;
}