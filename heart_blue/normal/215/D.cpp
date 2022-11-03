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
LL check(int t, int T, int x, int cost, int tot, int cnt)
{
	int p = T - t;
	if (1LL * cnt * p >= tot)
	{
		return 1LL*cnt * cost;
	}
	return 1LL*cnt * cost + (p + tot - cnt * p) * 1LL * x;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	LL ans = 0;
	while (n--)
	{
		int t, T, x, cost;
		scanf("%d%d%d%d", &t, &T, &x, &cost);
		if (t >= T)
		{
			ans += cost + 1LL * x * m;
			continue;
		}
		int o = max(1, m / (T - t));
		ans += min({ check(t,T,x,cost,m,1),check(t,T,x,cost,m,o),check(t,T,x,cost,m,o + 1) });
	}
	printf("%lld\n", ans);
	return 0;
}