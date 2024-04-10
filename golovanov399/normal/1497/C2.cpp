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
	int n = nxt(), k = nxt();
	for (int i = 0; i < k - 3; ++i) {
		cout << "1 ";
	}
	n -= k - 3;
	int b = __builtin_ctz(n);
	int m = (1 << b);
	if (m == n) {
		m /= 2;
	}
	cout << m << " " << (n - m) / 2 << " " << (n - m) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}