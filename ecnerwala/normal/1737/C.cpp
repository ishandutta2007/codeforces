#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::array<std::array<int, 2>, 3> locs;
		for (auto& [x, y] : locs) { cin >> x >> y; }
		std::array<int, 2> tgt;
		cin >> tgt[0] >> tgt[1];

		auto solve = [&]() -> bool {
			{
				bool has = false;
				for (auto l : locs) {
					if ((tgt[0] - l[0]) & 1) continue;
					if ((tgt[1] - l[1]) & 1) continue;
					has = true;
				}
				if (!has) return false;
			}
			{
				int num_x = 0, num_y = 0;
				for (auto l : locs) {
					if (l == tgt) return true;
					if (l[0] == tgt[0]) num_x++;
					if (l[1] == tgt[1]) num_y++;
				}
				if (num_x == 2 || num_y == 2) return true;
			}
			// if you're cornered, you're kinda screwed
			std::array<int, 3> xs{locs[0][0], locs[1][0], locs[2][0]};
			std::array<int, 3> ys{locs[0][1], locs[1][1], locs[2][1]};
			std::sort(xs.begin(), xs.end());
			std::sort(ys.begin(), ys.end());
			int mx = xs[1];
			int my = ys[1];
			if ((mx == 1 || mx == N) && (my == 1 || my == N)) return false;
			return true;
		};

		cout << (solve() ? "YES" : "NO") << '\n';
	}

	return 0;
}