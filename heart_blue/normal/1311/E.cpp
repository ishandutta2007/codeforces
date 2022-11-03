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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int minv[N];
int maxv[N];
int fa[N];
int a[N];
bool check(int x, int sz)
{
	return sz >= minv[x] && sz <= maxv[x];
}
void dfs(int n, int d, int& cur, int p = 0)
{
	int x = cur;
	fa[x] = p;
	if (n == 1)
	{
		return;
	}
	if (check(n - 1, d - (n - 1)))
	{
		dfs(n - 1, d - (n - 1), ++cur, x);
		return;
	}
	for (int i = 1; i + 1 < n; i++)
	{
		int minv1 = minv[i], maxv1 = maxv[i];
		int minv2 = minv[n - i - 1], maxv2 = maxv[n - i - 1];
		if (minv1 + minv2 + n - 1 <= d && d <= maxv1 + maxv2 + n - 1)
		{
			int rest = d - (n - 1);
			int sum1 = minv1;
			int sum2 = rest - sum1;
			int o = max(0, sum2 - maxv2);
			sum1 += o;
			sum2 -= o;
			dfs(i, sum1, ++cur, x);
			dfs(n - i - 1, sum2, ++cur, x);
			return;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 2; i < N; i++)
	{
		a[i] += a[i / 2] + 1;
		minv[i] += minv[i - 1] + a[i];
		maxv[i] = i * (i - 1) / 2;
	}
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, d;
		scanf("%d%d", &n, &d);
		if (!check(n, d))
		{
			puts("NO");
			continue;
		}
		puts("YES");
		int rt = 1;
		dfs(n, d, rt);
		for (int i = 2; i <= n; i++)
			printf("%d%c", fa[i], " \n"[i == n]);

	}
	return 0;
}