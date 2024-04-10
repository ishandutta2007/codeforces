#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (auto& v : a) {
		generate(all(v), nxt);
	}

	if (all_of(all(a), [](const vector<int>& v) { return is_sorted(all(v)); })) {
		cout << "1 1\n";
		return;
	}

	auto cmp = [&](int i, int j) {
		return all_of(all(a), [&](const vector<int>& v) { return v[i] <= v[j]; });
	};
	vector<int> perm(m);
	iota(all(perm), 0);
	auto check = [&](int i, int j) {
		swap(perm[i], perm[j]);
		bool ans = true;
		for (int k = 0; k < m - 1; ++k) {
			if (!cmp(perm[k], perm[k + 1])) {
				ans = false;
				break;
			}
		}
		swap(perm[i], perm[j]);
		return ans;
	};

	for (const auto& v : a) {
		if (is_sorted(all(v))) {
			continue;
		}
		int pos = 0;
		while (v[pos] <= v[pos + 1]) {
			++pos;
		}

		vector<int> nx(m, m);
		for (int i = m - 2; i >= 0; --i) {
			if (v[i] <= v[i + 1]) {
				nx[i] = nx[i + 1];
			} else {
				nx[i] = i + 1;
			}
		}
		auto subcheck = [&](int l, int r) {
			if (l > r) {
				swap(l, r);
			}
			if (l == r) {
				return false;
			}
			if (nx[0] < l || nx[l + 1] < r || (r < m - 1 && nx[r + 1] < m)) {
				return false;
			}
			if (l > 0 && v[l - 1] > v[r]) {
				return false;
			}
			if (l + 1 < r) {
				if (v[r] > v[l + 1] || v[r - 1] > v[l]) {
					return false;
				}
			} else {
				if (v[r] > v[l]) {
					return false;
				}
			}
			if (r < m - 1 && v[l] > v[r + 1]) {
				return false;
			}
			return true;
		};
		vector<pair<int, int>> cands;
		for (int j = 0; j < m; ++j) {
			for (int p : {pos, pos + 1}) {
				if (subcheck(p, j)) {
					cands.push_back({j, p});
				}
			}
		}
		for (auto [x, y] : cands) {
			if (check(x, y)) {
				cout << x + 1 << " " << y + 1 << "\n";
				return;
			}
		}

		cout << "-1\n";
		return;
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}