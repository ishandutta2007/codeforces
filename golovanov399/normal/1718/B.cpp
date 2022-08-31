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

vector<int> fib;

void solve() {
	int n = nxt();
	vector<int> c(n);
	generate(all(c), nxt);

	if (n == 1) {
		if (c[0] == 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}

	const int sz = fib.size();
	vector<long long> mask(n);
	vector<long long> mask_without_1(n);
	for (int i = 0; i < n; ++i) {
		int x = c[i];
		for (int j = sz - 1; j >= 0; --j) {
			if (x >= fib[j]) {
				x -= fib[j];
				mask[i] |= 1ll << j;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int x = c[i] - 1;
		for (int j = sz - 1; j >= 0; --j) {
			if (x >= fib[j]) {
				x -= fib[j];
				mask_without_1[i] |= 1ll << j;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (c[i] == 0) {
			continue;
		}
		long long m = 0;
		bool ok = !(mask_without_1[i] & 1ll);
		for (int j = 0; j < n; ++j) {
			long long x = (i == j ? mask_without_1 : mask)[j];
			if (m & x) {
				ok = false;
			}
			m |= x;
		}
		if (ok && (m & (m + 1)) == 0) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	fib = {1, 2};
	while ((int)fib.back() <= 1e9) {
		int x = fib.back() + fib.end()[-2];
		fib.push_back(x);
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}