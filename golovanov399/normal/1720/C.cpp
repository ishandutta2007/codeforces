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
	int cnt_ones = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt_ones += count(all(a[i]), '1');
	}
	int mn = 3;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			int cmx = 0;
			int s = 0;
			for (int x : {0, 1}) {
				for (int y : {0, 1}) {
					s += a[i + x][j + y] == '1';
					cmx = max<int>(cmx, a[i + x][j + y] == '1');
				}
			}
			mn = min(mn, s - cmx);
		}
	}
	if (mn == 0) {
		mn = 1;
	}
	cout << cnt_ones - mn + 1 << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}