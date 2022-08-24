#include <bits/stdc++.h>

using namespace std;

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

const int N = 2111;
long long dp[N][N];

const int mod = 1000000007;

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv(long long x) {
	return pw(x >= mod ? x - mod : x, mod - 2);
}

int main() {
	int k = nxt(), a = nxt(), b = nxt();
	long long p_a = inv(a + b) * a % mod;
	long long p_b = inv(a + b) * b % mod;

	dp[0][1] = 1;
	for (int i = 0; i < k; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * p_a) % mod;
			dp[i + j][j] = (dp[i + j][j] + dp[i][j] * p_b) % mod;
		}
	}

	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			if (i >= k) {
				// cerr << i << ", " << j << ": " << dp[i][j] << "\n";
				// cerr << "E = " << 1ll * dp[i][j] * i % mod << "\n";
				ans += 1ll * dp[i][j] * i % mod;
			} else if (j > k) {
				// cerr << i << ", " << j << ": " << dp[i][j] << "\n";
				// cerr << "E = " << (i + j - 1 + inv(p_b)) * dp[i][j] % mod << "\n";
				ans += (i + j - 1 + inv(p_b)) * dp[i][j] % mod;
			}
		}
	}

	cout << ans % mod << "\n";

	return 0;
}