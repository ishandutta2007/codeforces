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
int dp[N][N][5][3];
char str[N][N];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%s", str[i] + 1);
	int m = strlen(str[1] + 1);
	int x = 1, y = 1;
	int d = 1;
	int c = 0;
	int cur = 0;
	memset(dp, -1, sizeof dp);
	while (1)
	{
		for (int p = 0; p <= 1; p++)
		{
			while (1)
			{
				int x2 = x + dx[(d + p * (2 * c - 1) + 4) % 4];
				int y2 = y + dy[(d + p * (2 * c - 1) + 4) % 4];
				if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && str[x2][y2] == str[x][y])
				{
					x = x2;
					y = y2;
				}
				else
					break;
			}
		}
		if (dp[x][y][d][c] != -1)
		{
			k -= cur;
			k %= cur - dp[x][y][d][c];
			cur = 0;
			memset(dp, -1, sizeof dp);
		}
		dp[x][y][d][c] = cur;
		if (cur == k)
		{
			printf("%c\n", str[x][y]);
			return 0;
		}
		int x2 = x + dx[d];
		int y2 = y + dy[d];
		if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && str[x2][y2] != '0')
		{
			x = x2;
			y = y2;
		}
		else
		{
			if (c)
				d = (d + 1) % 4;
			c ^= 1;
		}
		cur++;
	}

	return 0;
}