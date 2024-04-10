#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	vector<string> a(8);
	for (auto& s : a) {
		cin >> s;
	}
	for (auto s : a) {
		if (s == string(8, 'R')) {
			cout << "R\n";
			return;
		}
	}
	cout << "B\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}