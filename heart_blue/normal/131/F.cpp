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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
char str[N][N];
int sum[N][N];
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
int getsum(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	int limit = 0;
	scanf("%d%d%d", &n, &m, &limit);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int cnt = 0;
			for (int o = 0; o < 5; o++)
			{
				cnt += str[i + dx[o]][j + dy[o]] == '1';
			}
			if (cnt == 5) sum[i][j] = 1;
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	LL ans = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int ptr = 2;
			for (int k = 2; k < m; k++)
			{
				ptr = max(ptr, k);
				while (ptr < m && getsum(i, k, j, ptr) < limit)
				{
					ptr++;
				}
				ans += m - 1 - ptr + 1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}