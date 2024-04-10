#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXCNT = 7005;
const int MAXP = 15;
const int INF = (int) 1e9+5;

int n;
long long k;
long long a[MAXN];

int count_primes = 0;
pair<long long, int> primes[MAXP];
int divs[MAXN][MAXP];
int mul[MAXP];

int count_divs = 0;
pair<int, long long> dp[MAXN][MAXCNT];
int par[MAXN][MAXCNT];

inline void getDivisors() {
	for (int i = 2; 1ll * i * i <= k; i++) {
		if (k % i == 0) {
			primes[count_primes] = make_pair(i, 0);
			while (k % i == 0) {
				primes[count_primes].second++;
				k /= i;
			}
			count_primes++;
		}
	}
	if (k != 1)
		primes[count_primes++] = make_pair(k, 1);

	for (int i = 0; i < n; i++) {
	    long long x = a[i];
		for (int j = 0; j < count_primes; j++) {
			while (x % primes[j].first == 0) {
				x /= primes[j].first;
				divs[i][j]++;
			}
		}
	}

	count_divs = 1;
	for (int i = 0; i < count_primes; i++)
		count_divs *= primes[i].second + 1;

	mul[count_primes - 1] = 1;
	for (int i = count_primes - 2; i >= 0; i--)
		mul[i] = mul[i + 1] * (primes[i + 1].second + 1);
}

int main() {

	scanf("%d%I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);

	if (k == 1) {
	    pair<long long, int> best(1e18, 0);
		for (int i = 0; i < n; i++)
		    best = min(best, make_pair(a[i], i + 1));
		printf("1\n%d\n", best.second);
		exit(0);
	}

	getDivisors();
	
	for (int i = 0; i < count_divs; i++)
		dp[0][i] = make_pair(INF, 0);
	dp[0][0] = make_pair(0, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < count_divs; j++) {
			dp[i][j] = make_pair(INF, 0);

			int last = 0, cur = j;
			for (int q = 0; q < count_primes; q++) {
				last += mul[q] * max(0, cur / mul[q] - divs[i - 1][q]);
				cur %= mul[q];
			}

			if (dp[i - 1][last].first + 1 < dp[i][j].first) {
				dp[i][j] = make_pair(dp[i - 1][last].first + 1, dp[i - 1][last].second + a[i - 1]);
				par[i][j] = last;
			}
			if (dp[i - 1][last].first + 1 == dp[i][j].first && dp[i - 1][last].second + a[i - 1] < dp[i][j].second) {
			    dp[i][j].second = dp[i - 1][last].second + a[i - 1];
			    par[i][j] = last;
			}
			if (dp[i - 1][j] < dp[i][j]) {
				dp[i][j] = dp[i - 1][j];
				par[i][j] = j;
			}
		}
	}

	if (dp[n][count_divs - 1].first == INF) {
		printf("-1");
		exit(0);
	}

	printf("%d\n", dp[n][count_divs - 1].first);
	for (int i = n, j = count_divs - 1; j > 0; j = par[i--][j])
		if (par[i][j] < j) 
			printf("%d ", i);

	return 0;
}