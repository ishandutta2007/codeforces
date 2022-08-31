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
	int n = nxt(), k = nxt();
	if (2 * k - 1 > n) {
		cout << "-1\n";
	} else {
		vector<string> ans(n, string(n, '.'));
		for (int i = 0; i < k; ++i) {
			ans[2 * i][2 * i] = 'R';
		}
		for (auto s : ans) {
			cout << s << "\n";
		}
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}