#include <bits/stdc++.h>

template <typename T> using min_pq = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T> using max_pq = std::priority_queue<T, std::vector<T>, std::less<T>>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<pair<int64_t, int64_t>> A(N);
	for (int i = 0; i < N; i++) {
		int64_t x, y; cin >> x >> y;
		A[i] = {x+y, x-y};
	}
	sort(A.begin(), A.end());

	int64_t ans = 0;

	int64_t lo_shift = 0;
	max_pq<int64_t> lo;
	for (int i = 0; i < N+1; i++) {
		lo.push(0);
	}
	int64_t hi_shift = 0;
	min_pq<int64_t> hi;
	for (int i = 0; i < N+1; i++) {
		hi.push(0);
	}

	int64_t cur_sum = 0;
	for (auto [nxt_sum, v] : A) {
		lo_shift -= (nxt_sum - cur_sum);
		hi_shift += (nxt_sum - cur_sum);
		cur_sum = nxt_sum;

		// add v
		assert(!lo.empty());
		assert(!hi.empty());
		assert(lo.top() + lo_shift <= hi.top() + hi_shift);
		assert(lo.size() == hi.size());
		if (v < lo.top() + lo_shift) {
			ans += (lo.top() + lo_shift) - v;
			lo.push(v - lo_shift);
			lo.push(v - lo_shift);
			hi.push(lo.top() + lo_shift - hi_shift);
			lo.pop();
		} else if (v > hi.top() + hi_shift) {
			ans += v - (hi.top() + hi_shift);
			hi.push(v - hi_shift);
			hi.push(v - hi_shift);
			lo.push(hi.top() + hi_shift - lo_shift);
			hi.pop();
		} else {
			lo.push(v - lo_shift);
			hi.push(v - hi_shift);
		}
	}

	ans /= 2;
	cout << ans << '\n';

	return 0;
}