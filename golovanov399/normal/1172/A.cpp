#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		b[i] = nxt();
	}

	vector<int> first(n, n * 10);
	for (int i = 0; i < n; ++i) {
		if (a[i])
			first[a[i] - 1] = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (b[i]) {
			first[b[i] - 1] = i + 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		first[i] += n - 1 - i;
	}
	int ans = *max_element(all(first)) + 1;
	int c = b.back();
	if (c > 0) {
		bool ok = true;
		for (itn i = 1; i <= c; ++i) {
			if (b[n - i] != c + 1 - i) {
				ok = false;
			}
		}
		if (ok) {
			if (c == n) {
				ans = 0;
			} else {
				if (*max_element(first.begin() + c, first.end()) < n - c) {
					ans = n - c;
				}
			}
		}
	}
	cout << ans << "\n";

	return 0;
}