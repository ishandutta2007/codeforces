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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() % 2;
	}
	vector<int> ones;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			ones.push_back(i);
		}
	}
	int ans = -1;
	for (int r : {0, 1}) {
		if ((int)ones.size() != (n + 1 - r) / 2) {
			continue;
		}
		long long cur = 0;
		for (int i = 0; i < (int)ones.size(); ++i) {
			cur += abs(r + 2 * i - ones[i]);
		}
		if (ans == -1 || ans > cur) {
			ans = cur;
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