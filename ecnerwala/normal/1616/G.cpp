#define NDEBUG
#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<std::array<int, 2>> E(M);
		for (auto& e : E) {
			cin >> e[0] >> e[1];
		}

		std::vector<bool> is_bad(N+1, true);
		is_bad[0] = is_bad[N] = false;
		for (auto [a, b] : E) {
			if (b - a == 1) is_bad[a] = false;
		}

		std::vector<int> pref_bad(N+2);
		int first_bad = -1;
		int last_bad = -1;
		for (int i = 0; i <= N; i++) {
			if (is_bad[i]) {
				if (first_bad == -1) first_bad = i;
				last_bad = i;
			}
			pref_bad[i+1] = pref_bad[i] + is_bad[i];
		}

		if (first_bad == -1) {
			cout << int64_t(N) * int64_t(N-1) / 2 << '\n';
			continue;
		}

		assert(last_bad != -1);

		std::vector<std::vector<int>> adj(N+1);
		auto add_edge = [&](int a, int b) -> void {
			assert(a < b);
			if (b - a == 1) return;
			assert(b - a >= 2);
			b--;
			assert(b - a >= 1);
			if (pref_bad[b] - pref_bad[a+1] > 0) {
				return;
			}
			assert(b <= first_bad || (first_bad <= a && a <= b && b <= last_bad) || last_bad <= a);
			if (b <= first_bad) adj[a].push_back(b);
			else adj[b].push_back(a);
		};
		for (auto [a, b] : E) {
			add_edge(a, b);
		}
		std::vector<int> dp(N+1);
		dp[first_bad] = 1;
		dp[0] = 2;
		for (int i = first_bad-1; i > 0; i--) {
			int v = 0;
			for (int j : adj[i]) {
				v |= dp[j];
			}
			dp[0] |= v;
			if (v == 1 || v == 2) v ^= 3;
			dp[i] = v;
		}
		if (first_bad == last_bad) dp[N] = 2;
		for (int i = first_bad+1; i < N; i++) {
			int v = 0;
			for (int j : adj[i]) {
				v |= dp[j];
			}
			if (i >= last_bad) dp[N] |= v;
			if (v == 1 || v == 2) v ^= 3;
			dp[i] = v;
		}

		std::array<int, 4> cnt_forwards; cnt_forwards.fill(0);
		for (int i = 0; i <= first_bad; i++) {
			cnt_forwards[dp[i]]++;
		}
		std::array<int, 4> cnt_backwards; cnt_backwards.fill(0);
		for (int i = last_bad; i <= N; i++) {
			cnt_backwards[dp[i]]++;
		}

		int64_t ans = 0;
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (x & y) {
					ans += int64_t(cnt_forwards[x]) * int64_t(cnt_backwards[y]);
				}
			}
		}
		if (first_bad == last_bad) {
			ans--;
		}
		cout << ans << '\n';
	}

	return 0;
}