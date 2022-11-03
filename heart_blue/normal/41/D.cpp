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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int dp[N][N][11];
int pre[N][N][11];
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	k++;
	MEM(dp, -1);
	MEM(pre, -1);
	scanf("%s", str[1] + 1);
	for (int i = 1; i <= m; i++) dp[1][i][(str[1][i] - '0') % k] = str[1][i] - '0';
	for (int oo = 2; oo <= n; oo++)
	{
		scanf("%s", str[oo] + 1);
		for (int i = 1; i <= m; i++)
		{
			for (int o = -1; o <= 1; o += 2)
			{
				int x = i + o;
				if (x < 1) continue;
				if (x > m) continue;
				for (int j = 0; j < k; j++)
				{
					if (dp[oo - 1][x][j] == -1) continue;
					int sum = dp[oo - 1][x][j] + str[oo][i] - '0';
					if (dp[oo][i][sum % k] < sum)
					{
						dp[oo][i][sum % k] = sum;
						pre[oo][i][sum % k] = o;
					}
				}
			}
		}
	}
	int key = 1;
	for (int i = 1; i <= m; i++)
	{
		if (dp[n][i][0] > dp[n][key][0]) key = i;
	}
	if (dp[n][key][0] == -1) puts("-1"), exit(0);
	printf("%d\n", dp[n][key][0]);
	printf("%d\n", key);
	int sum = dp[n][key][0];
	int o = 0;
	while (n > 1)
	{
		if (pre[n][key][o] == -1) putchar('L');
		else putchar('R');
		sum -= str[n][key] - '0';
		key += pre[n][key][o];
		o = sum % k;
		n--;
	}
	return 0;
}