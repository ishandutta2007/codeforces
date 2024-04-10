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
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	long long ans = 0;
	for (int i = 0; i < n; i += 2) {
		long long bal = 0, minbal = 0;
		for (int j = i + 1; j < n; ++j) {
			if (i % 2 != j % 2) {
				long long left = -minbal;
				long long right = bal - minbal;
				// cerr << i << " " << j << ": " << bal << " " << minbal << " " << left << " " << right << "\n";
				left = max(left, 1ll);
				right = max(right, 1ll);
				if (left <= a[i] && right <= a[j]) {
					ans += min(a[i] - left, a[j] - right) + 1;
				}
			}
			if (j % 2 == 0) {
				bal += a[j];
			} else {
				bal -= a[j];
			}
			minbal = min(minbal, bal);
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}