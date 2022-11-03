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
const int N = 1e2 + 10;
int c[N][N];
int key[N][2];
int dp[N][N * N];
LL powmod(LL a, LL b, LL mod = INF)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
void init()
{
	for (int i = 0; i < N; i++) c[i][0] = c[i][i] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= INF)
				c[i][j] -= INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	LL m;
	scanf("%d%lld%d", &n, &m, &k);
	init();
	LL d = m / n;
	LL r = m % n;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		key[i][0] = powmod(c[n][i], d);
		key[i][1] = powmod(c[n][i], d + 1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i * n; j++)
		{
			for (int t = 0; t <= n; t++)
			{
				dp[i + 1][j + t] = (dp[i + 1][j + t] + 1LL * dp[i][j] * key[t][i + 1 <= r]) % INF;
			}
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}