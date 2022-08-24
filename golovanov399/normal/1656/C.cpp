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
	sort(all(a));
	if (all_of(all(a), [](int x) { return x != 1; })) {
		cout << "YES\n";
		return;
	}
	if (any_of(all(a), [](int x) { return x == 0; })) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] - a[i] == 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}