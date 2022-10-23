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
	int n = nxt(), k = nxt();
	vector<long long> p(n + 1);
	for (int i = n - k + 1; i <= n; ++i) {
		p[i] = nxt();
	}
	vector<long long> a(n);
	for (int i = n - k + 1; i < n; ++i) {
		a[i] = p[i + 1] - p[i];
		if (i > n - k + 1 && a[i] < a[i - 1]) {
			cout << "No\n";
			return;
		}
	}
	if (k == 1) {
		cout << "Yes\n";
		return;
	}
	for (int i = n - k; i >= 0; --i) {
		p[i] = p[i + 1] - a[n - k + 1];
	}
	cout << (p[0] <= 0 ? "Yes" : "No") << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}