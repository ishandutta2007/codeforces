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
const int N = 2e5 + 10;
int a[N];
int solve(int n, int x, int y)
{
	int ret = 2 * INF;
	int minv = abs(x - a[1]);
	for (int i = 1; i <= n; i++)
	{
		int o;
		if (i < n) o = abs(y - a[i]) + abs(y - a[i + 1]) - abs(a[i + 1] - a[i]);
		else o = abs(y - a[i]);
		ret = min(ret, minv + o);
		minv = min(minv, abs(x - a[i]) + abs(x - a[i + 1]) - abs(a[i + 1] - a[i]));
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans = 2 * INF;
		ans = min(abs(1 - x) + min(abs(x - a[1]), abs(1 - a[1])),
			abs(1 - x) + min(abs(x - a[n]), abs(1 - a[n])));
		for (int i = 1; i < n; i++)
		{
			ans = min({ ans,
				abs(a[i] - 1) + x - 1 + abs(a[i + 1] - x) - abs(a[i + 1] - a[i]),
				abs(a[i] - x) + x - 1 + abs(a[i + 1] - 1) - abs(a[i + 1] - a[i]) });
		}
		ans = min({ ans,
			solve(n,1,x),
			solve(n,x,1) });
		LL res = ans;
		for (int i = 1; i < n; i++)
			res += abs(a[i] - a[i + 1]);
		printf("%lld\n", res);
	}

	return 0;
}