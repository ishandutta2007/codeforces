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
	int n = nxt();
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		M[abs(nxt())] += 1;
	}
	int ans = 0;
	for (auto [k, v] : M) {
		ans += min(v, 1 + !!k);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}