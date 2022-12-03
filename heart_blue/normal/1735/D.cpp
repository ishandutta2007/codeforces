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
const int N = 2e3 + 10;
map<LL, int> mc;
LL a[N];
LL b[3][3] =
{ 0,2,1,
  2,1,0,
  1,0,2,
};
LL check(LL x, LL y, int k)
{
	LL ret = 0;
	for (int i = 2 * (k - 1); i >= 0; i -= 2)
	{
		ret |= b[x >> i & 3][y >> i & 3] << i;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		LL x = 0;
		for (int j = 0; j < k; j++)
		{
			x <<= 2;
			int o;
			scanf("%d", &o);
			x |= o;
		}
		a[i] = x;
		mc[x] = 1;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int tot = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (mc.count(check(a[i], a[j], k)))
				tot++;
		}
		int o = tot / 2;
		ans += o * (o - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}