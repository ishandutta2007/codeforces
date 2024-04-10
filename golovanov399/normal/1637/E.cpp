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
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		cnt[nxt()] += 1;
	}
	vector<pair<int, int>> banned(m);
	for (int i = 0; i < m; ++i) {
		int x = nxt(), y = nxt();
		banned[i] = {x, y};
	}
	sort(all(banned));
	
	map<int, vector<int>> by_cnt;
	for (auto [k, v] : cnt) {
		by_cnt[v].push_back(k);
	}

	set<pair<int, int>> used;

	auto f = [&](const vector<int>& v1, const vector<int>& v2) -> long long {
		priority_queue<tuple<int, int, int>> pq;
		pq.push({v1.back() + v2.back(), (int)v1.size() - 1, (int)v2.size() - 1});
		while (!pq.empty()) {
			auto [val, i, j] = pq.top();
			pq.pop();
			pair<int, int> ij = {min(v1[i], v2[j]), max(v1[i], v2[j])};
			if (used.count(ij)) {
				continue;
			}
			used.insert(ij);
			if (v1[i] != v2[j] && !binary_search(all(banned), ij)) {
				return val;
			}
			if (i) {
				pq.push({v1[i - 1] + v2[j], i - 1, j});
			}
			if (j) {
				pq.push({v1[i] + v2[j - 1], i, j - 1});
			}
		}
		return 0;
	};

	long long ans = 0;
	for (const auto& [c1, v1] : by_cnt) {
		for (const auto& [c2, v2] : by_cnt) {
			ans = max(ans, f(v1, v2) * (c1 + c2));
			if (c1 == c2) {
				break;
			}
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