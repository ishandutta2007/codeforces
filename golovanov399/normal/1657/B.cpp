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
	int n = nxt(), b = nxt(), x = nxt(), y = nxt();
	long long cur = 0, s = 0;
	for (int i = 1; i <= n; ++i) {
		cur += x;
		if (cur > b) {
			cur -= x + y;
		}
		s += cur;
	}
	cout << s << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}