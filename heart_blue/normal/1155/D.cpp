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
const int N = 3e5 + 10;
LL rval[N];
LL sum[N];
int a[N];
map<LL, int> mc;
void add(LL x)
{
	mc[x]++;
}
void del(LL x)
{
	if (mc[x]-- == 1)
		mc.erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = a[i] + sum[i - 1];
	}
	LL ans = max({ 0LL,sum[n],sum[n] * x });
	for (int i = n; i >= 1; i--)
	{
		rval[i] = max(0LL, rval[i + 1] + a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		add(sum[i] * x + rval[i + 1]);
	}
	LL res = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, res + mc.rbegin()->first - sum[i - 1] * x);
		del(sum[i] * x + rval[i + 1]);
		res = max(0LL, res + a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}