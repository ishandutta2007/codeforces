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

const int N = 1111;
int C[N][N];

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

	int m = nxt(), n = nxt();
	vector<vector<char>> a(n, vector<char>(m, 0));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			a[i][j] = s[j] - '0';
		}
	}
	
	vector<long long> val(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) {
				val[j] |= 1ll << i;
			}
		}
	}

	auto tmp = val;
	make_unique(tmp);
	
	vector<long long> dp(m + 1);
	dp[0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += 1ll * C[i - 1][j] * dp[j] % mod;
		}
		dp[i] %= mod;
	}

	long long ans = 1;
	for (long long x : tmp) {
		int cnt = 0;
		for (long long y : val) {
			if (y == x) {
				++cnt;
			}
		}
		ans = ans * dp[cnt] % mod;
	}
	cout << ans << "\n";

	return 0;
}