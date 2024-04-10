#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 19
#define MAXPOW 524288

int N, M;
vector<int> adj[MAXN];
LL dp[MAXPOW][MAXN];

int bitcount(int n) {
	int ans = 0;
	while (n != 0) {
		n -= n & -n;
		ans++;
	}
	return ans;
}

int topbit(int n) {
	int bitpow = n & -n;
	int ret = 0;
	while (bitpow >>= 1) {
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("11D.in", "r", stdin);
	// freopen("11D.out", "w", stdout);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	LL ans = 0;
	for (int mask = 1; mask < 1<<N; mask++) {
		for (int bit = 0; bit < N; bit++) {
			if (mask & (1 << bit)) {
				if (bitcount(mask) == 1) {
					dp[mask][bit] = 1;
				}
				else {
					if ((1 << bit) == (mask & -mask)) continue;
					for (int i : adj[bit]) {
						if (mask & (1 << i)) {
							dp[mask][bit] += dp[mask ^ (1 << bit)][i];
						}
					}
				}
			}
			if (bitcount(mask) >= 3 && find(adj[bit].begin(), adj[bit].end(), topbit(mask)) != adj[bit].end()) {
				ans += dp[mask][bit];
				// fprintf(stderr, "%d %d %d\n", ans, mask, bit);
			}
			// fprintf(stderr, "dp[%d][%d] = %d\n", mask, bit, dp[mask][bit]);
		}
	}

	ans /= 2;

	cout << ans << endl;
	return 0;
}