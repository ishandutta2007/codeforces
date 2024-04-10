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
	int q = nxt();
	while (q--) {
		int u = nxt(), v = nxt();
		int last = 30;
		bool ok = (u <= v);
		for (int i = 29; i >= 0; --i) {
			if (!(v & (1 << i))) {
				continue;
			}
			last = min(last, i);
			while (last >= 0 && !(u & (1 << last))) {
				--last;
			}
			if (last < 0) {
				ok = false;
				break;
			}
			--last;
		}
		puts(ok ? "YES" : "NO");
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}