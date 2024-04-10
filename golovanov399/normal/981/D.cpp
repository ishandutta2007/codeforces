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

const int N = 55;
long long sum[N][N];

int main() {
	int n = nxt(), k = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			sum[i][j + 1] = sum[i][j] + a[j];
		}
	}

	auto check = [&](long long mask) {
		vector<char> ok(n + 1, 0);
		ok[0] = 1;
		for (int it = 0; it < k; ++it) {
			vector<char> tmp(n + 1, 0);
			for (int i = 0; i < n; ++i) {
				if (!ok[i]) {
					continue;
				}
				for (int j = i + 1; j <= n; ++j) {
					if ((sum[i][j] & mask) == mask) {
						tmp[j] = 1;
					}
				}
			}
			ok.swap(tmp);
		}
		return ok[n];
	};

	long long ans = 0;
	for (int i = 60; i >= 0; --i) {
		if (check(ans | (1ll << i))) {
			ans |= (1ll << i);
		}
	}

	cout << ans << "\n";

	return 0;
}