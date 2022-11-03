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
int a[N];
int c[N];
int v[N];
int n, k, s, t;
LL check(int x)
{
	LL tot = 0;
	for (int i = 0; i <= k; i++)
	{
		int d = a[i + 1] - a[i];
		if (d > x) return INF*2;
		int len1 = min(d, x - d);
		int len2 = max(0, d - len1);
		tot += len1 + len2 * 2;
	}
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 1; i <= n; i++) scanf("%d%d", &c[i], &v[i]);
	for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
	a[0] = 0, a[k + 1] = s;
	sort(a, a + k + 1);
	int l = 1, r = INF;
	int res = r;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid) > t) l = mid + 1;
		else r = mid - 1, res = mid;
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		if (v[i] >= res)
		{
			ans = min(ans, c[i]);
		}
	}
	if (ans == INF) ans = -1;
	printf("%d\n", ans);
	return 0;
}