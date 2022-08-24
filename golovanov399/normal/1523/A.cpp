#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	string s;
	cin >> s;
	vector<int> d_left(n, 2e9);
	vector<int> d_right(n, 2e9);
	for (int i = 0; i < n; ++i) {
		if (i) {
			d_left[i] = d_left[i - 1] + 1;
		}
		if (s[i] == '1') {
			d_left[i] = 0;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (i < n - 1) {
			d_right[i] = d_right[i + 1] + 1;
		}
		if (s[i] == '1') {
			d_right[i] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			continue;
		}
		if (d_left[i] != d_right[i] && min(d_left[i], d_right[i]) <= m) {
			s[i] = '1';
		}
	}
	cout << s << "\n";
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