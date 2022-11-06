#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

const int maxn = 1000, maxk = 1000, mod = 1000000007;
int dp[maxn+1][maxk+1][2], fact[maxk+1];

void add(int &v, int x) {v += x; if (v >= mod) v -= mod;}

int main(int argc, char ** argv)
{
	fact[0] = 1;
	for (int i = 1; i <= maxk; i++) fact[i] = (lint)i * fact[i-1] % mod;

	for (int n = 0; n <= maxn; n++)
		for (int k = 0; k <= maxk; k++)
			for (int f = 1; f >= 0; f--) {
				dp[n][k][f] = 0;
				if (n == 0 && k == 0 && f == 1) add(dp[n][k][f], 1);
				else {
					if (f == 0) {
						add(dp[n][k][f], dp[n][k][1]);
						if (n >= k && k > 0) add(dp[n][k][f], dp[n - k][k][f]);
					} else {
						if (n-1 >= 0) add(dp[n][k][f], dp[n-1][k][1]);
						if (k-1 >= 0 && n >= k-1) add(dp[n][k][f], dp[n - (k-1)][k-1][0]);
					}
				}
			}
	
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int k, n;

		scanf("%d %d", &n, &k);

		printf("%d\n", (int)((lint)fact[k] * dp[n-k][k][0] % mod));
	}

	return 0;
}