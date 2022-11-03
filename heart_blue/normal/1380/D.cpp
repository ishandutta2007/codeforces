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
const int N = 2e5 + 10;
int a[N];
int b[N];
int pos[N];
int getmax(int l, int r)
{
	int maxv = 0;
	for (int j = l; j <= r; j++)
	{
		maxv = max(maxv, a[j]);
	}
	return maxv;
}
LL solve(int l, int r, int limit, int k, LL x, LL y)
{
	if (l > r) return 0;
	int len = r - l + 1;
	int maxv = getmax(l, r);
	if (maxv < limit)
	{
		return min(len / k * x + len % k * y, len * y);
	}
	else if (len >= k)
	{
		len -= k;
		return x + min(len / k * x + len % k * y, len * y);
	}
	else
	{
		puts("-1");
		exit(0);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	LL x, y;
	scanf("%d%d", &n, &m);
	scanf("%lld%d%lld", &x, &k, &y);
	for (int i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);
		a[i] = val;
		pos[val] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
	}
	LL ans = 0;
	for (int i = 1; i < m; i++)
	{
		int l = pos[b[i]];
		int r = pos[b[i + 1]];
		if (l > r)
		{
			puts("-1");
			return 0;
		}
		l++, r--;
		ans += solve(l, r, max(b[i], b[i + 1]), k, x, y);
	}
	ans += solve(1, pos[b[1]] - 1, b[1], k, x, y);
	ans += solve(pos[b[m]] + 1, n, b[m], k, x, y);
	printf("%lld\n", ans);
	return 0;
}