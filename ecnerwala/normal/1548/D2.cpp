#include <bits/stdc++.h>

int64_t solve(const std::vector<std::array<int64_t, 2>>& P) {
	int N = int(P.size());
	using std::array;
	int64_t ans = 0;

	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			array<array<int64_t, 2>, 2> cnt;
			cnt[0] = cnt[1] = {0,0};
			int cur_N = 0;
			for (int i = 0; i < N; i++) {
				auto [x, y] = P[i];
				if ((x & 1) == a && (y & 1) == b) {
					x >>= 1, y >>= 1;
					x &= 1, y &= 1;
					cnt[x][y]++;
					cur_N++;
				}
			}

			auto c3 = [](int64_t v) -> int64_t { return v * (v-1) / 2 * (v-2) / 3; };
			ans += c3(cur_N);
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					ans -= cnt[i^1][j] * cnt[i^1][j^1] * cnt[i][j^1];
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int cnt[4][4][2];
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < N; j++) {
			int64_t dx = P[j][0] - P[i][0];
			int64_t dy = P[j][1] - P[i][1];
			if (!(dx & 1) && !(dy & 1)) continue;
			int64_t g = std::gcd(dx, dy);
			assert(g > 0);
			assert(g & 1);
			assert(j != i);
			int ax = dx & 3;
			int ay = dy & 3;
			int ag = (g >> 1) & 1;
			for (int bx = (ax & 1); bx < 4; bx += 2) {
				for (int by = (ay & 1); by < 4; by += 2) {
					for (int bg = 0; bg < 2; bg++) {
						int v = ax * by - ay * bx;
						assert(!(v & 1));
						v &= 2;
						v += (ag * 2 + 1) + (bg * 2 + 1);
						v += ((ax-bx)|(ay-by)) & 2;
						if (!(v & 2)) {
							ans += cnt[bx][by][bg];
						}
					}
				}
			}
			cnt[ax][ay][ag]++;
		}
	}

	return ans;
}

int64_t solve_slow(const std::vector<std::array<int64_t, 2>>& P) {
	int N = int(P.size());
	int64_t ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				int64_t a2 = (P[j][0] - P[i][0]) * (P[k][1] - P[i][1]) - (P[j][1] - P[i][1]) * (P[k][0] - P[i][0]);
				if (a2 & 1) continue;
				int64_t x = std::gcd(std::abs(P[j][0] - P[i][0]), std::abs(P[j][1] - P[i][1]));
				int64_t y = std::gcd(std::abs(P[k][0] - P[j][0]), std::abs(P[k][1] - P[j][1]));
				int64_t z = std::gcd(std::abs(P[i][0] - P[k][0]), std::abs(P[i][1] - P[k][1]));
				assert(!((x+y+z) & 1));
				if ((a2 & 2) == ((x+y+z) & 2)) {
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<array<int64_t, 2>> P(N);
	for (auto& p : P) cin >> p[0] >> p[1];

	cout << solve(P) << '\n';

	return 0;
}