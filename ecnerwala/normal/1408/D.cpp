#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<array<int, 2>> A(N); for (auto& a : A) cin >> a[0] >> a[1];
	vector<array<int, 2>> B(M); for (auto& b : B) cin >> b[0] >> b[1];
	const int V = 2.1e6;
	vector<int> bad(V, -1);
	for (const auto& a : A) {
		for (const auto& b : B) {
			int bad_x = b[0] - a[0];
			int bad_y = b[1] - a[1];
			// you're bad if you're <= bad_x and <= bad_y
			if (bad_y >= 0) {
				bad[bad_y] = max(bad[bad_y], bad_x);
			}
		}
	}

	int cur_bad = -1;
	int ans = 1e9;
	for (int i = V-1; i >= 0; i--) {
		cur_bad = max(cur_bad, bad[i]);
		ans = min(ans, i + (cur_bad + 1));
	}
	cout << ans << '\n';

	return 0;
}