#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int ask(int pos) {
	cout << "? " << pos << endl;
	return nxt();
}

void solve() {
	int n = nxt();
	if (n == 1) {
		cout << "! " << 1 << "\n";
		return;
	}
	int l = 1, r = n;
	while (r > l + 1) {
		int m = (l + r) / 2;
		int mv1 = ask(m);
		int mv2 = ask(m + 1);
		if (mv1 < mv2) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	if (l == r) {
		cout << "! " << l << endl;
	} else {
		if (ask(l) < ask(r)) {
			cout << "! " << l << endl;
		} else {
			cout << "! " << r << endl;
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}