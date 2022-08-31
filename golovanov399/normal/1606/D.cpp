#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Shit {
	int n, m;
	vector<vector<bool>> a;
	vector<char> rows;
	vector<int> len;
	vector<int> cnt;
	vector<int> bad_cnt;
	int min_bad;
	int curmin;

	Shit(int _n, int _m): n(_n), m(_m), a(_n, vector<bool>(_m, false)), rows(_n, false), len(_n, 0), cnt(_m + 1, 0), bad_cnt(_m, 0), min_bad(_m), curmin(0) {}

	void set(int x, int y) {
		a[x][y] = true;
		if (y == 0) {
			rows[x] = true;
			curmin = 0;
			cnt[0] += 1;
			for (int i = 1; i < m; ++i) {
				if (a[x][i]) {
					--bad_cnt[i];
				}
			}
			while (min_bad < m && bad_cnt[min_bad] == 0) {
				++min_bad;
			}
		}
		if (!rows[x]) {
			bad_cnt[y] += 1;
			min_bad = std::min(min_bad, y);
		}
		if (rows[x] && len[x] < m && a[x][len[x]]) {
			cnt[len[x]] -= 1;
			while (len[x] < m && a[x][len[x]]) {
				++len[x];
			}
			cnt[len[x]] += 1;
			while (cnt[curmin] == 0) {
				++curmin;
			}
		}
	}

	int min() const {
		return std::min(min_bad, curmin);
	}
};

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = nxt();
		}
	}

	vector<array<int, 3>> cells;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cells.push_back({{a[i][j], i, j}});
		}
	}
	sort(all(cells));

	Shit forw(n, m), back(n, m);

	vector<int> left_order, right_order;
	vector<int> best_left(n + 1, 0);
	vector<int> best_right(n + 1, 0);
	for (int i = 0; i < (int)cells.size(); ++i) {
		auto [v, x, y] = cells[i];
		forw.set(x, y);
		if (y == 0) {
			left_order.push_back(x);
		}
		if (i < (int)cells.size() - 1 && v != cells[i + 1][0]) {
			best_left[left_order.size()] = max(best_left[left_order.size()], forw.min());
		}
	}
	for (int i = 0; i < (int)cells.size(); ++i) {
		auto [v, x, y] = cells[i];
		back.set(x, m - 1 - y);
		if (y == m - 1) {
			right_order.push_back(x);
		}
		if (i < (int)cells.size() - 1 && v != cells[i + 1][0]) {
			best_right[right_order.size()] = max(best_right[right_order.size()], back.min());
		}
	}
	transform(all(best_left), best_left.begin(), [&](int x) { return min(x, m - 1); });
	transform(all(best_right), best_right.begin(), [&](int x) { return min(x, m - 1); });

	// for (auto x : left_order) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (auto x : right_order) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (auto x : best_left) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (auto x : best_right) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	vector<int> rcnt(n, 1);
	int one_cnt = n;
	auto add = [&](int pos, int x) {
		if (rcnt[pos] == 1) {
			--one_cnt;
		}
		rcnt[pos] += x;
		if (rcnt[pos] == 1) {
			++one_cnt;
		}
	};

	for (int i = 0; i < n - 1; ++i) {
		add(right_order[n - 1 - i], -1);
		add(left_order[i], 1);
		if (one_cnt == n && best_left[i + 1] + best_right[n - 1 - i] >= m) {
			cout << "YES\n";
			string s(n, 'R');
			for (int j = 0; j <= i; ++j) {
				s[left_order[j]] = 'B';
			}
			cout << s << " " << best_left[i + 1] << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}