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
const int N = 2e6 + 10;
int flag[N];
int cnt[N];
int ans[N];
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
		memset(flag, 0, sizeof(int) * (n + 5));
		memset(cnt, 0, sizeof(int) * (n + 5));
		memset(ans, 0, sizeof(int) * (n + 5));
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			cnt[x]++;
		}
		int tot = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cnt[i] == 0) continue;
			tot++;
			int x = cnt[i];
			map<int, int> mc;
			for (int j = 1; j <= x; j++)
			{
				int key = (x + j - 1) / j;
				if (!mc.count(key))
					mc[key] = j;
				else
					mc[key] = min(mc[key], j);
				if (x % j == 0)
				{
					if (mc.count(key + 1))
						mc[key + 1] = min(mc[key + 1], j);
					else
						mc[key + 1] = j;
				}
			}
			for (auto& p : mc)
			{
				flag[p.first]++;
				ans[p.first] += p.second;
			}
		}
		int res = INF;
		for (int i = 1; i <= n + 1; i++)
		{
			if (flag[i] == tot)
				res = min(ans[i], res);
		}
		printf("%d\n", res);
	}
	return 0;
}