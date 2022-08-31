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
	int n = nxt();
	string a[3];
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
	}
	string ans = "";
	int x[3] = {0, 0, 0};
	int cn[2] = {0, 0};
	for (int i = 0; i < 3 * n; ++i) {
		cn[0] = cn[1] = 0;
		for (int j = 0; j < 3; ++j) {
			if (x[j] < 2 * n) {
				cn[a[j][x[j]] - '0'] += 1;
			}
		}
		char c = '0' + (cn[0] > cn[1] ? 0 : 1);
		ans += c;
		for (int j = 0; j < 3; ++j) {
			if (x[j] < 2 * n && a[j][x[j]] == c) {
				++x[j];
			}
		}
		bool done = false;
		for (int j = 0; j < 3; ++j) {
			if (x[j] == 2 * n) {
				if (x[(j + 1) % 3] > x[(j + 2) % 3]) {
					ans += a[(j + 1) % 3].substr(x[(j + 1) % 3]);
				} else {
					ans += a[(j + 2) % 3].substr(x[(j + 2) % 3]);
				}
				done = true;
				break;
			}
		}
		if (done) {
			break;
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}