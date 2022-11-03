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
const int N = 5e2 + 10;
int dp[21][N][N];
int w[N][N][4];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);		
	MEM(dp, 0x3f);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			w[i][j][0] = w[i][j + 1][1] = x;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			w[i][j][2] = w[i + 1][j][3] = x;
		}
	}
	if (k & 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				printf("-1 ");
			}
			puts("");
		}
		return 0;
	}
	MEM(dp[0], 0);
	k /= 2;
	for (int t = 0; t < k; t++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int o = 0; o < 4; o++)
				{
					int tx = i + dx[o];
					int ty = j + dy[o];
					if (tx < 1 || tx > n) continue;
					if (ty < 1 || ty > m) continue;
					dp[t + 1][i][j] = min(dp[t + 1][i][j], dp[t][tx][ty] + w[i][j][o]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", dp[k][i][j] * 2);
		}
		puts("");
	}
	return 0;
}