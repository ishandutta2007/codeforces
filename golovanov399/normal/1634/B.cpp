#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	long long x, y;
	cin >> x >> y;
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		tot ^= nxt() % 2;
	}
	puts((x + tot) % 2 == y % 2 ? "Alice" : "Bob");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}