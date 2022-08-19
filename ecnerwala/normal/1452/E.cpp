#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M, K; cin >> N >> M >> K;
	vector<array<int, 2>> ranges(M);
	for (auto& a : ranges) { cin >> a[0] >> a[1]; a[0]--; }
	sort(ranges.begin(), ranges.end(), [&](const auto& a, const auto& b) { return a[0] + a[1] < b[0] + b[1]; });

	auto get_best = [&](const vector<int>& a) {
		int cur = 0;
		for (int i = 0; i < K; i++) {
			cur += a[i];
		}
		int ans = cur;
		for (int i = K; i < N; i++) {
			cur += a[i], cur -= a[i-K];
			ans = max(ans, cur);
		}
		return ans;
	};

	vector<int> lo_cnt(N);
	vector<int> hi_cnt(N);
	for (auto [x, y] : ranges) {
		for (int i = x; i < y; i++) hi_cnt[i]++;
	}
	int ans = get_best(lo_cnt) + get_best(hi_cnt);
	for (auto [x, y] : ranges) {
		for (int i = x; i < y; i++) hi_cnt[i]--, lo_cnt[i]++;
		ans = max(ans, get_best(lo_cnt) + get_best(hi_cnt));
	}
	cout << ans << '\n';

	return 0;
}