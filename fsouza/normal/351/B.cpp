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

typedef long long lint;

using namespace std;

int p[MAXN];

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);
	
	int inv = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		for (int j = 0; j < i; j++)
			if (p[j] > p[i])
				inv ++;
	}

	int dp[2] = {0, 1};
	
	for (int i = 2; i <= inv; i++)
		dp[i&1] += 4;

	printf("%d.000000\n", dp[inv&1]);

	return 0;
}