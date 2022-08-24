#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool isPrime(long long n) {
	if (n <= 1) {
		return false;
	}
	for (long long x = 2; x * x <= n; ++x) {
		if (n % x == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if (a == b + 1 && isPrime(a + b)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}