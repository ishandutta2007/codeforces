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
const int N = 1e7 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		LL l, r, x, y, z;
		cin >> n >> l >> r >> x >> y >> z >> a[1] >> a[2];
		LL mask = 1LL << 32;
		mask--;
		for (int i = 3; i <= n; i++)
		{
			a[i] = (a[i - 2] * x + a[i - 1] * y + z) & mask;
		}
		LL ans = 4 * INF * INF;
		LL minv1 = 4 * INF;
		LL minv2 = 4 * INF;
		for (int i = 1; i <= n; i++)
		{
			a[i] = a[i] % (r - l + 1) + l;
			if (minv1 != 4 * INF && minv1 < a[i])
			{
				ans = min(ans, a[i] * minv1);
			}
			if (minv2 != 4 * INF && minv2 < a[i])
			{
				ans = min(ans, a[i] * minv2);
			}
			if (a[i] < 0) minv1 = min(minv1, a[i]);
			else minv2 = min(minv2, a[i]);
		}
		LL maxv1 = -4 * INF;
		for (int i = n; i >= 1; i--)
		{
			if (maxv1 != 4 * INF && a[i] < maxv1)
			{
				ans = min(ans, a[i] * maxv1);
			}
			if (a[i] <= 0) maxv1 = max(maxv1, a[i]);
		}
		if (ans == 4 * INF * INF) puts("IMPOSSIBLE");
		else printf("%lld\n", ans);
	}
	return 0;
}