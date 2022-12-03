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
const int N = 3e5 + 10;
int a[N];
int b[N];
LL solve(int n, int h)
{
	for (int i = 1; i <= n; i++)
		b[i] = h - a[i];
	LL l = 0, r = INF * INF;
	LL ans = INF * INF;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL cnt2 = mid / 2;
		LL cnt1 = mid - cnt2;
		for (int i = 1; i <= n; i++)
		{
			int o = min(b[i] / 2LL, cnt2);
			cnt2 -= o;
			cnt1 -= b[i] - 2 * o;
		}
		if (cnt1 >= 0) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int maxv = *max_element(a + 1, a + n + 1);
		printf("%lld\n", min(solve(n, maxv), solve(n, maxv + 1)));
	}
	return 0;
}