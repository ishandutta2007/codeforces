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

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<pair<int, int>>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	vector<char> used(n);
	auto check = [&](int mask) {
		vector<int> st = {0};
		fill(all(used), 0);
		int cnt = 0;
		used[0] = 1;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			++cnt;
			for (auto [x, w] : a[v]) {
				if (used[x] || (w & mask) < w) {
					continue;
				}
				used[x] = 1;
				st.push_back(x);
			}
		}
		return cnt == n;
	};
	const int L = 30;
	int mask = (1 << L) - 1;
	for (int i = L - 1; i >= 0; --i) {
		if (check(mask ^ (1 << i))) {
			mask ^= 1 << i;
		}
	}
	cout << mask << "\n";
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