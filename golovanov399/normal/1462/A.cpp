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
	int l = 0, r = n - 1;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			cout << a[l++] << " ";
		} else {
			cout << a[r--] << " ";
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