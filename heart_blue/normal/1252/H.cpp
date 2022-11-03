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
const int N = 2e3 + 10;
char str[N][N];
int sum[N][N];
int cnt[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == str[i - 1][j]) sum[i][j] = sum[i - 1][j] + 1;
			else sum[i][j] = 1;
		}
	}
	LL ans = 0;
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (sum[i][j] * 3 > i) continue;
			int d = sum[i][j];
			if (sum[i - d][j] == d
				&& sum[i - 2 * d][j] >= d
				&& str[i][j] != str[i - d][j]
				&& str[i - d][j] != str[i - 2 * d][j])
			{
				cnt[i][j] = 1;
				if (cnt[i][j - 1]
					&& sum[i][j - 1] == d
					&& str[i][j] == str[i][j - 1]
					&& str[i - d][j] == str[i - d][j - 1]
					&& str[i - 2 * d][j] == str[i - 2 * d][j - 1])
				{
					cnt[i][j] += cnt[i][j - 1];
				}
			}
			ans += cnt[i][j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}