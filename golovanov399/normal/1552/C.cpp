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
	int n = nxt(), k = nxt();
	vector<pair<int, int>> edges(k);
	vector<char> used(2 * n, false);
	for (int i = 0; i < k; ++i) {
		edges[i].first = nxt() - 1, edges[i].second = nxt() - 1;
		used[edges[i].first] = used[edges[i].second] = true;
	}
	vector<int> good;
	for (int i = 0; i < 2 * n; ++i) {
		if (!used[i]) {
			good.push_back(i);
		}
	}
	for (int i = 0; i < n - k; ++i) {
		edges.push_back({good[i], good[i + n - k]});
	}
	for (auto& [x, y] : edges) {
		if (x > y) {
			swap(x, y);
		}
	}
	int ans = 0;
	sort(all(edges));
	for (const auto& p : edges) {
		for (const auto& q : edges) {
			if (p == q) {
				break;
			}
			ans += p.first < q.second && q.second < p.second;
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}