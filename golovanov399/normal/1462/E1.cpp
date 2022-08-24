#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

long long C(int n, int m) {
	long long res = 1;
	for (int i = 0; i < m; ++i) {
		res = res * (n - i) / (i + 1);
	}
	return res;
}

void solve() {
	int n = nxt(), m = 3, k = 2;
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	long long ans = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && a[j] <= a[i] + k) {
			++j;
		}
		ans += C(j - i - 1, m - 1);
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