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
int dp[N][26][26];
pair<int, int> pre[N][26][26];
char str[N][N];
int sum[26][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(dp, 0x3f);
	MEM(dp[0], 0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		MEM(sum, 0);
		for (int j = 1; j <= m; j++)
		{
			sum[str[i][j] - 'a'][j & 1]++;
		}
		for (int o1 = 0; o1 < 26; o1++)
		{
			for (int o2 = 0; o2 < 26; o2++)
			{
				if (o1 == o2) continue;
				for (int o3 = 0; o3 < 26; o3++)
				{
					if (o3 == o1) continue;
					for (int o4 = 0; o4 < 26; o4++)
					{
						if (o3 == o4) continue;
						if (o4 == o2) continue;
						int tmp = dp[i - 1][o1][o2] + m - sum[o3][1] - sum[o4][0];
						if (dp[i][o3][o4] > tmp)
						{
							dp[i][o3][o4] = tmp;
							pre[i][o3][o4] = make_pair(o1, o2);
						}
					}
				}
			}
		}
	}
	int o1 = 0, o2 = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (dp[n][o1][o2] > dp[n][i][j])
			{
				o1 = i, o2 = j;
			}
		}
	}
	printf("%d\n", dp[n][o1][o2]);
	for (int i = n; i >= 1; i--)
	{
		int a[] = { o2,o1 };
		for (int j = 1; j <= m; j++)
		{
			str[i][j] = (a[j & 1]) + 'a';
		}
		tie(o1, o2) = pre[i][o1][o2];
	}
	for (int i = 1; i <= n; i++)
		puts(str[i] + 1);
	return 0;
}