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

long long isqrt(long long n) {
	long long x = sqrtl(n);
	while (x * x > n) {
		--x;
	}
	while ((x + 1) * (x + 1) <= n) {
		++x;
	}
	return x;
}

long long f(long long n) {
	return isqrt(n) + (isqrt(4 * n + 1) + 1) / 2 + isqrt(n + 1);
}

void solve() {
	long long l, r;
	cin >> l >> r;
	cout << f(r) - f(l - 1) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}