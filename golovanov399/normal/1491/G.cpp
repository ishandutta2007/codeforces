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
	int n = nxt();
	vector<int> p(n), q(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
		q[p[i]] = i;
	}
	vector<vector<int>> cycles;
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		if (q[i] == i) {
			continue;
		}
		cycles.push_back({});
		for (int x = i; !used[x]; x = q[x]) {
			cycles.back().push_back(x);
			used[x] = 1;
		}
	}

	vector<pair<int, int>> ans;

	auto swap_coins = [&](int u, int v) {
		ans.push_back({q[u], q[v]});
		swap(q[u], q[v]);
		swap(p[q[u]], p[q[v]]);
	};

	while ((int)cycles.size() >= 2) {
		auto c1 = cycles.back();
		cycles.pop_back();
		auto c2 = cycles.back();
		cycles.pop_back();
		swap_coins(c1[0], c2[0]);
		for (int i = 0; i < (int)c1.size() - 1; ++i) {
			swap_coins(c1[((int)c1.size() - i) % c1.size()], c1[(int)c1.size() - i - 1]);
		}
		for (int i = 0; i < (int)c2.size() - 1; ++i) {
			swap_coins(c2[((int)c2.size() - i) % c2.size()], c2[(int)c2.size() - i - 1]);
		}
		swap_coins(c1[1], c2[1]);
	}
	if (!cycles.empty()) {
		auto c = cycles[0];
		if ((int)c.size() == 2) {
			int another = 0;
			while (find(all(c), another) != c.end()) {
				++another;
			}
			swap_coins(another, c[1]);
			swap_coins(c[0], c[1]);
			swap_coins(c[0], another);
		} else {
			for (int i = (int)c.size() - 1; i > 1; --i) {
				swap_coins(c[i], c[i - 1]);
			}
			swap_coins(c[0], c.back());
			swap_coins(c.back(), c[1]);
			swap_coins(c[0], c.back());
		}
	}
	// assert(is_sorted(all(q)));
	cout << ans.size() << "\n";
	for (auto [u, v] : ans) {
		cout << u + 1 << " " << v + 1 << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}