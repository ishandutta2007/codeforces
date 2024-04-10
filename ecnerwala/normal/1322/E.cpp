#include <bits/stdc++.h>

template <typename T, typename Comp> struct monotonic_queue {
	std::vector<std::pair<T, int>> q;
	int lo, hi;
	monotonic_queue(int max_sz) : q(max_sz), lo(0), hi(0) { }
	void push(T val, int idx) {
		while (hi > lo && Comp()(val, q[hi-1].first)) --hi;
		q[hi++] = {val, idx};
	}
	void pop(int idx) {
		if (lo < hi && q[lo].second == idx) lo++;
	}
	T get_val() const {
		assert(lo < hi);
		return q[lo].first;
	}
	T get_val(T other) const {
		if (lo < hi && Comp()(q[lo].first, other)) return q[lo].first;
		return other;
	}
};

template <typename T> using min_monotonic_queue = monotonic_queue<T, std::less<T>>;
template <typename T> using max_monotonic_queue = monotonic_queue<T, std::greater<T>>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;

	int C = 0;
	vector<int> ans(N);

	array<min_monotonic_queue<int>, 2> mins{min_monotonic_queue<int>{(N+1)/2}, {N/2}};
	array<max_monotonic_queue<int>, 2> maxs{max_monotonic_queue<int>{(N+1)/2}, {N/2}};

	for (int l = 0, r = 0; l < N; ) {
		if ((r - l) & 1) {
			// take the current state as maximal
			int m = (l + r - 1) / 2;
			C = max(C, (r - l - 1) / 2);
			if (r - l == 1) {
				ans[m] = A[m];
			} else if (mins[l&1].get_val() > maxs[!(l&1)].get_val()) {
				ans[m] = mins[l&1].get_val();
			} else if (maxs[l&1].get_val() < mins[!(l&1)].get_val()) {
				ans[m] = maxs[l&1].get_val();
			} else assert(false);
		}
		if (r < N && (l == r || mins[r&1].get_val(A[r]) > maxs[!(r&1)].get_val() || maxs[r&1].get_val(A[r]) < mins[!(r&1)].get_val())) {
			mins[r&1].push(A[r], r);
			maxs[r&1].push(A[r], r);
			r++;
		} else {
			mins[l&1].pop(l);
			maxs[l&1].pop(l);
			l++;
		}
	}

	cout << C << '\n';
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i+1==N];
	}

	return 0;
}