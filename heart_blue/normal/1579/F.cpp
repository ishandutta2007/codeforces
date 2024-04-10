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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int ans[N];
int n;
int dfs(int x, int d)
{
	if (x < 0) x += n;
	if (ans[x] >= 0) return ans[x];
	if (a[x] == 0) return ans[x] = 0;
	ans[x] = INF;
	return ans[x] = dfs(x - d, d) + 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &n);
		int d;
		scanf("%d", &d);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		fill(ans, ans + n, -1);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			res = max(res, dfs(i, d));
		}
		if (res >= INF) res = -1;
		printf("%d\n", res);
	}
	return 0;
}