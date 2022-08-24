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

	int n = nxt(), m = nxt();
	vector<int> cnt(n);
	int idx = -1;
	for (int i = 0; i < n; ++i) {
		int tmp = min(m, i / 2);
		cnt[i] += tmp;
		m -= tmp;
		if (m == 0) {
			idx = i;
			break;
		}
	}
	if (m) {
		cout << "-1\n";
		return 0;
	}

	if (cnt[idx] == 0) {
		for (int i = 0; i < n; ++i) {
			cout << n + 2 + i << " ";
		}
		cout << "\n";
		return 0;
	}

	for (int i = 0; i < idx; ++i) {
		cout << i + 1 << " ";
	}
	int r = idx;
	int l = r + 1 - 2 * cnt[idx];
	cout << l + r << " ";

	int d = 2 * (l + r + 10);
	for (int i = idx + 1; i < n; ++i) {
		cout << d * (n + 10 + i - idx) << " ";
	}
	cout << "\n";

	return 0;
}