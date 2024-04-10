#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int a[3];
	generate(a, a + 3, nxt);
	sort(a, a + 3);
	puts(a[2] - 1 > a[0] + a[1] ? "No" : "Yes");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}