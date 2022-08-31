#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	string s;
	cin >> s;
	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}

	int n = nxt();
	vector<int> gays(n);
	generate(all(gays), nxt);
	vector<char> used(n, false);
	vector<vector<int>> faggots;
	while (!*min_element(all(used))) {
		faggots.push_back({});
		auto& vec = faggots.back();
		for (int i = 0; i < n; ++i) {
			if (!used[i] && !gays[i]) {
				vec.push_back(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!used[i] && gays[i]) {
				for (int j : vec) {
					gays[i] -= abs(i - j);
				}
			}
		}
		for (int i : vec) {
			used[i] = true;
		}
	}
	string t(n, '?');
	for (int i = 0, j = 25; i < (int)faggots.size(); ++i) {
		while (cnt[j] < (int)faggots[i].size()) {
			--j;
		}
		for (int x : faggots[i]) {
			t[x] = 'a' + j;
		}
		--j;
	}
	cout << t << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}