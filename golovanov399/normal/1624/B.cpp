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
	int a = nxt(), b = nxt(), c = nxt();
	if (2 * b - c > 0 && (2 * b - c) % a == 0) {
		cout << "Yes\n";
	} else if (2 * b - a > 0 && (2 * b - a) % c == 0) {
		cout << "Yes\n";
	} else if ((a + c) % (2 * b) == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}