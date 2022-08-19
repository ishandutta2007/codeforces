#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t cap[2]; cin >> cap[0] >> cap[1];
		int64_t count[2]; cin >> count[0] >> count[1];
		int64_t weight[2]; cin >> weight[0] >> weight[1];
		if (weight[0] > weight[1]) {
			swap(weight[0], weight[1]);
			swap(count[0], count[1]);
		}

		int64_t ans = 0;
		for (int heavy0 = 0; heavy0 <= count[1] && weight[1] * heavy0 <= cap[0]; heavy0++) {
			int64_t light0 = min(count[0], (cap[0] - weight[1] * heavy0) / weight[0]);
			int64_t light1 = min(count[0] - light0, cap[1] / weight[0]);
			int64_t heavy1 = min(count[1] - heavy0, (cap[1] - weight[0] * light1) / weight[1]);

			ans = max(ans, heavy0 + light0 + light1 + heavy1);
		}
		cout << ans << '\n';
	}

	return 0;
}