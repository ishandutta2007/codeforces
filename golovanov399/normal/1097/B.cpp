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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int mask = 0; mask < (1 << n); ++mask) {
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			if ((1 << j) & mask) {
				cur += a[j];
			} else {
				cur -= a[j];
			}
		}
		if (cur % 360 == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}