#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<pair<vector<int>, vector<int>>> vs(1);
	vs[0].first.resize(n);
	vs[0].second.resize(n);
	generate(all(vs[0].first), nxt);
	generate(all(vs[0].second), nxt);
	int ans = 0;
	for (int bi = 29; bi >= 0; --bi) {
		const int bit = 1 << bi;
		decltype(vs) nvs;
		bool ok = true;
		for (const auto& [a, b] : vs) {
			if (a.empty()) {
				continue;
			}
			vector<int> nwa[2], nwb[2];
			for (int x : a) {
				nwa[!!(x & bit)].push_back(x);
			}
			for (int x : b) {
				nwb[!!(x & bit)].push_back(x);
			}
			if (nwa[0].size() == nwb[1].size()) {
				nvs.push_back({nwa[0], nwb[1]});
				nvs.push_back({nwa[1], nwb[0]});
			} else {
				ok = false;
			}
		}
		if (ok) {
			vs = nvs;
			ans |= bit;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}