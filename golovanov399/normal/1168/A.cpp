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

bool can(const vector<int>& a, int m, int c) {
	int min_last = 0;
	for (int x : a) {
		if (x + c < m) {
			if (x + c < min_last) {
				return false;
			} else {
				min_last = max(x, min_last);
			}
		} else {
			if ((x + c) % m < min_last) {
				min_last = max(x, min_last);
			} else {
				//
			}
		}
	}

	return true;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int l = -1, r = m;
	while (r > l + 1) {
		int mid = (l + r) / 2;
		if (can(a, m, mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << r << "\n";

	return 0;
}