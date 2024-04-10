#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	map<pair<int, int>, int> mp;
	int num_lt = 0;
	int num_le = 0;
	mp[{num_lt, num_le}] ++;
	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		int v; cin >> v;
		num_lt += (v < M ? 1 : -1);
		num_le += (v <= M ? 1 : -1);
		// For the odd case, num_lt - o should be -1 and num_le - o should be 1
		ans += mp[{num_lt - (-1), num_le - (1)}];
		// For the even case, num_lt - o should be -2, and num_le - o should be 0
		ans += mp[{num_lt - (-2), num_le - (0)}];
		mp[{num_lt, num_le}]++;
	}
	cout << ans << '\n';

	return 0;
}