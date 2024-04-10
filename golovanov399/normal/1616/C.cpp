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
	generate(all(a), nxt);
	int ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cur = 0;
			for (int k = 0; k < n; ++k) {
				if ((a[k] - a[i]) * (j - i) == (a[j] - a[i]) * (k - i)) {
					++cur;
				}
			}
			ans = max(ans, cur);
		}
	}
	cout << n - ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}