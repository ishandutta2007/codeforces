#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int V = int(1.1e6);
	vector<int> sqf(V+1);
	for (int i = 1; i <= V; i++) {
		if (sqf[i]) continue;
		for (int j = 1; i * j * j <= V; j++) {
			sqf[i*j*j] = i;
		}
	}

	vector<int> cnt(V+1, 0);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) { cin >> a; a = sqf[a]; }

		for (auto a : A) {
			cnt[a]++;
		}
		int beauty_0 = 0;
		int new_group = 0;
		for (auto a : A) {
			if (cnt[a] == 0) continue;
			beauty_0 = max(beauty_0, cnt[a]);
			if (a == 1 || !(cnt[a] & 1)) new_group += cnt[a];
			cnt[a] = 0;
		}

		int beauty_1 = max(beauty_0, new_group);

		int Q; cin >> Q;
		while (Q--) {
			int64_t w; cin >> w;
			if (w >= 1) cout << beauty_1 << '\n';
			else cout << beauty_0 << '\n';
		}
	}

	return 0;
}