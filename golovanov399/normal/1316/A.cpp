#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), m = nxt();
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		s += nxt();
	}
	cout << min<long long>(m, s) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}