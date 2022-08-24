#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Seg {
	int idx;
	int l, r;
};

struct Event {
	int t;
	int i;
	int sign;

	bool operator <(const Event& ot) const {
		return tie(t, sign) < tie(ot.t, ot.sign);
	}
};

void solve() {
	int n = nxt(), m = nxt();
	vector<Event> evs(m);
	for (int i = 0; i < m; ++i) {
		int idx = nxt() - 1, l = nxt() - 1, r = nxt();
		evs.push_back({l, idx, 1});
		evs.push_back({r, idx, -1});
	}

	vector<vector<int>> deps(n);
	map<int, int> M;
	sort(all(evs));
	for (const auto& e : evs) {
		M[e.i] += e.sign;
		auto it = M.find(e.i);
		if (it->second == 0) {
			if (next(it) != M.end() && it != M.begin()) {
				deps[next(it)->first].push_back(prev(it)->first);
			}
			M.erase(it);
		} else if (e.sign == 1 && it->second == 1) {
			if (next(it) != M.end()) {
				deps[next(it)->first].push_back(e.i);
			}
			if (it != M.begin()) {
				deps[e.i].push_back(prev(it)->first);
			}
		}
	}

	vector<pair<int, int>> dp(n, {1, -1});
	for (int i = 0; i < n; ++i) {
		for (int j : deps[i]) {
			dp[i] = max(dp[i], {dp[j].first + 1, j});
		}
	}

	vector<char> to_remove(n, 1);
	int v = max_element(all(dp)) - dp.begin();
	cout << n - dp[v].first << "\n";
	while (v > -1) {
		to_remove[v] = 0;
		v = dp[v].second;
	}
	for (int i = 0; i < n; ++i) {
		if (to_remove[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}