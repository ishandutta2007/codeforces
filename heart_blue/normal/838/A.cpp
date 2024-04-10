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
const int N = 5e3 + 10;
int sum[N][N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++) sum[i][j] = str[j] - '0';
	}
	int maxv = max(n, m);
	for (int i = 1; i <= 2*maxv; i++)
	{
		for (int j = 1; j <= 2*maxv; j++)
		{
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	int ans = INF;
	for (int o = 2; o <= maxv; o++)
	{
		int x = (n + o - 1) / o * o;
		int y = (m + o - 1) / o * o;
		int cnt = 0;
		for (int i = o; i <= x; i += o)
		{
			for (int j = o; j <= y; j += o)
			{
				int tot = sum[i][j] - sum[i - o][j] - sum[i][j - o] + sum[i - o][j - o];
				cnt += min(tot, o * o - tot);
			}
		}
		ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}