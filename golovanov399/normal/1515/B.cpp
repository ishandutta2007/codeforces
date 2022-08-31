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

bool is_sqr(int n) {
	int x = round(sqrt(n));
	return x * x == n;
}

void solve() {
	int n = nxt();
	if (is_sqr(n * 2) || (n % 4 == 0 && is_sqr(n))) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}