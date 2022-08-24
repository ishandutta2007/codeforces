#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	int cntz = 0;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		if (x) {
			a.push_back(x);
		} else {
			cntz += 1;
		}
	}
	sort(all(a));
	if ((int)a.size() >= 6) {
		cout << "NO\n";
		return;
	}
	cntz = min(cntz, 3);
	while (cntz--) {
		a.push_back(0);
	}
	sort(all(a));
	n = a.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
				if (!binary_search(all(a), a[i] + a[j] + a[k])) {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}
	// for (int i = 1; i <= t; ++i) {
	// 	cout << "Case #" << i << ": ";
	// 	solve();
	// }

	return 0;
}