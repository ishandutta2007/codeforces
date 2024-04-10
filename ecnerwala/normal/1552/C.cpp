#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<bool> used(2*N);
		vector<array<int, 2>> pairs; pairs.reserve(N);
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x >> y; x--, y--;
			if (x > y) swap(x, y);
			used[x] = used[y] = true;
			pairs.push_back({x, y});
		}
		vector<int> unused; unused.reserve(2*(N-K));
		for (int i = 0; i < 2*N; i++) if (!used[i]) unused.push_back(i);
		for (int i = 0; i < N-K; i++) {
			pairs.push_back({unused[i], unused[N-K+i]});
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (max(pairs[i][0], pairs[j][0]) > min(pairs[i][1], pairs[j][1])) continue;
				if (pairs[i][0] < pairs[j][0] && pairs[j][1] < pairs[i][1]) continue;
				if (pairs[j][0] < pairs[i][0] && pairs[i][1] < pairs[j][1]) continue;
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}