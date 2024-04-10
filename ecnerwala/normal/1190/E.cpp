#include<bits/stdc++.h>
using namespace std;

const double PI = atan2(1, 0) * 2;
const double TAU = atan2(1, 0) * 4;

const int MAXN = 1.1e5;
int N;
int M;
pair<double, double> pts[MAXN]; // len, atan2

int nxt[MAXN];
pair<double, double> ranges[MAXN * 3];
pair<double, int> right_pts[MAXN * 2 + 20];

bool isGood(double dist) {
	//cerr << "numBarriers(" << dist << ")" << '\n';
	for (int i = 0; i < N; i++) {
		double angRange = acos(dist / pts[i].first);
		double a = pts[i].second - angRange;
		double b = pts[i].second + angRange;
		if (a < 0) a += TAU, b += TAU;
		ranges[i] = {a, b};
	}
	sort(ranges, ranges + N);

	for (int i = 0; i < N+10; i++) {
		ranges[i+N].first = ranges[i].first + TAU;
		ranges[i+N].second = ranges[i].second + TAU;
	}

	//for (int i = 0; i < N; i++) { cerr << ranges[i].first << '-' << ranges[i].second << '\n'; }

	auto l = right_pts, r = right_pts;
	for (int i = 0, j = -1; i < N; i++) {
		while (l == r || ranges[j].first <= l->first) {
			j++;
			// insert j
			double v = ranges[j].second;
			while (l < r && (r-1)->first >= v) {
				--r;
			}
			*r = {v, j};
			++r;
		}

		assert(j <= i+N && j > i);
		nxt[i] = j;

		if (l < r && l->second == i) l++;
	}

	auto getBarriers = [](int st) {
		int cnt = 0;
		int cur = st;
		while (cnt <= M+1 && cur < st + N) {
			cur += (nxt[cur%N] - cur%N);
			cnt++;
		}
		return cnt;
	};
	int v = getBarriers(0);
	if (v <= M) return true;
	if (v > M+1) return false;

	int a = 0, b = 0;
	do {
		a = nxt[a] % N;
		b = nxt[b] % N;
		b = nxt[b] % N;
	} while (a != b);

	return getBarriers(a) <= M;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			cout << fixed << setprecision(10) << 0. << '\n';
			exit(0);
		}
		pts[i].first = double(sqrt(x * x + y * y));
		pts[i].second = atan2(y, x);
		if (pts[i].second < 0) pts[i].second += 2 * PI;
	}
	double ma = pts[0].first;
	for (int i = 0; i < N; i++) ma = min(ma, pts[i].first);
	double mi = 0;

	if (ma > 1 && isGood(1)) {
		mi = 1;
		for (int z = 0; z < 26; z++) {
			double md = mi * sqrt(ma / mi);
			if (isGood(md)) {
				mi = md;
			} else {
				ma = md;
			}
		}
	} else {
		ma = min(ma, 1.);
		for (int z = 0; z < 20; z++) {
			double md = mi + (ma - mi) / 2;
			if (isGood(md)) {
				mi = md;
			} else {
				ma = md;
			}
		}
	}

	cout << fixed << setprecision(10) << mi << '\n';

	return 0;
}