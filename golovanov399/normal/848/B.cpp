#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Dancer {
	int x, y;
	int id;

	bool operator <(const Dancer& ot) const {
		return x + y < ot.x + ot.y || (x + y == ot.x + ot.y && x < ot.x);
	}
};

int main() {
	int n = nxt(), w = nxt(), h = nxt();
	vector<vector<Dancer>> a(2);
	vector<pair<int, int>> end(n);
	for (int i = 0; i < n; ++i) {
		int g = nxt() - 1, p = nxt(), t = -nxt();
		if (g == 1) {
			swap(t, p);
		}
		a[g].push_back({p, t, i});
		if (p > 0) {
			end[i] = {p, h};
		} else {
			end[i] = {w, t};
		}
	}

	for (int i = 0; i < 2; ++i) {
		sort(all(a[i]));
	}

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = i;
	}
	int i = 0, j = 0;
	swap(a[0], a[1]);
	while (i < (int)a[0].size() && j < (int)a[1].size()) {
		if (a[0][i].x + a[0][i].y < a[1][j].x + a[1][j].y) {
			++i;
		} else if (a[0][i].x + a[0][i].y > a[1][j].x + a[1][j].y) {
			++j;
		} else {
			int l = 0, r = 0;
			while (i + l < (int)a[0].size() && a[0][i + l].x + a[0][i + l].y == a[0][i].x + a[0][i].y) {
				++l;
			}
			while (j + r < (int)a[1].size() && a[1][j + r].x + a[1][j + r].y == a[1][j].x + a[1][j].y) {
				++r;
			}
			vector<int> ids;
			for (int k = 0; k < r; ++k) {
				ids.push_back(a[1][j + k].id);
			}
			for (int k = 0; k < l; ++k) {
				ids.push_back(a[0][i + k].id);
			}
			int cur = 0;
			for (int k = 0; k < l; ++k) {
				ans[a[0][i + k].id] = ids[cur++];
			}
			for (int k = 0; k < r; ++k) {
				ans[a[1][j + k].id] = ids[cur++];
			}
			i += l;
			j += r;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", end[ans[i]].first, end[ans[i]].second);
	}

	return 0;
}