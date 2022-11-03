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
const int N = 1e6 + 10;
int a[N];
LL solve(int n, LL key)
{
	if (key == 1) return 4 * INF * INF;
	LL res = 0;
	LL cur = 0;
	for (int i = 1; i <= n; i++)
	{
		res += abs(cur);
		cur += a[i];
		cur %= key;
		if (cur < 0) cur += key;
		if (cur > key - cur) cur = -(key - cur);
	}
	return res;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		tot += a[i];
	}
	LL ans = 4 * INF * INF;
	for (int o = 1; 1LL * o * o <= tot; o++)
	{
		if (tot % o) continue;
		ans = min(ans, solve(n, o));
		ans = min(ans, solve(n, tot / o));
	}
	if (ans == 4 * INF * INF)
		ans = -1;
	printf("%lld\n", ans);
	return 0;
}