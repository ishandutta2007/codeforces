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

const int R = 5555;
const int N = 55;

long double dp[N][R];

int main() {
	int n = nxt(), r = nxt();
	vector<int> f(n), s(n);
	vector<long double> p(n);

	for (int i = 0; i < n; ++i) {
		f[i] = nxt(), s[i] = nxt();
		p[i] = nxt() * 0.01;
	}

	long double ll = 0, rr = 1e9;
	for (int it = 0; it < 100; ++it) {
		long double thr = (ll + rr) / 2;
		for (int i = 0; i <= r; ++i) {
			dp[n][i] = 0;
		}
		for (int i = r + 1; i <= r + 111; ++i) {
			dp[n][i] = thr;
		}
		for (int i = n - 1; i >= 0; --i) {
			for (int j = r + 1; j <= r + 111; ++j) {
				dp[i][j] = thr;
			}
			for (int j = r; j >= 0; --j) {
				long double tmp = p[i] * (f[i] + dp[i + 1][j + f[i]]) + (1 - p[i]) * (s[i] + dp[i + 1][j + s[i]]);
				dp[i][j] = min(tmp, thr);
			}
		}

		if (dp[0][0] < thr) {
			rr = thr;
		} else {
			ll = thr;
		}
	}

	cout << setprecision(10) << fixed;
	cout << (ll + rr) / 2 << "\n";

	return 0;
}