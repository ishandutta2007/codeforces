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
	vector<string> a(n, string(m, '0'));
	auto can = [&](int x, int y) {
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				int nx = x + dx, ny = y + dy;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '1') {
					return false;
				}
			}
		}
		return true;
	};
	for (int i = 0; i < (n + m - 2) * 2; ++i) {
		int x = 0, y = 0;
		if (i < m - 1) {
			y = i;
		} else if (i < n + m - 2) {
			y = m - 1;
			x = i - (m - 1);
		} else if (i < n + m + m - 3) {
			x = n - 1;
			y = (m - 1) - (i - n - m + 2);
		} else {
			x = (n + n + m + m - 4 - i);
		}
		if (can(x, y)) {
			a[x][y] = '1';
		}
	}
	for (auto s : a) {
		cout << s << "\n";
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