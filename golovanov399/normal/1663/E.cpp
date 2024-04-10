#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
	int n = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int d = 0; d < 8; ++d) {
				if (d != 1) {
					continue;
				}
				if (clamp(i + 6 * dx[d], 0, n - 1) != i + 6 * dx[d] || clamp(j + 6 * dy[d], 0, n - 1) != j + 6 * dy[d]) {
					continue;
				}
				string t = "";
				for (int it = 0; it < 7; ++it) {
					t += a[i + it * dx[d]][j + it * dy[d]];
				}
				if (t == "theseus") {
					cout << "YES\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}