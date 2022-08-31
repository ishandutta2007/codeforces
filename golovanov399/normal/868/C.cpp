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
	int n = nxt(), k = nxt();
	int K = 1 << k;
	vector<int> cnt(K);
	for (int i = 0; i < n; ++i) {
		int q = 0;
		for (int j = 0; j < k; ++j) {
			q = q * 2 + nxt();
		}
		cnt[q] += 1;
	}

	if (cnt[0]) {
		puts("YES");
		return 0;
	}

	for (int i = 1; i < K; ++i) {
		for (int j = 1; j < K; ++j) {
			if (!(i & j) && cnt[i] && cnt[j]) {
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");

	return 0;
}