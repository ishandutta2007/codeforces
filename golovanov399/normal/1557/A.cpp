#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	long long s = accumulate(all(a), 0ll);
	long double ans = -3e9;
	long long p = 0;
	for (int i = 0; i < n - 1; ++i) {
		p += a[i];
		ans = max(ans, (long double)p / (i + 1) + (long double)(s - p) / (n - i - 1));
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << setprecision(10) << fixed;
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}