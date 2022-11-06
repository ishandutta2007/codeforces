#include <iostream>
#include <cstdio>
#include <vector>

#define MAXN 24
#define INF 1000000010

using namespace std;

const int mod = 1000000007;

int dp[1<<MAXN], *sum = dp;

int main()
{
	int n, k, vals[2];

	scanf("%d", &n);

	vector <int> A(n), fact(n+1, 0);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);

	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++) {
			fact[i] = fact[i] + fact[i-1];
			if (fact[i] >= mod) fact[i] -= mod;
		}

	sum[0] = 0;
	for (int i = 0; i < n; i++) sum[1<<i] = A[i];
	for (int s = 1; s < (1<<n); s++) sum[s] = min(INF, sum[s&-s] + sum[s^(s&-s)]);

	scanf("%d", &k);
	for (int i = 0; i < k; i++) scanf("%d", &vals[i]);

	for (int s = 0; s < (1<<n); s++) {
		if (sum[s] == vals[0] || sum[s] == vals[1])
			dp[s] = fact[__builtin_popcount(s)];
		else {
			dp[s] = 0;
			for (int s2 = s; s2; s2 -= s2&-s2) {
				dp[s] = dp[s] + dp[s - (s2&-s2)];
				if (dp[s] >= mod) dp[s] -= mod;
			}
		}
	}

	int ret = fact[n] + (mod - dp[(1<<n)-1]);
	if (ret >= mod) ret -= mod;

	printf("%d\n", ret);

	return 0;
}