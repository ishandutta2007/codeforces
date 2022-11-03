#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e1 + 10;
int dp[2][N][N];
char s0[N * N];
char s1[N];
char s2[N];
int fail1[N], fail2[N];
int nex1[N][N], nex2[N][N];
void getfail(char s[N], int n, int fail[N])
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j && s[j + 1] != s[i]) j = fail[j];
		if (s[j + 1] == s[i]) j++;
		fail[i] = j;
	}
}
void build(char s[N], int n, int fail[N], int nex[N][N])
{
	getfail(s, n, fail);

	for (int i = 0; i < n; i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			if (c == s[i + 1]) nex[i][c - 'a'] = i + 1;
			else nex[i][c - 'a'] = nex[fail[i]][c - 'a'];
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s%s", s0 + 1, s1 + 1, s2 + 1);
	int n = strlen(s0 + 1);
	int sz1 = strlen(s1 + 1);
	int sz2 = strlen(s2 + 1);
	build(s1, sz1, fail1, nex1);
	build(s2, sz2, fail2, nex2);
	MEM(dp, 0xcf);
	dp[0][0][0] = 0;
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		o ^= 1;
		MEM(dp[o], 0xcf);
		for (int j = 0; j < sz1; j++)
		{
			for (int k = 0; k < sz2; k++)
			{
				for (char c = 'a'; c <= 'z'; c++)
				{
					if (c != s0[i] && s0[i] != '*') continue;
					int jj = nex1[j][c - 'a'];
					int kk = nex2[k][c - 'a'];
					int t = 0;
					if (jj == sz1) jj = fail1[jj], t++;
					if (kk == sz2) kk = fail2[kk], t--;
					dp[o][jj][kk] = max(dp[o][jj][kk], dp[o ^ 1][j][k] + t);
				}
			}
		}
	}
	int ans = -INF;
	for (int i = 0; i < sz1; i++)
	{
		for (int j = 0; j < sz2; j++)
		{
			ans = max(ans, dp[o][i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}