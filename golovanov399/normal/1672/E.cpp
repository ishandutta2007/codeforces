#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

int last;
int ask(int w) {
	cout << "? " << w << endl;
	return last = nxt();
}

void solve() {
	int n = nxt();
	int l = 0, r = 2002 * n;
	while (r > l + 1) {
		int m = (l + r) / 2;
		(ask(m) == 1 ? r : l) = m;
	}
	int w = r;

	int cur = w;
	for (int i = 2; i <= n; ++i) {
		if (i - 1 < w - (cur - 1)) {
			continue;
		}
		int cand = cur - 1;
		cand = cand / i * i;
		while (cand > 0 && w - cand <= n - 1 && ask(cand / i) <= i) {
			if (last == 0) {
				break;
			}
			cur = cand / i * last;
			i = last;
			cand = cur - 1;
			cand = cand / i * i;
		}
	}
	cout << "! " << cur << endl;
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}