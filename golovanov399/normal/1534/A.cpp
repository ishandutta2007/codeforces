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
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	bool failed[2] = {false, false};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.') {
				continue;
			} else if (a[i][j] == 'R') {
				failed[(i + j) % 2] = true;
			} else {
				failed[(i + j + 1) % 2] = true;
			}
		}
	}
	string first;
	for (itn i = 0; i < m; ++i) {
		first += (i % 2 ? 'R' : 'W');
	}
	string second = 'R' + first.substr(0, m - 1);
	swap(first, second);
	if (failed[0]) {
		swap(first, second);
	}
	if (!failed[0] || !failed[1]) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << (i % 2 ? first : second) << "\n";
		}
	} else {
		cout << "NO\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}