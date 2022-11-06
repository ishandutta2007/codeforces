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
#define MAXK 2000
#define MAXV 2000

typedef long long lint;

using namespace std;

const int mod = 1000000007;
int dp[MAXK+1][MAXV+1];

int main(int argc, char ** argv) {
	int maxv, k;

	scanf("%d %d", &maxv, &k);

	for (int v = 1; v <= maxv; v++) dp[1][v] = 1;

	for (int n = 2; n <= k; n++) {
		for (int v2 = 1; v2 <= maxv; v2++) {
			dp[n][v2] = 0;
			for (int v = v2; v <= maxv; v += v2) {
				dp[n][v2] += dp[n-1][v];
				if (dp[n][v2] >= mod) dp[n][v2] -= mod;
			}
		}
	}

	int ret = 0;
	for (int v = 1; v <= maxv; v++) {
		ret += dp[k][v];
		if (ret >= mod) ret -= mod;
	}

	printf("%d\n", ret);

	return 0;
}