#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, K; cin >> N >> K;
	if ((N & 1) && !(K & 1)) {
		cout << -1 << '\n';
		exit(0);
	}

	for (int D = 0; true; D++) {
		if (D * K < N) continue;
		if ((D * K - N) & 1) continue;
		int extra_pairs = (D * K - N) / 2;
		if (1 + (extra_pairs + N-1) / N * 2 > D) continue;
		if (D > 500) {
			cout << -1 << '\n';
			exit(0);
		}

		int ans = 0;
		vector<pair<int, int>> cnt(N);
		for (int i = 0; i < N; i++) {
			cnt[i] = {1 + (extra_pairs + i) / N * 2, i};
		}
		while (D--) {
			std::nth_element(cnt.begin(), cnt.end() - K, cnt.end());
			cout << '?';
			for (int i = N-K; i < N; i++) {
				assert(cnt[i].first > 0);
				cnt[i].first--;
				cout << ' ' << cnt[i].second+1;
			}
			cout << '\n' << flush;
			int v; cin >> v;
			ans ^= v;
		}
		cout << '!' << ' ' << ans << '\n' << flush;
		break;
	}

	return 0;
}