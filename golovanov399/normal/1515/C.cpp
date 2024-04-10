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
	int n = nxt(), m = nxt(), x = nxt();
	set<pair<int, int>> S;
	for (int i = 0; i < m; ++i) {
		S.insert({0, i});
	}
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		int y = nxt();
		auto [v, pos] = *S.begin();
		S.erase(S.begin());
		ans[i] = pos;
		S.insert({v + y, pos});
	}
	assert(abs(S.begin()->first - S.rbegin()->first) <= x);
	cout << "YES\n";
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}