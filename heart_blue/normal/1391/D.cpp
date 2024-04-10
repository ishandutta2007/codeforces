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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int dp[N][8];
char a[N];
int cnt[10] = { 0,1,1,2,1,2,2,3 };
int b[10][10];
int c[10][10];
vector<int> v;
void init()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((cnt[i] + cnt[j]) & 1)
				b[i][j] = 1;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (b[i & 3][j & 3] && b[i >> 1][j >> 1])
				c[i][j] = 1;
		}
	}
}
void build(int n, int m)
{
	if (min(n, m) >= 4)
	{
		puts("-1");
		exit(0);
	}
	if (min(n, m) == 1)
	{
		puts("0");
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &a[i * m]);
	}
	for (int i = 0; i < n * m; i++)
		a[i] -= '0';
	if (n > m)
	{
		for (int i = 0; i < n; i++)
		{
			int o = 0;
			for (int j = 0; j < m; j++)
			{
				o |= a[i * m + j] << j;
			}
			v.push_back(o);
		}
	}
	else
	{
		v.resize(m, 0);
		for (int i = 0; i < n * m; i++)
		{
			v[i % m] |= a[i] << (i / m);
		}
	}
}
void solve(int key[10][10], int tot)
{
	for (int i = 0; i < tot; i++)
		dp[0][i] = cnt[i ^ v[0]];
	for (int i = 1; i < v.size(); i++)
	{
		MEM(dp[i], 0x3f);
		for (int j = 0; j < tot; j++)
		{
			for (int k = 0; k < tot; k++)
			{
				if (key[j][k] == 0) continue;
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + cnt[v[i] ^ k]);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < tot; i++)
		ans = min(ans, dp[v.size() - 1][i]);
	printf("%d\n", ans);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	build(n, m);
	if (min(n, m) == 2) solve(b, 4);
	else solve(c, 8);
	return 0;
}