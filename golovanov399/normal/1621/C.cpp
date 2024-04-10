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

int ask(int i) {
	cout << "? " << i + 1 << endl;
	return nxt() - 1;
}

void solve() {
	int n = nxt();
	vector<int> p(n);
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		int x = ask(i);
		while (!used[x]) {
			used[x] = 1;
			int y = ask(i);
			p[x] = y;
			x = y;
		}
	}
	cout << "!";
	for (auto x : p) {
		cout << " " << x + 1;
	}
	cout << endl;
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}