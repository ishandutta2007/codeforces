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
	string s, t;
	cin >> s >> t;
	for (int par : {(s.length() + t.length()) % 2}) {
		int i = par;
		bool ok = true;
		for (char c : t) {
			while (i < (int)s.length() && s[i] != c) {
				i += 2;
			}
			if (i < (int)s.length()) {
				++i;
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
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