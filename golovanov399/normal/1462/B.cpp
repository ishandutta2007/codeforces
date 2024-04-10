#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	string s;
	cin >> s;
	if (n < 4) {
		cout << "NO\n";
		return;
	}
	const string ss = "2020";
	for (int i = 0; i <= 4; ++i) {
		if (s.substr(0, i) == ss.substr(0, i) && s.substr(n - 4 + i) == ss.substr(i)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}