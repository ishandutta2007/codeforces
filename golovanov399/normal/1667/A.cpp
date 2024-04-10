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
	long long ans = 1e18;
	for (int z = 0; z < n; ++z) {
		long long cur = 0;
		long long last = 0;
		for (int i = z + 1; i < n; ++i) {
			long long tmp = last / a[i] + 1;
			cur += tmp;
			last = tmp * a[i];
		}
		last = 0;
		for (int i = z - 1; i >= 0; --i) {
			long long tmp = last / a[i] + 1;
			cur += tmp;
			last = tmp * a[i];
		}
		ans = min(ans, cur);
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