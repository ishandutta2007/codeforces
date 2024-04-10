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
LL a[N][N];
int pre[N][N];
char str[N];
inline LL mul(LL x, LL y)
{
	if (x >= INF*INF / y) return INF*INF;
	else return x*y;
}
void init()
{
	int n = strlen(str + 1);
	MEM(a, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		LL cur = 0;
		for (int j = i; j <= n; j++)
		{
			cur = mul(cur, 10);
			cur += str[j] - '0';
			a[i][j] = cur;
			if (cur == 0) break;
		}
	}
}
LL dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int b;
	scanf("%d%s", &b, str + 1);
	init();
	int n = strlen(str + 1);
	MEM(dp, 0x3f);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j + 1][i] >= b) continue;
			for (int k = j; k >= 0; k--)
			{
				if (dp[i][k + 1] > mul(dp[j][k], b) + a[j + 1][i])
				{
					dp[i][k + 1] = mul(dp[j][k], b) + a[j + 1][i];
				}
			}
		}
	}
	LL ans = INF*INF;
	for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}