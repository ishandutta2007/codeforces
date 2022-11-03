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
const LL inf = 4 * INF * INF;

LL multy(LL a, LL b)
{
	if (a == 0 || b == 0) return 0;
	if (a > inf / b) return inf;
	else return a * b;
}
LL add(LL a, LL b)
{
	if (a > inf - b) return inf;
	else return a + b;
}
LL powk(LL k)
{
	if (k < 0) return 0;
	if (k > 62) return inf;
	LL ret = 1;
	for (int i = 1; i <= k; i++)
	{
		ret = multy(ret, 4);
		ret = add(ret, 1);
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
		int n;
		LL k;
		scanf("%d%lld", &n, &k);

		LL cur = 1;
		LL x = 0;
		int ans = -1;
		while (n > 0)
		{
			if (k < cur)
			{
				break;
			}
			n--;
			k -= cur;
			x = add(x, multy(cur * 2 - 1, powk(n - 1)));
			cur = multy(2, cur) + 1;
			if (x >= k)
			{
				ans = n;
				break;
			}
		}
		if (ans >= 0)
		{
			printf("YES %d\n", ans);
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}