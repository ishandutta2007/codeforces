#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; int64_t M; cin >> N >> M;
		struct rain_t {
			int64_t x, v;
		};
		std::vector<rain_t> R(N); for (auto& r : R) cin >> r.x >> r.v;

		std::vector<std::pair<int64_t, int64_t>> coords; coords.reserve(3*N);
		for (auto r : R) {
			coords.push_back({r.x - r.v, +1});
			coords.push_back({r.x, -2});
			coords.push_back({r.x + r.v, +1});
		}
		std::sort(coords.begin(), coords.end());
		const int64_t INF = 1e18;
		int64_t lo = INF, hi = -INF;
		{
			int64_t cur_pos = 0;
			int64_t cur_val = 0;
			int64_t cur_slope = 0;
			for (int i = 0; i < int(coords.size()); i++) {
				cur_val += (coords[i].first - cur_pos) * cur_slope;
				cur_pos = coords[i].first;
				cur_slope += coords[i].second;

				if (cur_val > M) {
					lo = std::min(lo, cur_pos - (cur_val - M));
					hi = std::max(hi, cur_pos + (cur_val - M));
				}
			}
		}

		for (auto r : R) {
			if (r.x - r.v <= lo && r.x + r.v >= hi) {
				cout << '1';
			} else {
				cout << '0';
			}
		}
		cout << '\n';
	}

	return 0;
}