#include <bits/stdc++.h>

template <typename T> using min_pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<pair<int64_t, int64_t>> A(N);
	for (auto& a : A) {
		cin >> a.first >> a.second;
	}

	sort(A.begin(), A.end());
	int64_t ans = 0;
	for (auto a : A) ans += a.second;

	int64_t best_start = A[0].first;
	min_pq<pair<int64_t, int64_t>> to_vis;
	min_pq<pair<int64_t, int64_t>> flat_vis;
	for (int i = 0; i < N; i++) {
		while (!to_vis.empty() && to_vis.top().first <= A[i].first) {
			best_start = max(best_start, to_vis.top().second);
			to_vis.pop();
		}
		while (!flat_vis.empty() && flat_vis.top().second <= A[i].first) flat_vis.pop();

		int64_t d = A[i].first - best_start;
		if (!flat_vis.empty()) d = min(d, flat_vis.top().first);

		if (i == N-1) {
			ans += d;
			break;
		}
		to_vis.push({A[i].first + A[i].second, A[i].first + A[i].second - d});
		flat_vis.push({d, A[i].first + A[i].second});
	}

	cout << ans << '\n';

	return 0;
}