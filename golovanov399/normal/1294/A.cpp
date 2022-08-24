#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int a = nxt(), b = nxt(), c = nxt(), n = nxt();
	int s = (a + b + c + n);
	if (s % 3) {
		puts("NO");
	} else {
		puts(s / 3 >= max({a, b, c}) ? "YES" : "NO");
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}