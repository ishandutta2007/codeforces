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

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	long long sum = accumulate(all(a), 0ll);
	long long cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += abs((i % 2 == 0 ? 1 : a[i]) - a[i]);
	}
	if (2 * cur <= sum) {
		for (int i = 0; i < n; ++i) {
			cout << (i % 2 == 0 ? 1 : a[i]) << " ";
		}
	} else {
		for (int i = 0; i < n; ++i) {
			cout << (i % 2 == 1 ? 1 : a[i]) << " ";
		}
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}