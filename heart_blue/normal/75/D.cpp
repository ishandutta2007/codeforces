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
const int N = 2e5 + 10;
const int M = 60;
int lmax[M];
int rmax[M];
int sum[M];
int a[N];
int maxv[M];
LL ans = -INF;
void init(int id)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[id] += a[i];

	}
	int tot = 0;
	lmax[id] = a[1];
	rmax[id] = a[n];
	maxv[id] = a[1];
	for (int i = 1; i <= n; i++)
	{
		tot += a[i];
		lmax[id] = max(lmax[id], tot);
	}
	tot = 0;
	for (int i = n; i >= 1; i--)
	{
		tot += a[i];
		rmax[id] = max(rmax[id], tot);
	}
	int cur = 0;

	for (int i = 1; i <= n; i++)
	{
		cur = max(a[i], cur + a[i]);
		maxv[id] = max(maxv[id], cur);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		init(i);
	LL cur = 0;
	for (int i = 1; i <= m; i++)
	{
		int id;
		scanf("%d", &id);
		ans = max(ans, cur + lmax[id]);
		cur = max(1LL * rmax[id], cur + sum[id]);
		ans = max(ans, cur);
		ans = max(ans, 1LL * maxv[id]);
	}
	printf("%lld\n", ans);
	return 0;
}