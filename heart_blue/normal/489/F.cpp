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
const int N = 5e2 + 10;
int cnt[N];
char str[N];
int dp[2][N];
int n, m, mod;
inline int C2(int n)
{
	return 1LL * n * (n - 1) % (2 * mod) / 2;
}
inline void add(int& x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &mod);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < n; j++)
		{
			cnt[j] += str[j] - '0';
			if (cnt[j] > 2)
			{
				puts("0");
				return 0;
			}
		}
		if (count(str, str + n, '1') != 2)
		{
			puts("0");
			return 0;
		}
	}
	int x = count(cnt, cnt + n, 0);
	int y = count(cnt, cnt + n, 1);
	MEM(dp, 0);
	int o = 0;
	dp[o][x] = 1 % mod;
	int rest = x * 2 + y;
	for (int t = m; t < n; t++)
	{
		o ^= 1;
		MEM(dp[o], 0);
		for (int i = 0; i <= n; i++)
		{
			int j = rest - 2 * i;
			{
				if (i >= 2)
					add(dp[o][i - 2], 1LL * dp[o ^ 1][i] * C2(i) % mod);
				if (i >= 1 && j >= 1)
					add(dp[o][i - 1], 1LL * i * j * dp[o ^ 1][i] % mod);
				if (j >= 2)
					add(dp[o][i], 1LL * dp[o ^ 1][i] * C2(j) % mod);
			}
		}
		rest -= 2;
	}
	printf("%d\n", dp[o][0] % mod);
	return 0;
}