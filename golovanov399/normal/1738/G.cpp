#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt() - 1;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<string> ans(n, string(n, '0'));
	vector<int> cur_row(k);
	for (int i = 0; i < k; ++i) {
		cur_row[i] = n - k + i;
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k - i; ++j) {
			ans[n - 1 - i][j] = ans[i][n - 1 - j] = '1';
		}
	}
	for (int col = 0; col < n; ++col) {
		int row = 0;
		for (int i = 0; i < k; ++i) {
			if (col > i + n - k) {
				continue;
			}
			int mn = n;
			while (row <= cur_row[i]) {
				if (a[row][col] == '0') {
					mn = min(mn, row);
				}
				++row;
			}
			if (col == i + n - k) {
				mn = i;
			}
			ans[cur_row[i]][col] = '1';
			while (cur_row[i] > mn) {
				--cur_row[i];
				ans[cur_row[i]][col] = '1';
			}
		}
		while (row < n) {
			if (a[row][col] == '0') {
				cout << "No\n";
				return;
			}
			++row;
		}
	}
	cout << "Yes\n";
	for (auto s : ans) {
		cout << s << "\n";
	}
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