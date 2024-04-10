#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<array<int, 2>> pts(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		pts[i] = {y, x};
	}

	std::rotate(pts.begin(), min_element(pts.begin(), pts.end()), pts.end());
	for (int i = 1; i < N; i++) {
		pts[i][0] -= pts[0][0];
	}
	pts[0][0] = 0;

	pts.push_back(*pts.begin());
	int Y = (*max_element(pts.begin(), pts.end()))[0];

	vector<vector<double>> coords(Y+1);
	coords[0].push_back(pts[0][1]);
	coords[0].push_back(pts[0][1]);
	for (int i = 0; i < N; i++) {
		auto p = pts[i], q = pts[i+1];
		assert(p[0] != q[0]);
		if (p[0] > q[0]) swap(p, q);
		for (int y = p[0]+1; y <= q[0]; y++) {
			coords[y].push_back(p[1] + (q[1] - p[1]) * double(y - p[0]) / double(q[0] - p[0]));
		}
	}

	for (int y = 0; y <= Y; y++) {
		assert(coords[y].size() == 2);
		sort(coords[y].begin(), coords[y].end());
	}

	vector<pair<int, int>> queries(Q);
	for (int q = 0; q < Q; q++) {
		cin >> queries[q].first;
		queries[q].second = q;
	}
	sort(queries.begin(), queries.end());

	vector<array<double, 3>> pref(Q+1);
	auto add_quad = [&](double x1, double x2, array<double, 3> coeff, int sign) {
		auto comp = [](const pair<int, int>& p, double x) {
			return p.first < x;
		};
		int i1 = int(lower_bound(queries.begin(), queries.end(), x1, comp) - queries.begin());
		int i2 = int(lower_bound(queries.begin(), queries.end(), x2, comp) - queries.begin());
		if (i1 == i2) return; // let's avoid introducing any NaNs
		for (int z = 0; z < 3; z++) {
			coeff[z] *= sign;
			pref[i1][z] += coeff[z];
			pref[i2][z] -= coeff[z];
		}
	};
	auto add_above = [&](double x1, double x2, int sign) {
		if (x1 > x2) swap(x1, x2);
		add_quad(x2, 1e99, {(-x2 - x1) / 2, 1, 0}, sign);
		// (x - x1)^2 / (x2 - x1) / 2
		add_quad(x1, x2, {x1 * x1 / (x2 - x1) / 2, -x1 / (x2 - x1), 1/(x2-x1)/2}, sign);
	};
	auto add_below = [&](double x1, double x2, int sign) {
		// above - below = {x - (x1+x2)/2}
		// below = above - {x - (x1+x2)/2}
		add_above(x1, x2, sign);
		add_quad(-1e99, 1e99, {(-x2-x1)/2, 1, 0}, -sign);
	};

	for (int y = 0; y+1 <= Y; y++) {
		array<double, 2> y0 = {coords[y][0], coords[y][1]};
		array<double, 2> y1 = {coords[y+1][0], coords[y+1][1]};

		// add in half the area unconditionally
		pref[0][0] += ((y1[1] - y1[0]) + (y0[1] - y0[0])) / 2 / 2;

		// farther from the midline is more area
		add_below((y0[0]+y0[1])/2, (y1[0]+y1[1])/2, +1);
		add_above((y0[0]+y0[1])/2, (y1[0]+y1[1])/2, +1);

		// if it gets too far, subtract that part out
		add_below(y0[0], y1[0], -1);
		add_above(y0[1], y1[1], -1);
	}

	vector<double> ans(Q);
	for (int q = 0; q < Q; q++) {
		for (int z = 0; z < 3; z++) pref[q+1][z] += pref[q][z];
		ans[q] = ((pref[q][2] * queries[q].first) + pref[q][1]) * queries[q].first + pref[q][0];
	}

	vector<double> real_ans(Q);
	for (int q = 0; q < Q; q++) {
		real_ans[queries[q].second] = ans[q];
	}
	for (int q = 0; q < Q; q++) {
		cout << fixed << setprecision(10) << real_ans[q] << '\n';
	}

	return 0;
}