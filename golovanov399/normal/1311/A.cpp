#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline long long nxt() {
	long long x;
	cin >> x;
	return x;
}

void solve() {
	int a = nxt(), b = nxt();
	if (a == b) {
		cout << "0\n";
	} else if (a < b && (b - a) % 2 == 1) {
		cout << "1\n";
	} else if (a > b && (a - b) % 2 == 0) {
		cout << "1\n";
	} else {
		cout << "2\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}