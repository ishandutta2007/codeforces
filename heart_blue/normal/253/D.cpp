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
const int N = 4e2 + 10;
char str[N][N];
int sum[N][N];
int getsum(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == 'a') 
				sum[i][j]++;
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int ptr = 1;
			int cnt[200];
			MEM(cnt, 0);
			for (int t = 1; t <= m; t++)
			{
				ptr = max(ptr, t);
				while (ptr <= m && getsum(i, t, j, ptr) <= k)
				{
					if (str[i][ptr] == str[j][ptr])
						cnt[str[i][ptr]]++;
					ptr++;
				}
				if (str[i][t] == str[j][t] && cnt[str[i][t]] > 0)
				{
					ans += --cnt[str[i][t]];
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}