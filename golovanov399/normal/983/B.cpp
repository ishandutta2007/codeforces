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

const int N = 5055;
int ar[N][N];

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int l = 1; l <= n; ++l) {
		for (int i = 0; i + l <= n; ++i) {
			if (l == 1) {
				ar[i][i + l] = a[i];
			} else {
				ar[i][i + l] = ar[i][i + l - 1] ^ ar[i + 1][i + l];
			}
		}
	}
	for (int l = 2; l <= n; ++l) {
		for (int i = 0; i + l <= n; ++i) {
			ar[i][i + l] = max({ar[i][i + l], ar[i][i + l - 1], ar[i + 1][i + l]});
		}
	}

	int q = nxt();
	while (q--) {
		int l = nxt() - 1, r = nxt();
		printf("%d\n", ar[l][r]);
	}

	return 0;
}