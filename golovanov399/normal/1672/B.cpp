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
	string s;
	cin >> s;
	int bal = 0;
	for (char c : s) {
		bal += (c == 'A') ? -1 : 1;
		if (c == 'B' && bal > 0) {
			cout << "No\n";
			return;
		}
	}
	if (s.back() != 'B') {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}