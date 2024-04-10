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
int ans[N];
vector<pair<int, int>> vp[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	while (q--)
	{
		int i, j, x;
		scanf("%d%d%d", &i, &j, &x);
		if (i > j) swap(i, j);
		vp[i].emplace_back(j, x);
	}
	for (int o = 29; o >= 0; o--)
	{
		MEM(flag, 0);
		for (int i = 1; i <= n; i++)
		{
			for (auto& [j, x] : vp[i])
			{
				if (x >> o & 1) continue;
				flag[i] = flag[j] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			if (ans[i] >> o & 1) continue;
			for (auto& [j, x] : vp[i])
			{
				if (x >> o & 1)
				{
					if (flag[j] || i == j)
					{
						cnt++;
					}
				}
			}
			if (cnt > 0)
			{
				ans[i] |= 1 << o;
				continue;
			}
			for (auto& [j, x] : vp[i])
			{
				if (x >> o & 1)
				{
					ans[j] |= 1 << o;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}