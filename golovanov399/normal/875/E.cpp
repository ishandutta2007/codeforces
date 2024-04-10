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

struct SegTree {
	int n;
	vector<int> a;

	SegTree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.assign(n + n, 0);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = ar[i];
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = max(a[i + i], a[i + i + 1]);
		}
	}

	int _get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return max(_get(v + v, l1, m, l, r), _get(v + v + 1, m, r1, l, r));
	}

	int get(int l, itn r) {
		return _get(1, 0, n, l, r);
	}
};

int main() {
	int n = nxt();
	vector<int> a(n + 2);
	for (int i = 0; i < n + 2; ++i) {
		a[i] = nxt();
	}

	n += 2;

	vector<int> am(n);
	const int big = 1e9 + 10;
	for (itn i = 0; i < n; ++i) {
		am[i] = big - a[i];
	}

	SegTree mx(a), mn(am);

	int l = abs(a[0] - a[1]) - 1;
	int r = 1e9 + 10;
	while (r > l + 1) {
		int lst = n - 1;
		int m = (l + r) / 2;
		vector<char> dp(n, 0);
		dp[n - 1] = 1;
		for (int i = n - 2; i >= 0; --i) {
			// cerr << "[" << i << ", " << lst << "] -> " << mx.get(i, lst + 1) << ", " << -mn.get(i, lst + 1) << "\n";
			if (mx.get(i, lst + 1) <= a[i] + m && big - mn.get(i, lst + 1) >= a[i] - m) {
				dp[i] = 1;
				lst = i;
			}
		}
		// cerr << m << ":";
		// for (int i = 0; i < n; ++i) {
		// 	cerr << " " << (int)dp[i];
		// }
		// cerr << "\n";
		if (dp[0] || dp[1]) {
			r = m;
		} else {
			l = m;
		}
	}

	printf("%d\n", r);

	return 0;
}