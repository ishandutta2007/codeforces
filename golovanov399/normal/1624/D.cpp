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
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'a'] += 1;
	}
	int tot = 0;
	for (int x : cnt) {
		tot += x / 2;
	}

	auto can = [&](int len) {
		return tot >= 1ll * k * (len / 2) && n >= 1ll * k * len;
	};

	int l = 0, r = n + 1;
	while (r > l + 1) {
		int m = (l + r) / 2;
		(can(m) ? l : r) = m;
	}
	cout << l << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}