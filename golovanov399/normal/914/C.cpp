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

const int mod = 1000000007;

const int N = 1111;
int dp[N][N];
int C[N][N];
int f[N];

int main() {
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= mod) {
				C[i][j] -= mod;
			}
		}
	}
	for (int i = 2; i < N; ++i) {
		f[i] = f[__builtin_popcount(i)] + 1;
	}

	string s;
	cin >> s;
	int k = nxt();

	int n = s.length();

	dp[n][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '0') {
			memcpy(dp[i], dp[i + 1], (n + 1) * sizeof(int));
		} else {
			memcpy(dp[i] + 1, dp[i + 1], n * sizeof(int));
			for (int j = 0; j < n - i; ++j) {
				dp[i][j] += C[n - i - 1][j];
				if (dp[i][j] >= mod) {
					dp[i][j] -= mod;
				}
			}
		}
	}

	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j <= n; ++j) {
	// 		cerr << dp[j][i] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";

	if (k == 0) {
		puts("1");
	} else {
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (f[i] == k - 1) {
				ans += dp[0][i];
			}
		}
		printf("%d\n", (int)((ans + mod - (k == 1)) % mod));
	}

	return 0;
}