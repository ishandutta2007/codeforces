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
	vector<int> cands;
	long long ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			int x = nxt();
			if (i >= n && j >= n) {
				ans += x;
			} else if ((i >= n) != (j >= n) && (i % n == 0 || i % n == n - 1) && (j % n == 0 || j % n == n - 1)) {
				cands.push_back(x);
			}
		}
	}
	cout << ans + *min_element(all(cands)) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}