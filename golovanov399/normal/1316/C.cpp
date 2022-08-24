#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), m = nxt(), p = nxt();
	vector<int> a(n), b(m);
	generate(all(a), nxt);
	generate(all(b), nxt);
	int i = 0, j = 0;
	while (a[i] % p == 0) {
		++i;
	}
	while (b[j] % p == 0) {
		++j;
	}
	cout << i + j << "\n";
}

int main() {
	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}