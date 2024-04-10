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
	int n = nxt(), q = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	int cnt = accumulate(all(a), 0);
	while (q--) {
		int t = nxt();
		if (t == 1) {
			int i = nxt() - 1;
			cnt -= a[i];
			a[i] ^= 1;
			cnt += a[i];
		} else {
			puts(nxt() <= cnt ? "1" : "0");
		}
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}