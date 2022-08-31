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

int main() {
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int x = 0, y = 0, ans = (a[0][0] == '*');
	while (true) {
		pair<int, int> opt = {100, 100};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i + j > x + y && i >= x && j >= y && a[i][j] == '*') {
					opt = min(opt, {i + j, i});
				}
			}
		}
		if (opt.first == 100) {
			break;
		}
		x = opt.second;
		y = opt.first - x;
		ans += 1;
	}
	cout << ans << "\n";

	return 0;
}