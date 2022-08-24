#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int x = nxt(), y = nxt(), z = nxt();
	puts(((x + y + z) % 9 == 0) && ((x + y + z) / 9 <= min({x, y, z})) ? "YES" : "NO");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}