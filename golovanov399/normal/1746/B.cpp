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
	int z = count(all(a), 0);
	int ans = z;
	int c1 = 0;
	for (int i = 0; i < n && !a[i]; ++i) {
		--z;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			++c1;
			for (int j = i + 1; j < n && !a[j]; ++j) {
				--z;
			}
		}
		ans = min(ans, c1 + max(0, z - c1));
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