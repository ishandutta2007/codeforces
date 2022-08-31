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
	long long n;
	cin >> n;
	if (n % 2050) {
		cout << "-1\n";
		return;
	}
	n /= 2050;
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	cout << res << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}