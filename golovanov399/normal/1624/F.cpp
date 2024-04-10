#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	int l = 1, r = n;
	int cur = 0;
	int added = 0;
	while (r > l + 1) {
		int m = (l + r) / 2;
		int cm = (m + added) % n;
		assert(cm);
		int rem = n - cm;
		cout << "+ " << rem << endl;
		added += rem;
		int lower = (l + added) / n;
		cur = nxt();
		(cur == lower ? r : l) = m;
	}
	cout << "! " << cur * n + (added + l) % n << endl;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}