#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int bal = 0, minbal = 0;
		for (char c : s) {
			if (c == '(') {
				++bal;
			} else {
				--bal;
			}
			minbal = min(minbal, bal);
		}
		a[i] = {minbal, minbal - bal};
	}

	map<int, int> left, right;
	int cnt_zero = 0;
	for (auto p : a) {
		if (!p.first && !p.second) {
			cnt_zero += 1;
		} else if (!p.first) {
			left[p.second] += 1;
		} else if (!p.second) {
			right[p.first] += 1;
		}
	}

	int ans = cnt_zero / 2;
	for (auto p : left) {
		ans += min(p.second, right[p.first]);
	}
	cout << ans << "\n";

	return 0;
}