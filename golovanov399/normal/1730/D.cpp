#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;
	reverse(all(t));
	set<string> S;
	for (int i = 0; i < n; ++i) {
		string tmp(1, s[i]);
		tmp += t[i];
		sort(all(tmp));
		if (S.contains(tmp)) {
			S.erase(tmp);
		} else {
			S.insert(tmp);
		}
	}
	if ((int)S.size() > 1) {
		cout << "NO\n";
	} else if (S.empty()) {
		cout << "YES\n";
	} else {
		auto st = *S.begin();
		cout << (st[0] == st[1] ? "YES" : "NO") << "\n";
	}
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