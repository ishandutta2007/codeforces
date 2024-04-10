#include<bits/stdc++.h>

struct frac {
	int x, y;
	frac(int x_, int y_) : x(x_), y(y_) {
		assert(y > 0);
	}
	explicit operator double () const { return double(x) / double(y); }
	friend bool operator < (const frac& a, const frac& b) { return int64_t(a.x) * b.y < int64_t(b.x) * a.y; }
	friend bool operator == (const frac& a, const frac& b) { return int64_t(a.x) * b.y == int64_t(b.x) * a.y; }
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	struct seg {
		array<int, 2> x;
		int y;
	};
	vector<seg> segs(N); for (auto& s : segs) cin >> s.x[0] >> s.x[1] >> s.y;

	vector<array<int, 2>> rnk(N, array<int, 2>{0,0});

	vector<tuple<frac, bool, array<int, 2>>> evts; evts.reserve(N*N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			seg a = segs[i];
			seg b = segs[j];
			if (make_pair(-a.y, a.x[0]) > make_pair(-b.y, b.x[0])) continue;

			// starts of i < j
			rnk[i][0]++;
			rnk[j][1]++;
			if (a.y == b.y) {
				assert(a.x[1] < b.x[0]);
				continue;
			}
			assert(a.y > b.y);
			evts.emplace_back(frac(b.x[0] - a.x[1], a.y - b.y), true, array<int, 2>{i, j});
			evts.emplace_back(frac(b.x[1] - a.x[0], a.y - b.y), false, array<int, 2>{j, i});
		}
	}

	sort(evts.begin(), evts.end());

	int num_inter = 0;
	int min_elt = int(find(rnk.begin(), rnk.end(), array<int, 2>{N-1, 0}) - rnk.begin());
	int max_elt = int(find(rnk.begin(), rnk.end(), array<int, 2>{0, N-1}) - rnk.begin());
	assert(-segs[min_elt].y <= -segs[max_elt].y);

	double ans = 1e99;

	if (evts.empty()) {
		assert(segs[max_elt].y == segs[min_elt].y);
		ans = segs[max_elt].x[1] - segs[min_elt].x[0];
	} else {
		for (auto [s, dir, inds] : evts) {
			if (dir == false) {
				// insert
				for (int z = 0; z < 2; z++) {
					rnk[inds[z]][z]++;
					if (rnk[inds[z]] == array<int, 2>{N-1, 0}) {
						min_elt = inds[z];
					} else if (rnk[inds[z]] == array<int, 2>{0, N-1}) {
						max_elt = inds[z];
					}
				}
				if (!--num_inter) {
					ans = min(ans, double(s) * (segs[max_elt].y - segs[min_elt].y) + (segs[max_elt].x[1] - segs[min_elt].x[0]));
				}
			} else {
				if (!num_inter++) {
					ans = min(ans, double(s) * (segs[max_elt].y - segs[min_elt].y) + (segs[max_elt].x[1] - segs[min_elt].x[0]));
				}
				for (int z = 0; z < 2; z++) {
					rnk[inds[z]][z]--;
				}
			}
		}
	}
	cout << fixed << setprecision(9) << ans << '\n';

	return 0;
}