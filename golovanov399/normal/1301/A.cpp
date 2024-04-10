#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < (int)a.size(); ++i) {
		if (a[i] == c[i] || b[i] == c[i]) {
			//
		} else {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}