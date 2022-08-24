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
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	long long cur = 1;
	for (int i = 0; i < n; ++i) {
		cur = lcm(cur, i + 2);
		if (cur > 2e9) {
			cur = 2e9;
		}
		if (a[i] % cur == 0) {
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}