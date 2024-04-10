#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Hexagon {
	int min_x, min_y, max_x, max_y, min_ymx, max_ymx;
};

Hexagon operator &(const Hexagon& a, const Hexagon& b) {
	return {
		max(a.min_x, b.min_x),
		max(a.min_y, b.min_y),
		min(a.max_x, b.max_x),
		min(a.max_y, b.max_y),
		max(a.min_ymx, b.min_ymx),
		min(a.max_ymx, b.max_ymx)
	};
}

Hexagon def() {
	return {0, 0, (int)1e7, (int)1e7, (int)-1e7, (int)1e7};
}

void solve() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c : s) {
			(c == 'B' ? a[i].first : a[i].second) += 1;
		}
		// cerr << a[i].first << " " << a[i].second << "\n";
	}

	pair<int, int> found;
	auto check = [&](int d) {
		Hexagon cur = def();
		for (auto [x, y] : a) {
			cur = cur & Hexagon{x - d, y - d, x + d, y + d, y - x - d, y - x + d};
		}
		// cerr << d << ": " << "[" << cur.min_x << ", " << cur.max_x << "] x [" << cur.min_y << ", " << cur.max_y << "] x [" << cur.min_ymx << ", " << cur.max_ymx << "]\n";
		if (cur.min_x > cur.max_x) {
			return false;
		}
		if (cur.min_y > cur.max_y) {
			return false;
		}
		if (cur.min_ymx > cur.max_ymx) {
			return false;
		}
		if (cur.max_ymx < cur.min_y - cur.max_x) {
			return false;
		}
		if (cur.min_ymx > cur.max_y - cur.min_x) {
			return false;
		}
		if (cur.max_ymx < cur.max_y - cur.max_x) {
			found = {cur.max_x, cur.max_ymx + cur.max_x};
			return true;
		} else if (cur.min_ymx > cur.max_y - cur.max_x) {
			found = {cur.max_y - cur.min_ymx, cur.max_y};
			return true;
		} else {
			found = {cur.max_x, cur.max_y};
			return true;
		}
		assert(false);
	};

	int l = -1, r = 1e6;
	while (r > l + 1) {
		int m = (l + r) / 2;
		(check(m) ? r : l) = m;
	}
	assert(check(r));
	cout << r << "\n";
	cout << string(found.first, 'B') << string(found.second, 'N') << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}