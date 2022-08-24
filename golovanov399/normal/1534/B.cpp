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
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int mx = max((i > 0 ? a[i - 1] : 0), (i < n - 1 ? a[i + 1] : 0));
		if (mx >= a[i]) {
			continue;
		}
		ans += a[i] - mx;
		a[i] = mx;
	}
	int last = 0;
	for (int x : a) {
		ans += abs(x - last);
		last = x;
	}
	ans += abs(last);
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}