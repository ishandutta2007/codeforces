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
const int N = 1e5 + 10;
int deg[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		fill(deg, deg + n + 1, 0);
		vector<pair<int, int>> vp(m);
		for (auto& [x, y] : vp)
		{
			scanf("%d%d", &x, &y);
			deg[x]++;
			deg[y]++;
		}
		if (m % 2 == 0)
		{
			puts("0");
			continue;
		}
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] & 1)
				ans = min(ans, a[i]);
		}
		for (auto [x, y] : vp)
		{
			if (deg[x] % 2 == 0 && deg[y] % 2 == 0)
			{
				ans = min(ans, a[x] + a[y]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}