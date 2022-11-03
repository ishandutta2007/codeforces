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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e5 + 10;
int ans[N];
int a[N];
bool dfs(int l, int r, int lans, int rans)
{
	while (l <= r)
	{
		if (a[l] > r + 1) return false;
		if (a[l] == -1 || a[l] == r + 1)
		{
			ans[l] = rans--;
			l++;
			continue;
		}
		if (!dfs(l, a[l] - 1, lans, lans + a[l] - 1 - l))
			return false;
		lans += a[l] - l;
		l = a[l];
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (!dfs(1, n, 1, n))
		{
			puts("-1");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", ans[i], " \n"[i == n]);
		}
	}
	return 0;
}