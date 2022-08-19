#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, X, Y; cin >> N >> X >> Y;
		vector<int> B(N);
		for (int i = 0; i < N; i++) cin >> B[i];

		vector<vector<int>> freq(N+2);
		for (int i = 0; i < N; i++) {
			freq[B[i]].push_back(i);
		}
		int extra = 1;
		while (!freq[extra].empty()) extra++;

		vector<int> ans(N, extra);

		priority_queue<pair<int, int>> pq;
		for (int v = 1; v <= N+1; v++) {
			pq.emplace(int(freq[v].size()), v);
		}

		for (int z = 0; z < X; z++) {
			int a = pq.top().second; pq.pop();

			int i = freq[a].back();
			freq[a].pop_back();

			ans[i] = a;

			pq.emplace(int(freq[a].size()), a);
		}

		int offset = pq.top().first;
		if (offset * 2 - (N-Y) > N-X) {
			cout << "NO" << '\n';
			continue;
		}
		vector<int> other_inds; other_inds.reserve(N-X);
		while (!pq.empty()) {
			int v = pq.top().second; pq.pop();
			other_inds.insert(other_inds.end(), freq[v].begin(), freq[v].end());
		}
		assert(int(other_inds.size()) == N-X);

		for (int i = 0; i < N-X; i++) {
			ans[other_inds[(i+offset)%(N-X)]] = B[other_inds[i]];
		}
		for (int i = 0; i < N-Y; i++) {
			ans[other_inds[i]] = extra;
		}
		for (int i = 0; i < N-X; i++) {
			assert(ans[other_inds[i]] != B[other_inds[i]]);
		}

		cout << "YES" << '\n';
		for (int i = 0; i < N; i++) {
			cout << ans[i] << " \n"[i+1==N];
		}
	}

	return 0;
}