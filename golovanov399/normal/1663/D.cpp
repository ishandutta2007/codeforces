#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void sleep(double x) {
	clock_t start = clock();
	while (clock() < start + x * CLOCKS_PER_SEC);
}

void solve() {
	string s;
	cin >> s;
	if (s == "ABC") {
		cout << (nxt() < 2000 ? "YES" : "NO") << "\n";
	} else if (s == "ARC") {
		cout << (nxt() < 2800 ? "YES" : "NO") << "\n";
	} else if (s == "AGC") {
		cout << (nxt() >= 1200 ? "YES" : "NO") << "\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}