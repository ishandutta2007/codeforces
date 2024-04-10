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

#define INF (INT_MAX/3)

#define MAXN 3000
#define MAXM 3000

typedef long long lint;

using namespace std;

const lint mod = (int)1e9 + 7;

int n, m;
char table[MAXN][MAXM+1];
lint dp[MAXN][MAXM];

lint solve(int y1, int x1, int y2, int x2)
{
	memset(dp, 0, sizeof(dp));
	dp[y2][x2] = (table[y2][x2] == '.');
	
	for (int y = y2; y >= y1; y--)
		for (int x = x2; x >= x1; x--) {
			if (y == y2 && x == x2) continue;
			dp[y][x] = 0;
			if (table[y][x] != '.') continue;
			if (y+1 <= y2) dp[y][x] += dp[y+1][x];
			if (x+1 <= x2) dp[y][x] += dp[y][x+1];
			if (dp[y][x] >= mod) dp[y][x] -= mod;
		}
	


	return dp[y1][x1];
}

int main(int argc, char ** argv)
{
	scanf("%d %d", &n, &m);
	
	for (int y = 0; y < n; y++)
		scanf(" %s", table[y]);

	lint ret = solve(0, 1, n-2, m-1) * solve(1, 0, n-1, m-2) % mod - solve(0, 1, n-1, m-2) * solve(1, 0, n-2, m-1) % mod;
	ret = (ret + mod) % mod;

	printf("%d\n", (int)ret);
	
	return 0;
}