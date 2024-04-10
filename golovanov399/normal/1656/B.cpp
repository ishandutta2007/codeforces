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
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n && a[j] - a[i] < k) {
			++j;
		}
		if (j < n && a[j] - a[i] == k) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}