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
#define MAXS 110

typedef long long lint;

using namespace std;

int n1, n2, nv;
char s1[MAXS+1], s2[MAXS+1], v[MAXS+1];
int dp[MAXS+1][MAXS+1][MAXS+1], dpnewc[MAXS+1][MAXS+1][MAXS+1];
int failure[MAXS+1];

int solve(int a, int b, int c)
{
	int &ret = dp[a][b][c];
	if (ret != -1) return ret;

	if (c == nv) return ret = -INF;
	if (a == n1 || b == n2) return ret = 0;

	ret = 0;
	ret = max(ret, solve(a+1, b, c));
	ret = max(ret, solve(a, b+1, c));

	if (s1[a] == s2[b]) {
		int newc = c;
		char hsi = s1[a];

		while (newc > 0 && v[newc] != hsi)
			newc = failure[newc];

		if (v[newc] == hsi) {
			newc ++;
		}

		dpnewc[a][b][c] = newc;

		ret = max(ret, 1 + solve(a+1, b+1, newc));
	}

	return ret;
}

void print(int a, int b, int c)
{
	if (a == n1 || b == n2) {
		printf("\n");
		return;
	}

	if (dp[a][b][c] == dp[a+1][b][c])
		print(a+1, b, c);
	else if (dp[a][b][c] == dp[a][b+1][c])
		print(a, b+1, c);
	else {
		printf("%c", s1[a]);
		print(a+1, b+1, dpnewc[a][b][c]);
	}
}

int main(int argc, char ** argv)
{
	scanf(" %s %s %s", s1, s2, v);
	n1 = strlen(s1);
	n2 = strlen(s2);
	nv = strlen(v);
	
	memset(dp, -1, sizeof(dp));

	memset(failure, -1, sizeof(failure));
	for (int i = 0; i < nv; i++) {
		failure[i+1] = failure[i] + 1;
		while (failure[i+1] > 0 && v[failure[i+1]-1] != v[i])
			failure[i+1] = failure[failure[i+1]-1] + 1;
	}
	failure[0] = 0;

	int maxsize = solve(0, 0, 0);

	if (maxsize <= 0) {
		printf("0\n");
	} else {
		print(0, 0, 0);
	}

	return 0;
}