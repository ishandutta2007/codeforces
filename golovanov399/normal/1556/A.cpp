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
	int x = nxt(), y = nxt();
	if (x % 2 != y % 2) {
		cout << "-1\n";
	} else if (!x && !y) {
		cout << "0\n";
	} else {
		cout << 1 + (x != y) << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}