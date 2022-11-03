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
const int N = 1e3 + 10;
char c[N][N];
int ans[N][N];
int flag[N][N];
int pre[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(ans, 0x3f);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	int cntx = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cntx += c[i][j] == '*';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == '.') cnt = 0;
			else cnt++;
			ans[i][j] = min(ans[i][j], cnt);
		}
		cnt = 0;
		for (int j = m; j > 0; j--)
		{
			if (c[i][j] == '.') cnt = 0;
			else cnt++;
			ans[i][j] = min(ans[i][j], cnt);
		}
	}
	int tot = 0;
	for (int j = 1; j <= m; j++)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (c[i][j] == '.') cnt = 0;
			else cnt++;
			ans[i][j] = min(ans[i][j], cnt);
		}
		cnt = 0;
		for (int i = n; i > 0; i--)
		{
			if (c[i][j] == '.') cnt = 0;
			else cnt++;
			ans[i][j] = min(ans[i][j], cnt);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			tot += ans[i][j] > 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		MEM(pre, 0);
		for (int j = 1; j <= m; j++)
		{
			if (ans[i][j] <= 1) continue;
			int len = ans[i][j];
			pre[j - len + 1]++;
			pre[j + len]--;
		}
		for (int j = 1; j <= m; j++) pre[j] += pre[j - 1];
		for (int j = 1; j <= m; j++) flag[i][j] += pre[j];
	}
	for (int j = 1; j <= m; j++)
	{
		MEM(pre, 0);
		for (int i = 1; i <= n; i++)
		{
			if (ans[i][j] <= 1) continue;
			int len = ans[i][j];
			pre[i - len + 1]++;
			pre[i + len]--;
		}
		for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
		for (int i = 1; i <= n; i++) flag[i][j] += pre[i];
	}
	int cnty = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cnty += flag[i][j] > 0;
		}
	}
	if (cntx != cnty)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (ans[i][j] <= 1) continue;
			printf("%d %d %d\n", i, j, ans[i][j] - 1);
		}
	}
	return 0;
}