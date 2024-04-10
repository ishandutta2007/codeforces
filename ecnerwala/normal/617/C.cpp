#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	using pt = array<int64_t, 2>;

	int N; cin >> N;
	array<pt, 2> S; cin >> S[0][0] >> S[0][1] >> S[1][0] >> S[1][1];


	auto sq = [](auto x) { return x * x; };

	vector<array<int64_t, 2>> pts(N);
	for (int i = 0; i < N; i++) {
		pt p; cin >> p[0] >> p[1];
		for (int z = 0; z < 2; z++) {
			pts[i][z] = sq(S[z][0] - p[0]) + sq(S[z][1] - p[1]);
		}
	}
	sort(pts.begin(), pts.end());
	for (int i = N-1; i > 0; i--) {
		pts[i-1][1] = max(pts[i-1][1], pts[i][1]);
	}

	int64_t ans = min(pts.front()[1], pts.back()[0]);
	for (int i = 0; i+1 < N; i++) {
		ans = min(ans, pts[i][0] + pts[i+1][1]);
	}
	cout << ans << '\n';

	return 0;
}