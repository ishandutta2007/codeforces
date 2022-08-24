#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	string s;
	cin >> s;
	vector<long long> cnt(n);
	for (int i = 0; i < m; ++i) {
		cnt[nxt() - 1] += 1;
	}
	cnt[n - 1] += 1;
	for (int i = n - 1; i > 0; --i) {
		cnt[i - 1] += cnt[i];
	}
	vector<long long> ans(26);
	for (int i = 0; i < n; ++i) {
		ans[s[i] - 'a'] += cnt[i];
	}
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}