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
	vector<int> a(n);
	generate(all(a), nxt);
	bool ok = false;
	function<void(int, int)> rec = [&](int i, int cur) {
		if (i == n) {
			ok |= cur == 0;
			return;
		}
		for (int s : {-1, 0, 1}) {
			rec(i + 1, cur + s * a[i]);
		}
	};
	for (int i = 0; i < n; ++i) {
		rec(i + 1, a[i]);
	}
	puts(ok ? "YES" : "NO");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}