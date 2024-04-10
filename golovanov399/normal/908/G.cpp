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
const int N = /* azino */ 777;
const long long ninth = (mod + 1) / 9;

long long fact[N];
long long inv[N];
long long invfact[N];
long long is[10][N];
long long js[2][N];
long long ks[10][N];
long long dp[2][10][N];
long long tmp[N];
long long deg[N];

int main() {
	assert(ninth * 9 % mod == 1);

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		inv[i] = (i == 1) ? 1 : mod - mod / i * 1ll * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		invfact[i] = invfact[i - 1] * inv[i] % mod;
	}

	for (int d = 0; d < 10; ++d) {
		long long curd = 1;
		for (int i = 0; i < N; ++i) {
			is[d][i] = curd * invfact[i] % mod;
			curd = curd * d % mod;
		}

		curd = 1;
		for (int i = 0; i < N; ++i) {
			ks[d][i] = curd * invfact[i] % mod;
			curd = curd * 10 * (9 - d) % mod;
		}
	}
	for (int d = 0; d < 2; ++d) {
		long long curd = 1;
		for (int i = 0; i < N; ++i) {
			js[d][i] = curd * invfact[i] % mod;
			curd = curd * (1 + 9 * d) % mod;
		}
	}
	deg[0] = 1;
	for (int i = 1; i < N; ++i) {
		deg[i] = deg[i - 1] * 10 % mod;
	}

	for (int id = 0; id < 2; ++id) {
		for (int d = 0; d < 10; ++d) {
			memset(tmp, 0, sizeof(tmp));
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (i + j >= N) break;
					tmp[i + j] = (tmp[i + j] + is[d][i] * js[id][j]) % mod;
				}
			}
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (i + j >= N) {
						break;
					}
					dp[id][d][i + j] = (dp[id][d][i + j] + tmp[i] * ks[d][j]) % mod;
				}
			}
		}
	}

	string s;
	cin >> s;

	long long ans = 0;

	int n = s.length();
	vector<int> cnt(10);
	for (int i = 0; i < n; ++i) {
		int ss = n - 1 - i;
		for (int j = 0; '0' + j < s[i]; ++j) {
			cnt[j] += 1;

			int cur = 0;
			for (int d = 0; d <= 9; ++d) {
				int x = cur, y = cnt[d];
				int z = i + 1 - x - y;

				long long tmp = deg[y + z] * dp[1][d][ss] % mod;
				tmp -= deg[z] * dp[0][d][ss] % mod;
				if (tmp < 0) {
					tmp += mod;
				}

				ans += tmp * d * ninth % mod * fact[ss] % mod;

				cur += cnt[d];
			}

			cnt[j] -= 1;
		}
		cnt[s[i] - '0'] += 1;
	}

	ans %= mod;
	if (ans < 0) {
		ans += mod;
	}

	itn cur = 0;
	for (int i = 9; i >= 0; --i) {
		while (cnt[i]--) {
			ans += deg[cur++] * i % mod;
		}
	}
	ans %= mod;

	cout << ans << "\n";

	return 0;
}