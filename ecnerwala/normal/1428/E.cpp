#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K; cin >> N >> K;

	auto sq = [](int a) -> int64_t {
		return int64_t(a) * int64_t(a);
	};

	auto split_cost = [&](int a, int k) {
		k++; // one more piece than cuts
		return sq(a/k) * k + (sq(a/k+1) - sq(a/k)) * (a%k);
	};

	priority_queue<tuple<int64_t, int, int>> pq;
	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ans += split_cost(a, 0);
		pq.push({split_cost(a, 0) - split_cost(a, 1), a, 1});
	}
	for (int z = 0; z < K-N; z++) {
		auto [c, a, k] = pq.top(); pq.pop();
		ans -= c;
		pq.push({split_cost(a, k) - split_cost(a, k+1), a, k+1});
	}
	cout << ans << '\n';

	return 0;
}