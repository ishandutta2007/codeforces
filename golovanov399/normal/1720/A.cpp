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
	long long a = nxt(), b = nxt(), c = nxt(), d = nxt();
	if (a == 0 || c == 0) {
		cout << (a != c) << "\n";
		return;
	}
	cout << !!(a * d % (b * c)) + !!(b * c % (a * d)) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}