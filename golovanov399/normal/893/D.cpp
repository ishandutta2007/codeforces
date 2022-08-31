#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

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
	int n = nxt(), d = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int ans = 0;
	int cur = 0;
	int balance = 0;
	vector<int> lows(n), rigs(n);
	for (int i = 0; i < n; ++i) {
		balance += a[i];
		if (a[i] == 0) {
			lows[i] = -balance;
		}
		rigs[i] = d - balance;
	}
	for (int i = 1; i < n; ++i) {
		lows[i] = max(lows[i], lows[i - 1]);
	}
	for (int i = n - 2; i >= 0; --i) {
		rigs[i] = min(rigs[i], rigs[i + 1]);
	}

	for (int i = 0; i < n; ++i) {
		if (lows[i] > rigs[i]) {
			puts("-1");
			return 0;
		}
		if (cur < lows[i]) {
			cur = rigs[i];
			++ans;
		}
	}

	printf("%d\n", ans);

	return 0;
}