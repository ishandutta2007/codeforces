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

const int N = 1 << 22;
int ans[N];
int to[N];

int main() {
	int n = nxt(), m = nxt();
	vector<int> masks(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		masks[u] |= 1 << v;
		masks[v] |= 1 << u;
	}
	for (int i = 0; i < n; ++i) {
		masks[i] |= 1 << i;
	}

	for (int i = 0; i < (1 << n); ++i) {
		ans[i] = 1e9;
	}

	ans[(1 << n) - 1] = 0;
	for (int mask = (1 << n) - 2; mask > 0; --mask) {
		for (int i = 0; i < n; ++i) {
			if (!(mask & (1 << i))) {
				continue;
			}
			if (ans[mask | masks[i]] + 1 < ans[mask]) {
				ans[mask] = ans[mask | masks[i]] + 1;
				to[mask] = i;
			}
		}
	}

	int res = 1e9;
	int init_mask = 0;
	for (int mask = (1 << n) - 1; mask > 0; --mask) {
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) && (mask & masks[i]) != mask) {
				ok = false;
				break;
			}
		}
		if (ok) {
			if (ans[mask] < res) {
				res = ans[mask];
				init_mask = mask;
			}
		}
	}

	printf("%d\n", res);
	while (init_mask != (1 << n) - 1) {
		printf("%d ", to[init_mask] + 1);
		init_mask |= masks[to[init_mask]];
	}
	printf("\n");

	return 0;
}