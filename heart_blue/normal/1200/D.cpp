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
int sum[N][N];
char str[N][N];
void add(int x1, int y1, int x2, int y2)
{
	x1 = max(x1, 1);
	y1 = max(y1, 1);
	x2 = max(x2, 1);
	y2 = max(y2, 1);
	for (int i = x1; i <= x2; i++)
	{
		sum[i][y1]++;
		sum[i][y2 + 1]--;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = n;
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (str[i][j] == 'B')
			{
				l = max(l, j - k + 1);
				r = min(r, j);
				cnt++;
			}
		}
		if (cnt == 0)
		{
			res++;
			continue;
		}
		if (l > r) continue;
		add(i - k + 1, l, i, r);
	}
	for (int j = 1; j <= n; j++)
	{
		int l = 1, r = n;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (str[i][j] == 'B')
			{
				l = max(l, i - k + 1);
				r = min(r, i);
				cnt++;
			}
		}
		if (cnt == 0)
		{
			res++;
			continue;
		}
		if (l > r) continue;
		add(l, j - k + 1, r, j);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum[i][j] += sum[i][j - 1];
			ans = max(ans, sum[i][j]);
		}
	}
	printf("%d\n", res + ans);
	return 0;
}