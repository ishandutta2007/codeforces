#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	array<int, 6> A;
	for (int& a : A) cin >> a;
	sort(A.begin(), A.end());
	int N; cin >> N;
	vector<int> B(N); for (int& b : B) cin >> b;

	// Set of fret #, note #, string #
	set<tuple<int, int, int>> vals;
	for (int i = 0; i < N; i++) {
		vals.insert({B[i] - A[5], i, 5});
	}
	auto get_cur_range = [&]() -> int {
		return get<0>(*vals.rbegin()) - get<0>(*vals.begin());
	};
	int ans = get_cur_range();
	while (true) {
		auto [v, i, j] = *vals.begin();
		vals.erase(vals.begin());
		if (j == 0) {
			// this string is already as long as possible, so we're stuck
			break;
		}
		j--;
		vals.insert({B[i] - A[j], i, j});
		ans = min(ans, get_cur_range());
	}
	cout << ans << '\n';

	return 0;
}