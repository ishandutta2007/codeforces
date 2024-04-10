#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	vector<long long> sc(26), tc(26);
	sc[0] = tc[0] = 1;
	int q = nxt();
	while (q--) {
		int type = nxt();
		int cnt = nxt();
		string s;
		cin >> s;
		for (char c : s) {
			(type == 1 ? sc : tc)[c - 'a'] += cnt;
		}
		int j = (int)tc.size() - 1;
		while (tc[j] == 0) {
			--j;
		}
		if (j || (sc[0] < tc[0] && *max_element(1 + all(sc)) == 0)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
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