#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {a[i], i};
	}
	vector<int> ans;
	while (!ar.empty()) {
		int i = max_element(all(ar)) - ar.begin();
		ans.push_back(a[ar[i].second]);
		int x = ar[i].first;
		ar.erase(ar.begin() + i);
		if (x == 0) {
			break;
		}
		for (auto& p : ar) {
			p.first &= ~x;
		}
	}
	for (auto p : ar) {
		ans.push_back(a[p.second]);
	}
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
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